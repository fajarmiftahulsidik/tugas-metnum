/* Metode Numerik
   Nama     : Ahmad Fajar Siddiq & Fajar Miftahul Siddiq
   NIM         : 3411151136 & 3411151122
   Kelas    : SIE-C

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#define nMax 100

int main(){
   /*kamus*/
   int x[nMax+1];
   int y[nMax+1];
   int x2[nMax+1];
   int y2[nMax+1];
   int xy[nMax+1];
   int n,i,elemen;
   int sigm_x=0,sigm_y=0,sigm_x2=0,sigm_y2=0,sigm_xy=0;
   float selisih[nMax+1];
   float m=0,c=0,error,sigm_prediksi=0,sigm_selisih=0;
   float prediksi[nMax+1];
   
   /*algoritma*/
   Home:
   printf("Perhitungan perkiraan lama waktu \n\n");
   printf("Masukan banyaknya n : ");scanf("%d", &n);
   /*jika n kurang dari 2 & lebih dari 100*/
   if(n<2){
      printf("mohon ma'af masukan salah'");
      getch();
      goto Home;
   }else if (n>100){
         printf("masukan teralu banyak");
         getch();
      goto Home;
   }
      
   else{
   for(i=1;i<=n;i++){
      printf("Jarak ke tempat pelanggan ke-%d = ",i);scanf("%d", &elemen);
      x[i]=elemen;
      sigm_x=sigm_x+x[i];
   }
   for(i=1;i<=n;i++){
      x2[i]=x[i]*x[i];
      sigm_x2=sigm_x2+x2[i];
   }
   printf("\n");
   for(i=1;i<=n;i++){
      printf("perkiraan waktu tempuh ke-%d = ",i);scanf("%d", &elemen);
      y[i]=elemen;
      sigm_y=sigm_y+y[i];
   }
   for(i=1;i<=n;i++){
      y2[i]=y[i]*y[i];
      sigm_y2=sigm_y2+y2[i];
      xy[i]=x[i]*y[i];
      sigm_xy=sigm_xy+xy[i];
   }
   m = ((n*sigm_xy)-(sigm_x*sigm_y))/((n*sigm_x2)-pow(sigm_x,2));
   c = ((sigm_y*sigm_x2)-(sigm_x*sigm_xy))/((n*sigm_x2)-pow(sigm_x,2));
   for(i=1;i<=n;i++){
      prediksi[i]=(m*x[i])+c;
   }
   printf("\nJarak \n");
   for(i=1;i<=n;i++){
         printf("|%dKM| ",x[i]);
  }
  printf("\n\nPerkiraan waktu tempuh\n");
   for(i=1;i<=n;i++){
         printf("|%djam| ",y[i]);
  }
  printf("\n\nPrediksi Waktu\n");
  for(i=1;i<=n;i++){
      printf("|%.2f|",prediksi[i]);
  }
  printf("\n\nSelisih waktu perkiraan\n");
  for(i=1;i<=n;i++){
      selisih[i]=y[i]-prediksi[i];
      if(selisih[i]<0){
         selisih[i]=prediksi[i]-y[i];
      }
      printf("|%.2f|",selisih[i]);
      sigm_selisih=sigm_selisih+selisih[i];
  }
  printf("\n\nError\n");
  printf("|%.2f|",sigm_selisih/n);
}

getch();
return 0;
}