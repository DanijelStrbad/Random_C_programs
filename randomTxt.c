#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void genRandTxt (int n)
{
	char lozinka[1000001];
	int i, birajZnak, maxDulj=0, minDulj=1000, trDuljina=0, suma=0, brRazmaka=0;
	double prosjek = 0.0;
	char a=(char)(254);	/*KVADRAT - ASCII*/
	FILE *zapisiTxt;
	zapisiTxt=fopen("randText.txt", "w");
	
	srand((unsigned)time(NULL));
	
	if(n>1000000 || n<1)
	{
		printf("\n\nError in call function 'genRandTxt'! (n in range [1, 1000000])\n");
	}
	else
	{
		if(zapisiTxt == NULL) {
			printf("\nFile error: randText.txt\n\n");
			exit(1);
		}
	
		lozinka[n] = (char)0;
		for(i=0; i<n; i++) {
			birajZnak=rand()%9;
			
			if( birajZnak>=0 && birajZnak<=7 ) {
				if( trDuljina<1000 ) {
					lozinka[i] = (char)( rand()%25+97 );
					
					trDuljina++;
				} else {
					i--;
					continue;
				}
			}
			else {
				if( (i==0) || (i==(n-1)) || ( (char)lozinka[i-1]==(char)32 ) ) {
					i--;
					continue;
				} else {
					lozinka[i] = (char)32;
					
					if( trDuljina>maxDulj ) {
						maxDulj = trDuljina;
					}
					if( trDuljina<minDulj ) {
						minDulj = trDuljina;
					}
					
					brRazmaka++;
					suma += trDuljina;
					trDuljina = 0;
				}
			}
		}
		
		prosjek = ((double)suma) / ((double)(brRazmaka+1));
		
		printf("\n");
		for(i=0; i<50; i++)
			printf("=");
		printf("\nText is:\n\n%s\n\n", lozinka);
		printf("\nMin word length: %d, Max word length: %d, Average word length: %3.2f\nNumber of words: %d, Number of characters: %d\n\n",
				minDulj, maxDulj, prosjek, (brRazmaka+1), n);
		for(i=0; i<50; i++)
			printf("=");
		
		printf("\n");
		for(i=0; i<50; i++)
			printf("=");
		printf("\n%c Writing text in file 'randText.txt' ..\n", a);
		for(i=0; i<50; i++)
			printf("=");
		
		fprintf(zapisiTxt, "%s\n", lozinka);
		fprintf(zapisiTxt, "\n\nMin word length: %d, Max word length: %d, Average word length: %3.2f, Number of words: %d, Number of characters: %d\n",
				minDulj, maxDulj, prosjek, (brRazmaka+1), n);
		
		fclose(zapisiTxt);
		
		printf("\n");
		for(i=0; i<50; i++)
			printf("=");
		printf("\n%c Writing in file 'randText.txt' done.\n", a);
		for(i=0; i<50; i++)
			printf("=");
	}
	printf("\n");
	return;
}

void eatInput() {
	char a;
	do{
		a=getchar();
		putchar(a);
	}while(a!='\n');
}

int main (void)
{
	int n, pom, uvjet1=0, i;
	char a;
	printf("Program for 'random typing'\n");
	
	do{
		uvjet1 = 0;
		
		printf("\nInput number of characters [1, 1000000]: ");
		
		i = 0;
		n = 0;
		pom = 0;
		while(1) {
			if( i>8 ) {
				uvjet1 = 1;
				eatInput();
				break;
			}
			i++;
			
			pom = getchar();
			if( pom>='0' && pom<='9' ) {
				pom = pom-48;
				n = n*10;
				n = n+pom;
			} else if( pom == '\n' ) {
				break;
			} else {
				uvjet1 = 1;
				eatInput();
				break;
			}
		}
		
		printf("\n");
	}while( n<1 || n>1000000 || uvjet1 );
	
	printf("Generating %d characters.\n", n);
	
	genRandTxt(n);
	
	a=(char)(254);	/*KVADRAT - ASCII*/
	
	printf("\n %c File randText.txt is generated.\n %c Input some letter for exit: ", a, a);
	eatInput();
	return 0;
}
