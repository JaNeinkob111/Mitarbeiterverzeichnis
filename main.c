/*
 * Mitarbeiter Verzeichnis
 *
 *  Created on: 09.11.2022
 *      Author: Jakob Noweck 907898
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define CLRSCR() system("cls")
#define PATH "F:\\HSD\\Informatik\\Mitarbeiterliste.txt"


void menue();
void eingeben();
void ausgeben();
void mitarbeiterpeicher();
void mitarbeiterladen();

struct mitarbeiter{
	char name [16];
	int rufnummer;
	char abteilung;
}liste [100];
int maindex = 0;

int main()
{
	CLRSCR();
	printf("Zum Start des Menues tippen sie eine Taste");
	mitarbeiterladen();
	getch();
	menue();
	mitarbeiterpeicher();
	CLRSCR();
	return 0;
}

void menue()
{
	int einausgabe;
	do
	{

		CLRSCR();
		printf("Menue\n");
		printf("Wenn sie ausgeben wollen tippen sie [1] "
				"\nwenn sie eingeben wollen tippen sie [2]"
				"\nwenn sie beenden wollen tippen sie [3]\n");
		scanf("%d", &einausgabe);
		fflush(stdin);
		CLRSCR();
		switch(einausgabe)
		{
			case 1: ausgeben(); break;
			case 2: eingeben(); break;
			case 3: return;
			default: printf("FEHLER!\nUng\x81ltige Eingabe");
		}
		getch();
	}while(einausgabe!=3);
	CLRSCR();
}

void eingeben ()
{
	CLRSCR();
	printf("Hier ist die Eingabe");
	printf("\nVorname des Mitarbeiters (max. 15 Zeichen): ");
	scanf("%15s", liste[maindex].name);
	fflush(stdin);
	printf("Rufnummer (3 Ziffern): ");
	scanf("%3i", &liste[maindex].rufnummer);
	fflush(stdin);
	printf("Abteilung: ");
	scanf("%1s", &liste[maindex].abteilung);
	fflush(stdin);
	maindex++;
}

void ausgeben (struct mitarbeiter *str1)
{
	CLRSCR();
	printf("%-15s","Mitarbeiter Verzeichnis\n\n");
	printf("%-15s %-15s %-15s\n","Name", "Rufnummer", "Abteilung");
	for(int i=0; i<maindex; i++)
	{
		printf("%-15s %-15i %-15c\n"
		,liste[i].name, liste[i].rufnummer, liste[i].abteilung);
	}
}

void mitarbeiterpeicher()
{
	FILE *fp;
	fp = fopen(PATH, "w");
	if (fp==NULL)
	{
		printf("Die Datei wurde nicht gefunden");
	}
	else
	{
		fprintf(fp, "%i\n", maindex);
		for(int i =0; i<maindex; i++)
		{
			fprintf(fp,"%-15s %-15i %-15c\n", liste[i].name, liste[i].rufnummer, liste[i].abteilung);
		}
		fclose(fp);
	}
}

void mitarbeiterladen()
{
	FILE *fp;
	fp = fopen(PATH, "r");
	if(fp==NULL)
	{
		printf("Die Datei wurde nicht gefunden");
	}
	else
	{
		fscanf(fp,"%i",&maindex);
		for(int i=0; i<maindex; i++)
		{
			fscanf(fp,"%s %i %c", liste[i].name, &liste[i].rufnummer, &liste[i].abteilung);
		}
		fclose(fp);
		printf("\nEs sind %i Eintraege vorhanedn", maindex);
	}
}