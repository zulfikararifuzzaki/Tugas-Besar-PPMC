#include "integrating.h"
#include "circLinkedList_randRear.h"

#ifndef FILEHANDLING_ABOUTUS_C
#define FILEHANDLING_ABOUTUS_C

int fileHandling(char* filename, node **rear){
    //Fungsi untuk memuat data dari file txt ke node dan menghitung jumlah kata
    //Input: nama file (string)
    //Output: jumlah kata

    char *word = (char*)malloc(sizeof(*word));
    char line[1024];
    char *newFilename = (char*)malloc(sizeof(*newFilename));
    int n;
    int i;
    FILE *fp;

    n = 0;
    fp = fopen(filename,"r");
    
    //Jika file tidak ditemukan
    while (!fp){
        puts("File Not Found!");
        puts("Masukkan nama file kembali! : ");
        scanf("%s", newFilename);
        fp = fopen(newFilename, "r");
    }
    
    free(newFilename);
    //Jika pembacaan belum mencapai EOF
    while(fgets(line, 1024, fp)){                           //Membaca 1024 karakter pada file

        line[strcspn(line, "\n")] = 0;                      //Menghilangkan \n
        word = strtok(line, " ");                           //Memisahkan kata dengan pembatas spasi

        //Menambahkan kata ke node
        while(word){
            //Kasus pembacaan karakter khusus
            for(i=0;i<(int)strlen(word);i++){
                //Hapus Tab
                if (word[i] == 9)
                    word[i] = 0;
                //Mengubah quotation mark (non ASCII)
                else if (word[i] == -30)
                    word[i] = 34;
                //Hilangkan sisa non ASCII characters
                else if (word[i] < 0)
                    word[i] = 1;
            }
            
            //Memasukkan kata ke circular linked list
            if ((int)strlen(word)>0){
                //printf("%s | ",word); //for test only
                AddNode(word, rear);
                n++;                                            //Menghitung jumlah kata
            }
            
            word = strtok(NULL, " ");
        }
    }
    free(word);
    fclose(fp);
    return n;
}

void aboutUs(){
    //Prosedur untuk menampilkan judul program dan credits
    puts("");
    puts("----------------------------------------------------------------------------");
    puts(" _____         _    ______                _                 _              ");
    puts("|_   _|       | |   | ___ \\              | |               (_)             ");
    puts("  | | _____  _| |_  | |_/ /__ _ _ __   __| | ___  _ __ ___  _ _______ _ __ ");
    puts("  | |/ _ \\ \\/ / __| |    // _` | '_ \\ / _` |/ _ \\| '_ ` _ \\| |_  / _ \\ '__|");
    puts("  | |  __/>  <| |_  | |\\ \\ (_| | | | | (_| | (_) | | | | | | |/ /  __/ |   ");
    puts("  \\_/\\___/_/\\_\\__|  \\_| \\_\\__,_|_| |_|\\__,_|\\___/|_| |_| |_|_/___\\___|_|   ");
    puts("----------------------------------------------------------------------------");
    puts("");
    puts("\t\t\t\tCreated by:\n");
    puts("\t\t Dhanurangga Al-Fadh             (13218005)");
    puts("\t\t Ivan Giovanni                   (13218006)");
    puts("\t\t Sarah Alyaa Tsaabitah           (13218011)");
    puts("\t\t Christian Dinata                (13218024)");
    puts("\t\t Zulfikar Nima Arifuzzaki        (13218029)");
    puts("");
    puts("\t\t\t   Press Enter To Continue");
    while(getchar() != '\n');
    loading();
    system("cls");
}

#endif
