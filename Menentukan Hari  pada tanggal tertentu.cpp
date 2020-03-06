#include <iostream>
#include <conio>
#include <stdio>

void main(){

int hari[12]={31,29,31,30,31,30,31,31,30,31,30,31},bln,tgl,thn=2016,h=5,s,a,pil,thna,q,w=0,jum,t;
char bulan[13][10]={"januari","februari","maret","april","mei","juni","juli","agustus","september","oktober","september","november","desember"};
char ming[7][10]={"senin","selasa","rabu","kamis","jum'at","sabtu","minggu"};
int jh=0,tgl1,tgl2,bln1,bln2,thn1,thn2,pili,pilih;

induk:
clrscr();

cout<<"tanggal menjadi hari "<<endl;
cout<<"untuk tahun 2016"<<endl;
cout<<"\nmasukk tanggal(HHBB)= "<<endl;cin>>tgl;cin>>bln;
cout<<endl<<endl;
cout<<"pada tanggal "<<tgl<<" bulan "<<bulan[bln-1]<<" dan tahun 2016 merupakan =";

//menghitung jumlah hari
for(a=1;a<bln;a++)
{
h=h+hari[a-1];
}

//menentukan hari
if(h<=7) s=h;
else s=h%7;

cout<<"hari "<<ming[s-1];

 cout<<"\n\nMenu = "<<endl;

 cout<<"1.Cari lagi"<<endl;
 cout<<"2.Hari di tahun lain(2013-4000)"<<endl;
 cout<<"3.menghitung selisih hari = "<<endl;
 cout<<"4.Keluar"<<endl;
 cout<<"pilihan anda ";cin>>pil;
 switch(pil)
 {

 	case 1:
   	goto induk;
      break;

 	case 2 :
   thn:
   cout<<"tanggal menjadi hari "<<endl;
   cout<<"untuk tahun (2013-4000)"<<endl;
   cout<<"\nmasukkan tahun tujuan = "<<endl;
   cin>>thna;
   //penentuan apakah masa depan atau masa lalu
   if(thna>thn)
   {
   for(a=thn;a<thna;a++)
   	{
      if (thn%4==0)  q=2;
      else q=1;
      w+=q;
      }
   }
   else if (thna<thn)
   {
   for(a=thn;a>thna;a--)
   	{	if (thn%4==1) {q=2;}
      	else {q=1;}
      	w-=q;
      }
   }

   //penentuan hari
   jum=h+w;
   if(jum>7) s=jum%7;
   else  s=jum;

   cout<<"pada tgl "<<tgl<<" bulan "<<bulan[bln-1]<<" tahun "<<thna<<" adalah hari ";
   cout<<"hari "<<ming[s-1]<<endl;

   cout<<"menu:"<<endl;
   cout<<"1.cari lagi"<<endl;
   cout<<"2.back "<<endl;
   cout<<"3.exit"<<endl;
   cout<<"masukkan pilihan anda ";cin>>pili;

   switch(pili)
   {
   	case 1:
      	goto thn;
         break;
      case 2:
      	goto induk;
         break;
      case 3:
      	goto akhir;
         break;
   }

   break;
   case 3:
      selisih:
   	cout<<"Mencari selisih hari dari TGL X sampai TGL Y "<<endl;
      cout<<"TGL X"<<endl;
      cout<<"tanggal ";cin>>tgl1;
      cout<<"bulan ";cin>>bln1;
      cout<<"tahun ";cin>>thn1;
      cout<<"\nTGL Y "<<endl;
      cout<<"tanggal ";cin>>tgl2;
      cout<<"bulan ";cin>>bln2;
      cout<<"tahun ";cin>>thn2;

      //menghitung hari

      jh=hari[bln1-1]-tgl1;

      if(thna=thn1)
         {
         if(bln1=bln2) jh=tgl2-tgl1;

         else
         	{
         	for(a=bln1+1;a<bln2;a++)
         		{
         			jh+=hari[a];
         		}
         	}
         }


       else
      {
      	for(a=bln1+1;a<=12;a++)
      	{
      		jh+=hari[a];
      	}

         for(a=thn1++;a<thn2;a++)
      	{
      		if(a%4==1) jh+=366;
         	else jh+=363;
      	}
         for(a=1;a<bln2;a++)
      	{
      		jh+=hari[a];
      	}
      	jh+=tgl2;

      }

      cout<<"selisih hari antara TGL X dan TGL Y adalah "<<jh<<" Hari"<<endl;
      cout<<"\nMenu = "<<endl;
      cout<<"1.hitung lagi "<<endl;
      cout<<"2.Back"<<endl;
      cout<<"3.exit"<<endl;
      cout<<"masukkan pilihan anda";cin>>pilih;
      switch(pilih)
      {
      case 1:
      	goto selisih;
         break;
      case 2:
      	goto induk;
         break;
      case 3:
      	goto akhir;
         break;
      }


      break;



   case 4:
   	goto akhir;
      break;
   }




getch();
akhir:}

