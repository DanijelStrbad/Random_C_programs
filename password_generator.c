#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void genPswd (int z2, int n)
{
	static int brPoziva;
	char lozinka[101];
	int i, birajZnak;
	
	brPoziva++;
	
	if(brPoziva == 0)
		srand((unsigned)time(NULL));
	
	if(n>75 || n<1 || z2<1 || z2>4)
	{
		printf("\n\nError in \"genPswd\"!\n");
	}
	else
	{
		lozinka[n]=0;
		for(i=0; i<n; i++)
		{
			if(z2==1)
			{
				birajZnak=rand()%2;
				if(birajZnak==0) lozinka[i]=rand()%25+65;
				else lozinka[i]=rand()%25+97;
			}
			else if(z2==2)
			{
				birajZnak=rand()%2;
				lozinka[i]=rand()%10+48;
			}
			else if(z2==3)
			{
				birajZnak=rand()%3;
				if(birajZnak==0) lozinka[i]=rand()%25+65;
				else if(birajZnak==1) lozinka[i]=rand()%25+97;
				else lozinka[i]=rand()%10+48;
			}
			else if(z2==4)
			{
				birajZnak=rand()%4;
				if(birajZnak==0) lozinka[i]=rand()%25+65;
				else if(birajZnak==1) lozinka[i]=rand()%25+97;
				else if(birajZnak==2) lozinka[i]=rand()%10+48;
				else lozinka[i]=rand()%14+33;
			}
		}
		
		printf("\n");
		for(i=0; i<n+20; i++)
			printf("=");
		printf("\n(%2d) password: %s\n", brPoziva, lozinka);
		for(i=0; i<n+20; i++)
			printf("=");
		
		for(i=0; i<n; i++)
			lozinka[i]=(char)(-1);
	}
	printf("\n");
	return;
}

int main (void)
{
	int n, z, i, brLozinka, pom, uvjet1=0, uvjet2=0, uvjet3=0;
	char a;
	do{
		uvjet1 = 0; uvjet2 = 0;
		printf("\nChoose:\n 1-just letters =>[a-z][A-Z]\n 2-just numbers =>[0-9]");
		printf("\n 3-letters and numbers =>[a-z][A-Z][0-9]");
		printf("\n 4-letters, numbers and special characters =>[a-z][A-Z][0-9][!#$...]\n  ");
		z = getchar();
		if(z<'1' || z>'4') {
			uvjet1 = 1;
		}
		z = z-48;
		
		a=getchar();
		if(a == '\n') {
			/* nothing */
		}
		else {
			uvjet1 = 1;
			do{
				a=getchar();
			}while(a!='\n');
		}
		
		printf("\nNumber of characters in password [1-75]: ");
		n = getchar();
		if(n<'1' || n>('0'+9)) {
			uvjet2 = 1;
		}
		n = n-48;
		pom = getchar();
		if(pom == '\n') {
			/* nothing */
		}
		else if(pom>='0' && pom<='9') {
			pom = pom-48;
			n = n*10;
			n = n+pom;
			
			pom = getchar();
			
			if(pom!='\n') {
				uvjet2 = 1;
				do{
					a=getchar();
				}while(a!='\n');
			}
		}
		else {
			do{
				a=getchar();
			}while(a!='\n');
		}
		
		printf("\n\n");
	}while(n<1 || n>75 || (uvjet1) || (uvjet2));
	
	do{
		uvjet3 = 0;
		printf("\nNumber of passwords [1-75]: ");
		brLozinka = getchar();
		if(brLozinka<49 || brLozinka>57) {
			uvjet3 = 1;
		}
		brLozinka = brLozinka-48;
		pom = getchar();
		
		if(pom == '\n') {
			/* nothing */
		}
		else if(pom>='0' && pom<='9') {
			pom = pom-48;
			brLozinka = brLozinka*10;
			brLozinka = brLozinka+pom;
			
			pom = getchar();
			
			if(pom!='\n') {
				uvjet3 = 1;
				do{
					a=getchar();
				}while(a!='\n');
			}
		}
		else {
			do{
				a=getchar();
			}while(a!='\n');
		}
		
	}while( brLozinka<1 || brLozinka>75 || (uvjet3));
	/*do{
		a=getchar();
	}while(a!='\n');*/
	
	for(i=0; i<brLozinka; i++)
		genPswd(z, n);
	
	n=254;	/*KVADRAT - ASCII - 254*/
	a=(char)(n);	/*KVADRAT - ASCII*/
	
	printf("\n\n %c Exit: ", a);
	do{
		a=getchar();
		putchar(a);
	}while(a!='\n');
	return 0;
}
