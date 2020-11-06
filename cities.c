#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Bsize 200
#define Elements 10000

typedef struct
{
	char city[100];
	int population;
	char country[100];
} City;	


int compare(const void *a, const void *b)
{
	City *city1 = (City *)a;
	City *city2 = (City *)b;
	return (city2->population - city1->population);
}

int main()
{
	char filename[] = "cities.csv";
	char buffer[Bsize];
	FILE *f;
	char *data;
	City filecity[Elements];
	f = fopen(filename,"r");
	int count = 0;
	int skip = 0;
	if (f == NULL)
	{
		printf("Unable to open file %s\n",filename);
		return 0;
	}
	while (fgets(buffer,Bsize,f))
	{
		if (skip == 0)
		{
			skip++;
			continue;
		}
		data=strtok(buffer,",");
		/*strcpy(filecity[count].city,data);*/
		data=strtok(NULL,",");
		strcpy(filecity[count].city,data);
		data=strtok(NULL,",");
		data=strtok(NULL,",");
		data=strtok(NULL,",");
		filecity[count].population = atoi(data);
		data=strtok(NULL,",");
		strcpy(filecity[count].country,data);
		count++;
	}
	
	qsort(filecity,Elements,sizeof(City),compare);
	
	FILE *sortF;
	sortF = fopen ("sorted.csv","w");
	int i = 0;
	for (i = 0; i < 7322 ; i++)
	{
		fprintf(sortF,"%s,%d,%s\n",filecity[i].city,filecity[i].population,filecity[i].country);
	}
	fclose(f);
	fclose(sortF);
	return 0;
}