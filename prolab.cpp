#include <graphics.h>
#include <stdio.h>

void harita1_buyukdaire(){
   setcolor(BLACK);
   circle(200,150,80);
   setfillstyle(SOLID_FILL,BLACK);
   floodfill(200,150,BLACK);
}
void harita1_kucukdaire(){
   setcolor(WHITE);
   circle(200,150,50);
   setfillstyle(SOLID_FILL,WHITE);
   floodfill(200,150,WHITE);
}
void harita1_arayollar(){
   setcolor(BLACK);
   rectangle(185,20,215,70);//dikey(üst) yol
   rectangle(185,225,215,280);//dikey(alt) yol
   rectangle(70,135,330,165);//yatay yol
   setfillstyle(SOLID_FILL,BLACK);
   floodfill(200,150,BLACK);//yatay yolu(orta) boyar
   floodfill(110,150,BLACK);//(sol)
   floodfill(320,150,BLACK);//(sağ)
   floodfill(200,50,BLACK);//dikey yolu boyar
   floodfill(200,250,BLACK);//dikey yolu boyar
}
void harita1_cizgiler(){
   int i;
   for(i=70;i<330;i=i+5){
    setcolor(WHITE);
    if(i>130 && i<150){
        continue;
    }
    if(i<265 && i>245){
        continue;
    }
    line(i,150,i+1,150);//yatay yolun çizgileri
   }
   for(i=20;i<80;i=i+5){
    setcolor(WHITE);
    line(200,i,200,i+1);//dikey üst yolun çizgileri
   }
   for(i=220;i<280;i=i+5){
    setcolor(WHITE);
    line(200,i,200,i+1);//dikey alt yolun çizgileri
   }
   for(i=0;i<360;i=i+8){
    arc(200,150,i+18,i+20,65);//daire çizgileri
   }
}
void harita1_saricizgi(){
   int i;
   for(i=70;i<330;i++){
    setcolor(BROWN);
    if(i>125 && i<146){
        continue;
    }
    if(i>252 && i<273){
        continue;
    }
    line(i,140,i+1,140);
    line(i,160,i+1,160);
   }
   setcolor(BROWN);
   line(190,20,190,76);
   line(210,20,210,76);
   line(190,224,190,280);
   line(210,224,210,280);

   arc(200,150,8,81,75);
   arc(200,150,99,172,75);
   arc(200,150,189,262,75);
   arc(200,150,279,351,75);
   arc(200,150,11,169,55);
   arc(200,150,191,349,55);
}
void harita1_yonler(){
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
setcolor(RED);
outtextxy(87,141,"t");
outtextxy(146,100,"a");
outtextxy(244,100,"b");
outtextxy(196,40,"x");
outtextxy(195,143,"e");
outtextxy(305,143,"y");
outtextxy(150,190,"c");
outtextxy(240,190,"d");
outtextxy(197,245,"z");
}
void harita1_hesapla(int saat_yonu[],int boyut,int e_caddesi_sag[],int boyut_e,int yonler[],int boyut_yon){
int arac_sayisi[9];
int bilinmeyen_sayisi=0;
int i,tmp=0;
char caddeler[9]={'t','x','y','z','a','b','c','d','e'};
printf("Lutfen caddelerden gecen arac sayisini giriniz,girmek istemiyorsaniz -1 girebilirsiniz:\n");
for(i=0;i<9;i++){
    printf("Lutfen %c caddesinden gecen arac sayisini giriniz:",caddeler[i]);
scanf("%d",&arac_sayisi[i]);
if(arac_sayisi[i]<-1){
    do{
    printf("%c caddesi icin hatali bir giris yaptiniz lutfen tekrar giris yapiniz:",caddeler[i]);
    scanf("%d",&tmp);
    arac_sayisi[i]=tmp;
    }while(tmp<-1);
}
}
for(i=0;i<9;i++){
    printf("%c caddesinden gecen arac sayisi:%d\n",caddeler[i],arac_sayisi[i]);
}
for(i=0;i<9;i++){
    if(arac_sayisi[i]==-1){
        bilinmeyen_sayisi++;
    }
}

float matris[5][6];
int j;
for(i=0;i<5;i++){
    for(j=0;j<6;j++){
        matris[i][j]=0;
        }
}

//girişler çıkışa eşit olacak
int toplam=0;
int sayac=0;
for(i=0;i<4;i++){
    if(arac_sayisi[i]!=-1 && yonler[i]==1){
        toplam+=arac_sayisi[i];
    }
    else if(arac_sayisi[i]!=-1 && yonler[i]==0){
        toplam-=arac_sayisi[i];
    }
    else if(arac_sayisi[i]==-1 && yonler[i]==1){
        matris[0][sayac]=1;
        sayac++;
    }
    else if(arac_sayisi[i]==-1 && yonler[i]==0){
        matris[0][sayac]=-1;
        sayac++;
    }
}
if(toplam<0){
    toplam=toplam*-1;
}
matris[0][5]=toplam;
//1. satır
}




void harita1_yonbelirleme(){
printf("Giris yonu icin 1'e cikis yonu icin 0'a basin:\n");
int yon_a,yon_b,yon_c,yon_d;
char baslangic_yon[4][2];
int yonler[4];
int saat_yonu[4];
int e_caddesi_sag[1];
do{
printf("t=");
scanf("%d",&yonler[0]);
printf("x=");
scanf("%d",&yonler[1]);
printf("y=");
scanf("%d",&yonler[2]);
printf("z=");
scanf("%d",&yonler[3]);
if(yonler[0]+yonler[1]+yonler[2]+yonler[3]!=2){
printf("2den fazla giris ya da cikis girdiniz lutfen tekrar deneyin:\n");
}
else{
    break;
}
}while(1);



printf("A caddesi icin baslangic noktasi giriniz:");
scanf("%s",&baslangic_yon[0][0]);
printf("A caddesi icin yon giriniz:");
scanf("%s",&baslangic_yon[0][1]);

printf("B caddesi icin baslangic noktasi giriniz:");
scanf("%s",&baslangic_yon[1][0]);
printf("B caddesi icin yon giriniz:");
scanf("%s",&baslangic_yon[1][1]);

printf("C caddesi icin baslangic noktasi giriniz:");
scanf("%s",&baslangic_yon[2][0]);
printf("C caddesi icin yon giriniz:");
scanf("%s",&baslangic_yon[2][1]);

printf("D caddesi icin baslangic noktasi giriniz:");
scanf("%s",&baslangic_yon[3][0]);
printf("D caddesi icin yon giriniz:");
scanf("%s",&baslangic_yon[3][1]);

printf("E caddesi icin baslangic noktasi giriniz:");
scanf("%s",&baslangic_yon[4][0]);
printf("E caddesi icin yon giriniz:");
scanf("%s",&baslangic_yon[4][1]);

cleardevice();
        closegraph();
        initwindow(900,600,"ProLab",250,100);
        floodfill(getmaxx()/2 ,getmaxy()/2,WHITE);
   harita1_buyukdaire();
   harita1_kucukdaire();
   harita1_arayollar();
   harita1_cizgiler();
   harita1_saricizgi();
   harita1_yonler();
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
outtextxy(500,150,"<---A caddesinin yonu");



if(baslangic_yon[0][0]=='t' && baslangic_yon[0][1]=='x' && yonler[0]==1 && yonler[1]==0){
    saat_yonu[0]=1;
    int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>85;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }
}

else if(baslangic_yon[0][0]=='t' && baslangic_yon[0][1]=='y' && yonler[0]==1 && yonler[2]==0){
    saat_yonu[0]=1;
    int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[0][0]=='t' && baslangic_yon[0][1]=='z' && yonler[0]==1 && yonler[3]==0){
    saat_yonu[0]=1;
    int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[0][0]=='x' && baslangic_yon[0][1]=='t' && yonler[1]==1 && yonler[0]==0){
    saat_yonu[0]=0;
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
    for(i=90;i<180;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>70;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[0][0]=='x' && baslangic_yon[0][1]=='z' && yonler[1]==1 && yonler[3]==0){
    saat_yonu[0]=0;
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
    for(i=90;i<270;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }

}

else if(baslangic_yon[0][0]=='x' && baslangic_yon[0][1]=='y' && yonler[1]==1 && yonler[2]==0){
    saat_yonu[0]=0;
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
    for(i=90;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }


}

else if(baslangic_yon[0][0]=='y' && baslangic_yon[0][1]=='t' && yonler[2]==1 && yonler[0]==0){
    saat_yonu[0]=0;
    int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=0;i<180;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>65;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[0][0]=='y' && baslangic_yon[0][1]=='x' && yonler[2]==1 && yonler[1]==0){
    saat_yonu[0]=1;
    int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=360;i>90;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }

}

else if(baslangic_yon[0][0]=='y' && baslangic_yon[0][1]=='z' && yonler[2]==1 && yonler[3]==0){
        saat_yonu[0]=0;
        int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
     for(i=0;i<270;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }

}

else if(baslangic_yon[0][0]=='z' && baslangic_yon[0][1]=='t' && yonler[3]==1 && yonler[0]==0){
    saat_yonu[0]=0;
    int i;
    for(i=270;i>220;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<180;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>65;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }

}

else if(baslangic_yon[0][0]=='z' && baslangic_yon[0][1]=='x' && yonler[3]==1 && yonler[1]==0){
    saat_yonu[0]=1;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=265;i>90;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }
}

else if(baslangic_yon[0][0]=='z' && baslangic_yon[0][1]=='y' && yonler[3]==1 && yonler[2]==0){
    saat_yonu[0]=1;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=265;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }

}
//a caddesi

cleardevice();
        closegraph();
        initwindow(900,600,"ProLab",250,100);
        floodfill(getmaxx()/2 ,getmaxy()/2,WHITE);
   harita1_buyukdaire();
   harita1_kucukdaire();
   harita1_arayollar();
   harita1_cizgiler();
   harita1_saricizgi();
   harita1_yonler();
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
outtextxy(500,150,"<---B caddesinin yonu");


if(baslangic_yon[1][0]=='t' && baslangic_yon[1][1]=='x' && yonler[0]==1 && yonler[1]==0){
    saat_yonu[1]=0;
    int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }

}

else if(baslangic_yon[1][0]=='t' && baslangic_yon[1][1]=='y' && yonler[0]==1 && yonler[2]==0){
   saat_yonu[1]=1;
   int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='t' && baslangic_yon[1][1]=='z' && yonler[0]==1 && yonler[3]==0){
    saat_yonu[1]=1;
    int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='x' && baslangic_yon[1][1]=='t' && yonler[1]==1 && yonler[0]==0){
saat_yonu[1]=1;
int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>180;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>65;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }

}

else if(baslangic_yon[1][0]=='x' && baslangic_yon[1][1]=='y' && yonler[1]==1 && yonler[2]==0){
   saat_yonu[1]=1;
   int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
 for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='x' && baslangic_yon[1][1]=='z' && yonler[1]==1 && yonler[3]==0){
    saat_yonu[1]=1;
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='y' && baslangic_yon[1][1]=='t' && yonler[2]==1 && yonler[0]==0){
    saat_yonu[1]=0;
    int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=0;i<180;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>65;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='y' && baslangic_yon[1][1]=='x' && yonler[2]==1 && yonler[1]==0){
    saat_yonu[1]=0;
    int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }


}

else if(baslangic_yon[1][0]=='y' && baslangic_yon[1][1]=='z' && yonler[2]==1 && yonler[3]==0){
    saat_yonu[1]=0;
    int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=0;i<270;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='z' && baslangic_yon[1][1]=='t' && yonler[3]==1 && yonler[0]==0){
    saat_yonu[1]=0;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<180;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>65;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='z' && baslangic_yon[1][1]=='y' && yonler[3]==1 && yonler[2]==0){
    saat_yonu[1]=1;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=265;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
     for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='z' && baslangic_yon[1][1]=='x' && yonler[3]==1 && yonler[1]==0){
    saat_yonu[1]=0;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=265;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }
}
//b caddesi

cleardevice();
        closegraph();
        initwindow(900,600,"ProLab",250,100);
        floodfill(getmaxx()/2 ,getmaxy()/2,WHITE);
   harita1_buyukdaire();
   harita1_kucukdaire();
   harita1_arayollar();
   harita1_cizgiler();
   harita1_saricizgi();
   harita1_yonler();
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
outtextxy(500,150,"<---C caddesinin yonu");


if(baslangic_yon[2][0]=='t' && baslangic_yon[2][1]=='x' && yonler[0]==1 && yonler[1]==0){
    saat_yonu[2]=0;
    int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }
}

else if(baslangic_yon[2][0]=='t' && baslangic_yon[2][1]=='y' && yonler[0]==1 && yonler[2]==0){
    saat_yonu[2]=0;
    int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='t' && baslangic_yon[2][1]=='z' && yonler[0]==1 && yonler[3]==0){
     saat_yonu[2]=0;
     int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<270;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='x' && baslangic_yon[2][1]=='t' && yonler[1]==1 && yonler[0]==0){//de
    saat_yonu[2]=1;
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>180;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>65;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='x' && baslangic_yon[2][1]=='y' && yonler[1]==1 && yonler[2]==0){
    saat_yonu[2]=0;
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
for(i=85;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='x' && baslangic_yon[2][1]=='z' && yonler[1]==1 && yonler[3]==0){
    saat_yonu[2]=0;
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
for(i=85;i<270;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='y' && baslangic_yon[2][1]=='t' && yonler[2]==1 && yonler[0]==0){
    saat_yonu[2]=1;
    int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=360;i>180;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>65;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='y' && baslangic_yon[2][1]=='x' && yonler[2]==1 && yonler[1]==0){
    saat_yonu[2]=1;
    int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=355;i>90;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }
}

else if(baslangic_yon[2][0]=='y' && baslangic_yon[2][1]=='z' && yonler[2]==1 && yonler[3]==0){
    saat_yonu[2]=0;
    int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=0;i<270;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='z' && baslangic_yon[2][1]=='t' && yonler[3]==1 && yonler[0]==0){//de
    saat_yonu[2]=1;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=265;i>180;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>65;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='z' && baslangic_yon[2][1]=='x' && yonler[3]==1 && yonler[1]==0){
    saat_yonu[2]=1;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=265;i>90;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }
}

else if(baslangic_yon[2][0]=='z' && baslangic_yon[2][1]=='y' && yonler[3]==1 && yonler[2]==0){
    saat_yonu[2]=1;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=265;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
     for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}
//c caddesi


cleardevice();
        closegraph();
        initwindow(900,600,"ProLab",250,100);
        floodfill(getmaxx()/2 ,getmaxy()/2,WHITE);
   harita1_buyukdaire();
   harita1_kucukdaire();
   harita1_arayollar();
   harita1_cizgiler();
   harita1_saricizgi();
   harita1_yonler();
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
outtextxy(500,150,"<---D caddesinin yonu");


if(baslangic_yon[3][0]=='t' && baslangic_yon[3][1]=='x' && yonler[0]==1 && yonler[1]==0){//de
saat_yonu[3]=0;
int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }
}

else if(baslangic_yon[3][0]=='t' && baslangic_yon[3][1]=='y' && yonler[0]==1 && yonler[2]==0){
    saat_yonu[3]=0;
    int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='t' && baslangic_yon[3][1]=='z' && yonler[0]==1 && yonler[3]==0){
    saat_yonu[3]=1;
    int i;
    for(i=70;i<120;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='x' && baslangic_yon[3][1]=='t' && yonler[1]==1 && yonler[0]==0){//de
    saat_yonu[3]=1;
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>180;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>65;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='x' && baslangic_yon[3][1]=='y' && yonler[1]==1 && yonler[2]==0){
    saat_yonu[3]=0;
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
for(i=85;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='x' && baslangic_yon[3][1]=='z' && yonler[1]==1 && yonler[3]==0){
   saat_yonu[3]=1;
   int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
     for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='y' && baslangic_yon[3][1]=='t' && yonler[2]==1 && yonler[0]==0){//de
    saat_yonu[3]=1;
    int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=360;i>180;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>65;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='y' && baslangic_yon[3][1]=='x' && yonler[2]==1 && yonler[1]==0){
    saat_yonu[3]=1;
    int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=360;i>90;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }
}

else if(baslangic_yon[3][0]=='y' && baslangic_yon[3][1]=='z' && yonler[2]==1 && yonler[3]==0){
    saat_yonu[3]=1;
    int i;
    for(i=315;i>265;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='z' && baslangic_yon[3][1]=='t' && yonler[3]==1 && yonler[0]==0){
    saat_yonu[3]=0;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<180;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=120;i>65;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='z' && baslangic_yon[3][1]=='x' && yonler[3]==1 && yonler[1]==0){
    saat_yonu[3]=0;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }
}

else if(baslangic_yon[3][0]=='z' && baslangic_yon[3][1]=='y' && yonler[3]==1 && yonler[2]==0){
    saat_yonu[3]=0;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=275;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}
//d caddesi

cleardevice();
        closegraph();
        initwindow(900,600,"ProLab",250,100);
        floodfill(getmaxx()/2 ,getmaxy()/2,WHITE);
   harita1_buyukdaire();
   harita1_kucukdaire();
   harita1_arayollar();
   harita1_cizgiler();
   harita1_saricizgi();
   harita1_yonler();
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
outtextxy(500,150,"<---E caddesinin yonu");



if(baslangic_yon[4][0]=='t' && baslangic_yon[4][1]=='x' && yonler[0]==1 && yonler[1]==0){
    e_caddesi_sag[0]=1;
    int i;
    for(i=70;i<255;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }
}

else if(baslangic_yon[4][0]=='t' && baslangic_yon[4][1]=='y' && yonler[0]==1 && yonler[2]==0){
    e_caddesi_sag[0]=1;
    int i;
    for(i=70;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[4][0]=='t' && baslangic_yon[4][1]=='z' && yonler[0]==1 && yonler[3]==0){
  e_caddesi_sag[0]=1;
  int i;
    for(i=70;i<255;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
     for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[4][0]=='x' && baslangic_yon[4][1]=='t' && yonler[1]==1 && yonler[0]==0){
   e_caddesi_sag[0]=0;
   int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
for(i=90;i>0;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
 for(i=255;i>70;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }//burda kaldık

}

else if(baslangic_yon[4][0]=='x' && baslangic_yon[4][1]=='y' && yonler[1]==1 && yonler[2]==0){
  e_caddesi_sag[0]=1;
  int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
for(i=90;i<180;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=140;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[4][0]=='x' && baslangic_yon[4][1]=='z' && yonler[1]==1 && yonler[3]==0){
    e_caddesi_sag[0]=1;
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(195,i+5,200,i+10);
    line(200,i+5,200,i+10);
    line(205,i+5,200,i+10);
    delay(200);
}
for(i=90;i<180;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=145;i<255;i=i+5){
    setcolor(YELLOW);
    line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
    delay(200);
}
for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[4][0]=='y' && baslangic_yon[4][1]=='t' && yonler[2]==1 && yonler[0]==0){
e_caddesi_sag[0]=0;
    int i;
    for(i=320;i>70;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }


}

else if(baslangic_yon[4][0]=='y' && baslangic_yon[4][1]=='x' && yonler[2]==1 && yonler[1]==0){
    e_caddesi_sag[0]=0;
    int i;
    for(i=320;i>125;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=180;i>90;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }


}

else if(baslangic_yon[4][0]=='y' && baslangic_yon[4][1]=='z' && yonler[2]==1 && yonler[3]==0){
 e_caddesi_sag[0]=0;
 int i;
    for(i=320;i>125;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=180;i<270;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
        for(i=220;i<275;i=i+5){
        line(195,i+5,200,i+10);
        line(200,i+5,200,i+10);
        line(205,i+5,200,i+10);
        delay(200);
    }
}

else if(baslangic_yon[4][0]=='z' && baslangic_yon[4][1]=='t' && yonler[3]==1 && yonler[0]==0){
    e_caddesi_sag[0]=0;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=250;i>70;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }

}

else if(baslangic_yon[4][0]=='z' && baslangic_yon[4][1]=='x' && yonler[3]==1 && yonler[1]==0){
    e_caddesi_sag[0]=0;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=250;i>125;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=180;i>90;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(195,i+10,200,i+5);
    line(200,i+10,200,i+5);
    line(205,i+10,200,i+5);
    delay(200);
   }
}

else if(baslangic_yon[4][0]=='z' && baslangic_yon[4][1]=='y' && yonler[3]==1 && yonler[2]==0){
    e_caddesi_sag[0]=1;
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(195,i+10,200,i+5);
        line(200,i+10,200,i+5);
        line(205,i+10,200,i+5);
        delay(200);
    }
    for(i=270;i>180;i=i-5){
        setcolor(YELLOW);
        arc(200,150,i,i+5,65);
        delay(200);
    }
    for(i=140;i<325;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}
//e caddesi


harita1_hesapla(saat_yonu,4,e_caddesi_sag,1,yonler,4);


}





void harita2_buyukdaire(){
   setcolor(BLACK);
   circle(600,150,80);
   setfillstyle(SOLID_FILL,BLACK);
   floodfill(600,150,BLACK);
}
void harita2_kucukdaire(){
   setcolor(WHITE);
   circle(600,150,50);
   setfillstyle(SOLID_FILL,WHITE);
   floodfill(600,150,WHITE);
}
void harita2_arayollar(){
   setcolor(BLACK);
   rectangle(585,20,615,75);//dikey(üst) yol
   rectangle(585,225,615,280);//dikey(alt) yol
   rectangle(470,135,525,165);//yatay yol
   rectangle(675,135,730,165);//yatay yol
   setfillstyle(SOLID_FILL,BLACK);
   floodfill(510,150,BLACK);//(sol)
   floodfill(720,150,BLACK);//(sağ)
   floodfill(600,50,BLACK);//dikey yolu boyar
   floodfill(600,250,BLACK);//dikey yolu boyar
}
void harita2_cizgiler(){
   int i;
   for(i=470;i<730;i=i+5){
    setcolor(WHITE);
    if(i>530 && i<665){
        continue;
    }
    line(i,150,i+1,150);//yatay yolun çizgileri
   }
   for(i=20;i<80;i=i+5){
    setcolor(WHITE);
    line(600,i,600,i+1);//dikey üst yolun çizgileri
   }
   for(i=220;i<280;i=i+5){
    setcolor(WHITE);
    line(600,i,600,i+1);//dikey alt yolun çizgileri
   }
   for(i=0;i<360;i=i+8){
    arc(600,150,i+18,i+20,65);//daire çizgileri
   }
}
void harita2_saricizgi(){
   int i;
   for(i=470;i<730;i++){
    setcolor(BROWN);
    if(i>525 && i<673){
        continue;
    }
    line(i,140,i+1,140);
    line(i,160,i+1,160);
   }
   setcolor(BROWN);
   line(590,20,590,76);
   line(610,20,610,76);
   line(590,224,590,280);
   line(610,224,610,280);

   arc(600,150,8,81,75);
   arc(600,150,99,172,75);
   arc(600,150,189,262,75);
   arc(600,150,279,351,75);
   arc(600,150,0,0,55);
}
void harita2_yonler(){
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
setcolor(RED);
outtextxy(490,143,"t");
outtextxy(546,100,"a");
outtextxy(644,100,"b");
outtextxy(596,40,"x");
outtextxy(705,143,"y");
outtextxy(550,190,"c");
outtextxy(640,190,"d");
outtextxy(597,245,"z");
}
void harita2_yonbelirleme(){
printf("Giris yonu icin 1'e cikis yonu icin 0'a basin:\n");
int yon_a,yon_b,yon_c,yon_d,saat_yonu=0;
char baslangic_yon[4][2];
int yonler[4];
do{
printf("t=");
scanf("%d",&yonler[0]);
printf("x=");
scanf("%d",&yonler[1]);
printf("y=");
scanf("%d",&yonler[2]);
printf("z=");
scanf("%d",&yonler[3]);
if(yonler[0]+yonler[1]+yonler[2]+yonler[3]!=2){
printf("2den fazla giris ya da cikis girdiniz lutfen tekrar deneyin:\n");
}
else{
    break;
}
}while(1);



printf("A caddesi icin baslangic noktasi giriniz:");
scanf("%s",&baslangic_yon[0][0]);
printf("A caddesi icin yon giriniz:");
scanf("%s",&baslangic_yon[0][1]);


printf("B caddesi icin baslangic noktasi giriniz:");
scanf("%s",&baslangic_yon[1][0]);
printf("B caddesi icin yon giriniz:");
scanf("%s",&baslangic_yon[1][1]);

printf("C caddesi icin baslangic noktasi giriniz:");
scanf("%s",&baslangic_yon[2][0]);
printf("C caddesi icin yon giriniz:");
scanf("%s",&baslangic_yon[2][1]);

printf("D caddesi icin baslangic noktasi giriniz:");
scanf("%s",&baslangic_yon[3][0]);
printf("D caddesi icin yon giriniz:");
scanf("%s",&baslangic_yon[3][1]);

settextstyle(BOLD_FONT,HORIZ_DIR,2);
outtextxy(150,150,"A caddesinin yonu--->");

if(baslangic_yon[0][0]=='t' && baslangic_yon[0][1]=='x' && yonler[0]==1 && yonler[1]==0){
    int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>85;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }
}

else if(baslangic_yon[0][0]=='t' && baslangic_yon[0][1]=='y' && yonler[0]==1 && yonler[2]==0){
    int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[0][0]=='t' && baslangic_yon[0][1]=='z' && yonler[0]==1 && yonler[3]==0){
    int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }
}

else if(baslangic_yon[0][0]=='x' && baslangic_yon[0][1]=='t' && yonler[1]==1 && yonler[0]==0){
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
    for(i=90;i<180;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>470;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[0][0]=='x' && baslangic_yon[0][1]=='z' && yonler[1]==1 && yonler[3]==0){
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
    for(i=90;i<270;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }

}

else if(baslangic_yon[0][0]=='x' && baslangic_yon[0][1]=='y' && yonler[1]==1 && yonler[2]==0){
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
    for(i=90;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }


}

else if(baslangic_yon[0][0]=='y' && baslangic_yon[0][1]=='t' && yonler[2]==1 && yonler[0]==0){
    int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=0;i<180;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>465;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[0][0]=='y' && baslangic_yon[0][1]=='x' && yonler[2]==1 && yonler[1]==0){
    int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=360;i>90;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }

}

else if(baslangic_yon[0][0]=='y' && baslangic_yon[0][1]=='z' && yonler[2]==1 && yonler[3]==0){
        int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
     for(i=0;i<270;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }

}

else if(baslangic_yon[0][0]=='z' && baslangic_yon[0][1]=='t' && yonler[3]==1 && yonler[0]==0){
    int i;
    for(i=270;i>220;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<180;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>465;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }

}

else if(baslangic_yon[0][0]=='z' && baslangic_yon[0][1]=='x' && yonler[3]==1 && yonler[1]==0){
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=265;i>90;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }
}

else if(baslangic_yon[0][0]=='z' && baslangic_yon[0][1]=='y' && yonler[3]==1 && yonler[2]==0){
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=265;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }

}
//a caddesi

//baslatma tekrar
cleardevice();
        closegraph();
        initwindow(900,600,"ProLab",250,100);
        floodfill(getmaxx()/2 ,getmaxy()/2,WHITE);
   harita2_buyukdaire();
   harita2_kucukdaire();
   harita2_arayollar();
   harita2_cizgiler();
   harita2_saricizgi();
   harita2_yonler();
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
outtextxy(150,150,"B caddesinin yonu--->");
//


if(baslangic_yon[1][0]=='t' && baslangic_yon[1][1]=='x' && yonler[0]==1 && yonler[1]==0){
    int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }

}

else if(baslangic_yon[1][0]=='t' && baslangic_yon[1][1]=='y' && yonler[0]==1 && yonler[2]==0){
   int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='t' && baslangic_yon[1][1]=='z' && yonler[0]==1 && yonler[3]==0){
    int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='x' && baslangic_yon[1][1]=='t' && yonler[1]==1 && yonler[0]==0){
int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>180;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>465;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }

}

else if(baslangic_yon[1][0]=='x' && baslangic_yon[1][1]=='y' && yonler[1]==1 && yonler[2]==0){
   int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
 for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='x' && baslangic_yon[1][1]=='z' && yonler[1]==1 && yonler[3]==0){
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='y' && baslangic_yon[1][1]=='t' && yonler[2]==1 && yonler[0]==0){
    int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=0;i<180;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>465;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='y' && baslangic_yon[1][1]=='x' && yonler[2]==1 && yonler[1]==0){
    int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }


}

else if(baslangic_yon[1][0]=='y' && baslangic_yon[1][1]=='z' && yonler[2]==1 && yonler[3]==0){
    int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=0;i<270;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='z' && baslangic_yon[1][1]=='t' && yonler[3]==1 && yonler[0]==0){
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<180;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>465;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='z' && baslangic_yon[1][1]=='y' && yonler[3]==1 && yonler[2]==0){
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=265;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
     for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[1][0]=='z' && baslangic_yon[1][1]=='x' && yonler[3]==1 && yonler[1]==0){
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=265;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }
}
//b caddesi

//baslatma tekrar
cleardevice();
        closegraph();
        initwindow(900,600,"ProLab",250,100);
        floodfill(getmaxx()/2 ,getmaxy()/2,WHITE);
   harita2_buyukdaire();
   harita2_kucukdaire();
   harita2_arayollar();
   harita2_cizgiler();
   harita2_saricizgi();
   harita2_yonler();
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
outtextxy(150,150,"C caddesinin yonu--->");
//

if(baslangic_yon[2][0]=='t' && baslangic_yon[2][1]=='x' && yonler[0]==1 && yonler[1]==0){
    int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }
}

else if(baslangic_yon[2][0]=='t' && baslangic_yon[2][1]=='y' && yonler[0]==1 && yonler[2]==0){
    int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='t' && baslangic_yon[2][1]=='z' && yonler[0]==1 && yonler[3]==0){
     int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<270;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='x' && baslangic_yon[2][1]=='t' && yonler[1]==1 && yonler[0]==0){//de
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>180;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>465;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='x' && baslangic_yon[2][1]=='y' && yonler[1]==1 && yonler[2]==0){
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
for(i=85;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='x' && baslangic_yon[2][1]=='z' && yonler[1]==1 && yonler[3]==0){
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
for(i=85;i<270;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='y' && baslangic_yon[2][1]=='t' && yonler[2]==1 && yonler[0]==0){
    int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=360;i>180;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>465;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='y' && baslangic_yon[2][1]=='x' && yonler[2]==1 && yonler[1]==0){
    int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=355;i>90;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }
}

else if(baslangic_yon[2][0]=='y' && baslangic_yon[2][1]=='z' && yonler[2]==1 && yonler[3]==0){
    int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=0;i<270;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='z' && baslangic_yon[2][1]=='t' && yonler[3]==1 && yonler[0]==0){//de
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=265;i>180;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>465;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[2][0]=='z' && baslangic_yon[2][1]=='x' && yonler[3]==1 && yonler[1]==0){
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=265;i>90;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }
}

else if(baslangic_yon[2][0]=='z' && baslangic_yon[2][1]=='y' && yonler[3]==1 && yonler[2]==0){
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=265;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
     for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}
//c caddesi

//baslatma tekrar
cleardevice();
        closegraph();
        initwindow(900,600,"ProLab",250,100);
        floodfill(getmaxx()/2 ,getmaxy()/2,WHITE);
   harita2_buyukdaire();
   harita2_kucukdaire();
   harita2_arayollar();
   harita2_cizgiler();
   harita2_saricizgi();
   harita2_yonler();
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
outtextxy(150,150,"D caddesinin yonu--->");
//

if(baslangic_yon[3][0]=='t' && baslangic_yon[3][1]=='x' && yonler[0]==1 && yonler[1]==0){//de
int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }
}

else if(baslangic_yon[3][0]=='t' && baslangic_yon[3][1]=='y' && yonler[0]==1 && yonler[2]==0){
    int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='t' && baslangic_yon[3][1]=='z' && yonler[0]==1 && yonler[3]==0){
    int i;
    for(i=470;i<520;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
    for(i=180;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='x' && baslangic_yon[3][1]=='t' && yonler[1]==1 && yonler[0]==0){//de
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>180;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>465;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='x' && baslangic_yon[3][1]=='y' && yonler[1]==1 && yonler[2]==0){
    int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
for(i=85;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='x' && baslangic_yon[3][1]=='z' && yonler[1]==1 && yonler[3]==0){
   int i;
    for(i=15;i<70;i=i+5){
    setcolor(YELLOW);
    line(595,i+5,600,i+10);
    line(600,i+5,600,i+10);
    line(605,i+5,600,i+10);
    delay(200);
}
for(i=85;i>0;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
     for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='y' && baslangic_yon[3][1]=='t' && yonler[2]==1 && yonler[0]==0){//de
    int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=360;i>180;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>465;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='y' && baslangic_yon[3][1]=='x' && yonler[2]==1 && yonler[1]==0){
    int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=360;i>90;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }
}

else if(baslangic_yon[3][0]=='y' && baslangic_yon[3][1]=='z' && yonler[2]==1 && yonler[3]==0){
    int i;
    for(i=720;i>660;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
    for(i=360;i>270;i=i-5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=220;i<275;i=i+5){
        line(595,i+5,600,i+10);
        line(600,i+5,600,i+10);
        line(605,i+5,600,i+10);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='z' && baslangic_yon[3][1]=='t' && yonler[3]==1 && yonler[0]==0){
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<180;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=520;i>465;i=i-5){
        setcolor(YELLOW);
        line(i+10,145,i+5,150);
        line(i+10,150,i+5,150);
        line(i+10,155,i+5,150);
        delay(200);
    }
}

else if(baslangic_yon[3][0]=='z' && baslangic_yon[3][1]=='x' && yonler[3]==1 && yonler[1]==0){
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=0;i<90;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=70;i>15;i=i-5){
    setcolor(YELLOW);
    line(595,i+10,600,i+5);
    line(600,i+10,600,i+5);
    line(605,i+10,600,i+5);
    delay(200);
   }
}

else if(baslangic_yon[3][0]=='z' && baslangic_yon[3][1]=='y' && yonler[3]==1 && yonler[2]==0){
    int i;
    for(i=270;i>215;i=i-5){
        setcolor(YELLOW);
        line(595,i+10,600,i+5);
        line(600,i+10,600,i+5);
        line(605,i+10,600,i+5);
        delay(200);
    }
    for(i=270;i<360;i=i+5){
        setcolor(YELLOW);
        arc(600,150,i,i+5,65);
        delay(200);
    }
    for(i=665;i<730;i=i+5){
        setcolor(YELLOW);
        line(i+5,145,i+10,150);
        line(i,150,i+10,150);
        line(i+5,155,i+10,150);
        delay(200);
    }
}
//d caddesi


}




void harita_secimi(){
POINT cursorPosition;
int mx,my;

while(1){
        GetCursorPos(&cursorPosition);
        mx=cursorPosition.x;
        my=cursorPosition.y;
    if(mx>320 && mx<580 && my<400 && my>140){
        if(GetAsyncKeyState(VK_LBUTTON)){
        cleardevice();
        closegraph();
        initwindow(900,600,"ProLab",250,100);
        floodfill(getmaxx()/2 ,getmaxy()/2,WHITE);
   harita1_buyukdaire();
   harita1_kucukdaire();
   harita1_arayollar();
   harita1_cizgiler();
   harita1_saricizgi();
   harita1_yonler();
   harita1_yonbelirleme();
   break;
        }
    }
    if(mx>720 && mx<985 && my<400 && my>140){
        if(GetAsyncKeyState(VK_LBUTTON)){
        cleardevice();
        closegraph();
        initwindow(900,600,"ProLab",250,100);
        floodfill(getmaxx()/2 ,getmaxy()/2,WHITE);
   harita2_buyukdaire();
   harita2_kucukdaire();
   harita2_arayollar();
   harita2_cizgiler();
   harita2_saricizgi();
   harita2_yonler();
   harita2_yonbelirleme();
   break;
    }
    }
}
}




   int main(){


   initwindow(900,600,"ProLab",250,100);
   floodfill(getmaxx()/2 ,getmaxy()/2,WHITE);
   harita1_buyukdaire();
   harita1_kucukdaire();
   harita1_arayollar();
   harita1_cizgiler();
   harita1_saricizgi();
   harita1_yonler();


   harita2_buyukdaire();
   harita2_kucukdaire();
   harita2_arayollar();
   harita2_cizgiler();
   harita2_saricizgi();
   harita2_yonler();

   settextstyle(BOLD_FONT,HORIZ_DIR,2);
   outtextxy(300,400,"Lutfen haritayi secin");

   harita_secimi();







   getch();
   return 0;


   }

