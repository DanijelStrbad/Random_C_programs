#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void genRandTxt (int n, char text[], int textLength)
{
	char lozinka[1000001];
	int i, trZnak, maxDulj=0, minDulj=1000000, trDuljina=0, suma=0, brRazmaka=0;
	double prosjek = 0.0;
	char a=(char)(254);	/*KVADRAT - ASCII*/
	FILE *zapisiTxt;
	zapisiTxt=fopen("randText.txt", "w");
	
	srand((unsigned)time(NULL));
	
	if(n>1000000 || n<1 || textLength>1000 || textLength<1)
	{
		printf("\n\nError in call function 'genRandTxt'! (n in range [1, 1000000]) (textLength in range [1, 1000])\n");
	}
	else
	{
		if(zapisiTxt == NULL) {
			printf("\nFile error: randText.txt\n\n");
			exit(1);
		}
		
		printf("\n");
		for(i=0; i<50; i++)
			printf("=");
		printf("\n%c Generating text ...\n", a);
		for(i=0; i<50; i++)
			printf("=");
		
	
		lozinka[n] = (char)0;	/* null terminator */
		for(i=0; i<n; i++) {
			trZnak = rand()%textLength;
			
			lozinka[i] = (char)( text[trZnak] );
			
			if( text[trZnak] != ' ' ) {
				trDuljina++;
			} else {
				if( trDuljina > maxDulj ) {
					maxDulj = trDuljina;
				}
				if( trDuljina < minDulj ) {
					minDulj = trDuljina;
				}
				
				brRazmaka++;
				suma += trDuljina;
				trDuljina = 0;
			}
		}
		if( brRazmaka == 0 ) {
			maxDulj = trDuljina;
			minDulj = trDuljina;
			suma = trDuljina;
		}
		
		prosjek = ((double)suma) / ((double)(brRazmaka+1));
		
		
		printf("\nText is:\n\n%s\n\n", lozinka);
		printf("\nMin word length: %d, Max word length: %d, Average word length: %3.2f\nNumber of words: %d, Number of characters: %d\n\n",
				minDulj, maxDulj, prosjek, (brRazmaka+1), n);
		for(i=0; i<50; i++)
			printf("=");
		
		printf("\n");
		for(i=0; i<50; i++)
			printf("=");
		printf("\n%c Writing text in file 'randText.txt' ...\n", a);
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
	int n, pom, uvjet1=0, i, userCharSetLength;
	char a;
	char userCharSet[1000001];
	printf("Program for 'random typing'\n");
	
	
	do{
		uvjet1 = 0;
		
		printf("\nInput characters [1, 1000]:\n ");
		i = 0;
		pom = 0;
		while(1) {
			pom = getchar();
			
			if( pom == '\n') {
				userCharSet[i] = (char)(0);
				break;
			} else if( i>=1000 ) {
				uvjet1 = 1;
				userCharSet[i] = (char)(0);
				printf("\nInput string has more than 1000 characters!\n");
				printf("Please eneter input string again!\n\n");
				eatInput();
				break;
			} else {
				userCharSet[i] = (char)pom;
			}
			i++;
		}
		
		printf("\n");
	}while( uvjet1 );
	userCharSetLength = i;
	
	
	do{
		uvjet1 = 0;
		
		printf("Input length of generated string [1, 1000000]: ");
		i = 0;	/* number of input characters */
		n = 0;	/* number to get */
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
	
	printf("Input string (long %d characters) is:\n%s\n\n\n\n", userCharSetLength, userCharSet);
	
	genRandTxt(n, userCharSet, userCharSetLength);
	
	a=(char)(254);	/*KVADRAT - ASCII*/
	
	printf("\n %c File randText.txt is generated.\n %c Input some letter for exit: ", a, a);
	eatInput();
	return 0;
}

