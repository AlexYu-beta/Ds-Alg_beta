#include <stack>
#include <cstring>
#include <iostream>
using namespace std;
static char ops[]="+-*/()";
static int priorityMap[][6]={{0,0,-1,-1,0,0},
                             {0,0,-1,-1,0,0},
                             {1,1,0,0,0,0},
                             {1,1,0,0,0,0},
                             {-1,-1,-1,-1,-1,-1},
                             {1,1,1,1,1,1}};

bool IsOperator(char ch){
    int i;
    for(i=0;i<sizeof(ops)/sizeof(char);i++){
        if(ch==ops[i])return true;
    }
    return false;
}

int findLoc(char c){
    int i,j=0;
    for(i=0;i<6;i++){
        if(ops[i]==c) j=i;
    }
    return j;
}

void translate(char* inFix, char* postFix)
{
    int j = 0, len;
    char c;
    stack<char> st;

    len = strlen(inFix);

    for (int i = 0; i < len; i++)
    {
        c = inFix[i];

        if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                postFix[j++] = st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (!IsOperator(c))
                st.push(c);
            else
            {
                while (st.empty() == false &&priorityMap[findLoc(st.top())][findLoc(c)] >= 0)
                {
                    postFix[j++] = st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
    }

    while (st.empty() == false)
    {
        postFix[j++] = st.top();
        st.pop();
    }
    postFix[j] = 0;
}


int main()
{
    char inFix[100];
    char postFix[100];
    cin >>inFix;
    translate(inFix, postFix);
    printf("%s", postFix);
    return 0;
}