#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

unsigned short b=10000,i=0,o=0;
bool cr=0;

struct number
{
	long long xn[6] ,xd[6];
	long long W0[20];
	float num;


}N[20];

long long Realw(unsigned short , long long *  );
void substract(long long*  , long long* , int* , int , unsigned short* );
void normalize(long long*  ,  unsigned short  , int* );
void convert(char *, long long *);
void afisare_1(long long *);
void menu();
void Sort(struct number *,int );
void HELP();

void Merge(struct number* ,int ,struct number* ,int nr,struct number* );
void Save();
void structurare(long long *,long long *,long long *);

int main()
{

while(1)
{
	menu();
	system("cls");

 long long* n=(long long*)calloc(6,sizeof(long long));

  char* temp1=(char*)calloc(26,sizeof(char));
  char* temp2=(char*)calloc(26,sizeof(char));

  long long W[20]={0} ;
  int q=0;
  long long xd,xn;
  unsigned short last,step=1;
  long long d[6]={0};

  printf("\r\nIntroduceti primul numar : "); gets(temp1); convert(temp1,n);

  printf("Introduceti al doilea  numar : "); gets(temp2); convert(temp2,d);

  

  for(i=1; i<6; i++ )
		W[i+2]=n[i];
	

xd=(d[1]*b +d[2])*b+d[3];

while(step<=15)
{
	
xn=Realw(step+2,W);
q=xn/xd;

last=(step+9<20) ? step+9 : 20;

substract(W,d,&q,step+2,&last);
normalize(W,step+2,&q);

step=step+1;

}

    free(n);
   afisare_1(W);
   structurare(n,d,W);
  printf("\r\n Pentru a te intoarce la menu - tasteaza orice buton...");
	getch();
}
	
}




long long Realw(unsigned short j , long long * W )
{
	long long c=0,s;
	 if(j+2<=18)c=W[j+2];
	s=( ((W[j-1]*b+W[j])*b+W[j+1])*b + c );
	
	return s;

}

void substract(long long* W , long long* d, int* q , int ka , unsigned short*kb )
{
		long long * W0;

		for(i=ka;i<*kb;i++)
		W[i]=W[i]- *q * d[i-ka+1];

}

void normalize(long long* W ,  unsigned short ka , int* q )
{

	W[ka]=W[ka]+W[ka-1]*b;
	W[ka-1]=*q;

}

void convert(char *temp, long long * num)
{
		
		int temp3,j;
		char temp2[20],v=0,x=1;
		j=1;i=0;
		
		while(temp[i]!='.' && temp[i]!=',' && i<strlen(temp) )
		{
			temp2[v++]=temp[i++];

		}
		
		temp3=atoi(temp2);
		num[x++]=(long long)temp3;  v=0;
	
		strcpy(temp2,"0000");
		

		for(i=i+1;i<strlen(temp);i++,j++)
		{
			temp2[v++]=temp[i];
			if(j%4==0) 
			{

				temp3=atoi(temp2); 
				v=0; 
				num[x++]=(long long)temp3;
			 
				strcpy(temp2,"0000");

			}

		} j--;

		
		if(j%4!=0 && v!=0)
		{	
			
			temp3=atoi(temp2); 
			
			if (temp3<10 && v==3) temp3=temp3;
			else if (temp3<10 && v==2) temp3=temp3*100;
			else if (temp3<10) temp3=temp3*1000;
			else if(temp3<100 && v==3 ) temp3=temp3;
			else if(temp3<100) temp3=temp3*100;
			else if(temp3<1000) temp3=temp3;
			 num[x++]=(long long)temp3;
			 
		}
		
		
}

void structurare(long long *n, long long *d, long long * W)
{
	char temp[8];
	for(i=0;i<20;i++)
	N[o].W0[i]=W[i];

	for(i=0;i<6;i++)
	{ N[o].xn[i]=n[i]; N[o].xd[i]=d[i]; }
	
	o++;


}

void afisare_1(long long *W)
{
	
	printf("\r\n Rezultatul este : ");
	printf("%d.",W[2]);
	
	for(i=3;i<17;i++)
	{

	if(W[i]<10 && W[i]>0) printf("%d%d%d",000);
	else if  (W[i]<100) printf("%d%d",00);
	else if  (W[i]<1000) printf("%d",0);
	 printf("%d",W[i]);

	}

	printf("\r\n\r\n Pentru continuare , tasteaza un buton ...\r\n");
	getch();
	cr=1;
 

}
void afisare_2()
{	
	int j,k;
	system("cls");
	

	for(j=0;j<o;j++)
	{
		printf("\r\n Impartirea nr %d",j+1);

		printf("\r\n ");
		for(k=1;k<6;k++)
		{	
		printf("%d",N[j].xn[k]);
		if(k==1) printf(".");
		}
		printf(" / ");
		for(k=1;k<6;k++)
		{	
		printf("%d",N[j].xd[k]);
		if(k==1) printf(".");
		}

		afisare_1(N[j].W0);
		printf("\r\n");


	}


}

void menu()
{
system("cls");
char choice;

	
	while(1)
	{
		system("cls");
printf("\r\n\t\t\t\t Impartirea numerelor cu precizie maxima : ");
printf("\r\n\r\n\t\t\t\t\t\t MENIU PRINCIPAL\r\n\r\n");
printf("\r\nAlege tasta : \r\n");
printf("\r\n\t\t\t\t1-HELP\r\n");
printf("\r\n\t\t\t\t2-Salvare in fisier \r\n");
printf("\r\n\t\t\t\t3-Sortarea numerelor dupa partea intreaga \r\n");
printf("\r\n\t\t\t\t4-Afisarea numerelor\r\n");
printf("\r\n\t\t\t\tENTER - executia programului\r\n");
printf("\r\n\t\t\t\t9-Iesire\r\n");

repeat:	choice=getch();

	switch(choice)
	{
		case '1' : HELP(); break;
		case '2' : Save(); break;
		case '3' : Sort(N,o); break;
		case '4' : afisare_2(); break;
		case '9' : exit(0); break;
		case  13 : return; break;
		default : printf("\r\n Alegere gresita !"); goto repeat; break;

	}
}

}
void HELP()
{
	system("cls");
	printf("\r\n Pentru operatii se folosesc 2 numere reale. ");
	printf("\r\n Programul are o precizie de 56 de cifre dupa virgula ");
	printf("\r\n Rezultatele pot fi salvate in fisier la alegerea utilizatorului ");

	printf("\r\n\r\n\r\n Programul este scris in limbajul C");
	printf("\r\n\r\n Autor: Bitca Ernest (FCIM UTM TI-153)  ");
	printf("\r\n\r\n Algoritmul impartirii : Algoritmul lui D.Smith");
	printf("\r\n\r\n Algoritmul sortarilor Merge Sort (Divide et Impera) ");
	printf("\r\n\r\n Biblioteci folosite : <stdio.h> <stdlib.h> <string.h> <conio.h> ");
	printf("\r\n\r\n Versiunea : 1.0\r\n");
	printf("\r\n Pentru a te intoarce la menu - tasteaza orice buton...");
	getch();
	
	return;
}

void Save()
{
	int j=0,k;
	FILE * fp;
	fp=fopen("Teza.txt","w");
	
	system("cls");
	

	system("cls");
	if(cr==0) printf("\r\n Nu sunt date pentru salvare\r\n");
	else 
	for(j=0;j<o;j++)
	{
		fprintf(fp,"\r\n Impartirea nr %d",j+1);

		fprintf(fp,"\r\n ");
		for(k=1;k<6;k++)
		{	
		fprintf(fp,"%d",N[j].xn[k]);
		if(k==1) fprintf(fp,".");
		}
		fprintf(fp," / ");
		for(k=1;k<6;k++)
		{	
		fprintf(fp,"%d",N[j].xd[k]);
		if(k==1) fprintf(fp,".");
		}

		fprintf(fp,"\r\n Rezultatul este : ");
		fprintf(fp,"%d.",N[j].W0[2]);
	
	for(k=3;k<17;k++)
	{

	if(N[j].W0[k]<10 && N[j].W0[k]>0) fprintf(fp,"%d%d%d",000);
	else if  (N[j].W0[k]<100) fprintf(fp,"%d%d",00);
	else if  (N[j].W0[k]<1000) fprintf(fp,"%d",0);
	 fprintf(fp,"%d",N[j].W0[k]);

	}
		printf("\r\n Salvare cu succes !");
		fprintf(fp,"\r\n");

	}
	fclose (fp);



	printf("\r\n Pentru a te intoarce la menu - tasteaza orice buton...");
	getch();

}

void Sort(struct number *N,int o)
{
	int mid;
	mid=o/2;
	struct number left[mid];
	struct number right[o-mid];

	if(o<2) return;

	for(i=0;i<mid;i++)
		left[i]=N[i];

	for(i=0;i<o;i++)
		right[i-mid]=N[i];

	Sort(left,mid);
	Sort(right,o-mid);
	Merge(left,mid,right,o-mid,N);

}

void Merge(struct number L[],int nl,struct number* R,int nr,struct number* N )
{
	i=0;
	int j=0;
	int k=0;
	while(i<nl && j<nr)
	{
		if(L[i].W0[2]<=R[j].W0[2])
		N[k]=L[i++];

		else
		N[k]=R[j++];

		k++;
	}

	while (i<nl)
		N[k++]=L[i++];
	while(j<nr)
		N[k++]=R[j++];

}


