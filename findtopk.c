#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define t 1000//dosyalarda 1000'er adet sayı var.

int main(int argc, char *argv[])
{
    clock_t start,end;
    double cpu_time_used;
    int *numarr;
    if(argc<5){
        fprintf(stderr,"Kullanım: findtopk <k> <N> <infile1> ...<infileN> <outfile>\n");
        return 1;
    }
    int i;
    int K=atoi(argv[1]);
    int N=atoi(argv[2]);
    char **infilenames=argv+3;
    char *outfilename=argv[argc-1];
    numarr=(int*)malloc(sizeof(int)*N);
    //main process işlemleri. Eğer output dosyası yoksa oluşturuyorum, varsa temizliyorum.
    if(getpid()>0){
        FILE *file_ptr;
        file_ptr=fopen(outfilename,"w");
        fclose(file_ptr);
    }
    for (i = 0; i < N; i++)
    {
        // child process oluştur
        int pid = fork();

        if (pid == 0)
        {
            // child process işlemleri
            FILE* fp;
            char *infilename=infilenames[i];
            fp = fopen(infilename, "r"); // dosyayı aç

            int numbers[t];
            int j;
            for (j = 0; j < t; j++)
            {
                fscanf(fp, "%d\n", &numbers[j]); // dosyadaki sayıları diziye oku
            }
            fclose(fp); // dosyayı kapat

            // K. en büyük sayıyı bul
            int k, temp;
            for (k = 0; k < t-1; k++)
            {
                for (j = 0; j < t-k-1; j++)
                {
                    if (numbers[j] > numbers[j+1])
                    {
                        temp = numbers[j];
                        numbers[j] = numbers[j+1];
                        numbers[j+1] = temp;
                    }
                }
            }
            char name[25];
            sprintf(name, "intermediate%d.txt", i+1); // Dosya adı oluşturuluyor
            FILE* fp1 = fopen(name, "w"); // Dosya açılıyor
            fprintf(fp1, "%d", numbers[t-K]); // Dosyaya yazılıyor
            fclose(fp1); // Dosya kapatılıyor
            printf("\n%d.dosyadaki en buyuk %d. sayi: %d",i+1,K, numbers[t-K]); // K. en büyük sayıyı yazdır

            exit(0); // child process'i sonlandır
        }
        char name[25];
        sprintf(name, "intermediate%d.txt", i+1);
        FILE* fp1 = fopen(name, "r"); //intermediate dosyalara K. en büyük sayılar okunup diziye atılıyor.
        int sayi;
        fscanf(fp1, "%d", &sayi);
        *(numarr+i)=sayi;
        fclose(fp1);
        if(remove(name)!=0){//intermediate dosya siliniyor.
            perror("Dosya Silinemedi!");
            return 1;
        }
    }
    int j,k;
    for(i=1;i<N;i++){
        for(j=1;j<N;j++){
            if(*(numarr+j)<=*(numarr+i)){//diziye aktarılan sayılar büyükten küçüğe sıralanıyor.
                k=*(numarr+i);
                *(numarr+i)=*(numarr+j);
                *(numarr+j)=k;
            }
        }
    }
    FILE *file_ptr;
    file_ptr=fopen(outfilename,"a+");
    for(i=0;i<N;i++){
        fprintf(file_ptr,"%d\n",*(numarr+i));//output dosyasına K.en büyük sayılar yazdırılıyor.
    }
    fclose(file_ptr);
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nRuntime: %f",cpu_time_used);//çalışma süresi
    return 0;
}
