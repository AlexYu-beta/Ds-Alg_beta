import java.io.File;

/**
 * Created by alex on 12/23/16.
 */
public class DirectoryTree {
    static void printDir(File file,int depth){
        for(int i=0;i<depth;i++){
            System.out.print("\t");
        }
        if(file.exists()){
            if(file.isFile()){
                System.out.println(file.getName());
            }else{
                File[] files=file.listFiles();
                try {
                    for (int i = 0; i < files.length; i++) {
                        printDir(files[i], depth + 1);
                    }
                }catch(NullPointerException e){

                }
            }
        }else return;
    }



    public static void main(String arg[]){
        File file=new File("/home/alex");
        printDir(file,0);
    }
}
