#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	FILE *girdi, *cikti;
	
	char sifre[]={};
	int anahtar, i;
	
	//Dosyayý acma
	girdi = fopen("input 1.txt","r");
	
	if (girdi == NULL) {
		printf("Input dosyasý acilirken bir hata olustu.\n");
          return 1;
     }
	
	//Dosyadaki kelimeyi okuma
	fscanf(girdi, "%s",sifre);
	
	
	// Anahtarý kullanýcýdan alma
	printf("Anahtar degerini girin: ");
	scanf("%d", &anahtar);
	
	
	//Sifreleme
	
	while (sifre[i] != '\0') {
        if (sifre[i] >= 'A' && sifre[i] <= 'Z') {
            sifre[i] = (sifre[i] - 'A' + anahtar) % 26 + 'A';
        } else if (sifre[i] >= 'a' && sifre[i] <= 'z') {
            sifre[i] = (sifre[i] - 'a' + anahtar) % 26 + 'a';
        }
        i++;
     }
	
	
	printf("\nSifrelenmis metin  :  %s\n\n",sifre);
	
	cikti = fopen("sifrelenmis.txt","w");
	
	if(cikti == NULL){
		printf("Sifrelenmis metni yazilacak dosya acilirken bir hata olustu.\n");
		return 1;
	}
	
	fprintf(cikti, "%s", sifre);
	
	fclose(girdi);
     fclose(cikti);
     
     printf("Sifrelenmis metin 'sifrelenmis_metin.txt' dosyasina yazildi.\n");
	
	
	return 0;
}
