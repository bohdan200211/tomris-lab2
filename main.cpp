#include "main.h"

int main()
{

	/*LinkedList<atomic>* ll = atomic::atomic_from_string(*new string("{a1,~a12,b123,~b1234}"));
	for(int i = 0; i < ll->size; i++)
		printf("Atomo: %s, negate: %s\n",ll->get(i)->atom.c_str(),(ll->get(i)->negate == true ? "true" : "false"));
	
	system("pause");
	exit(1);*/

	char * cformula = (char*)malloc(sizeof(char)*1024);
	string formula("");
	string tableaux("");
	printf("Enter the formula in the form of a sentence to solve it in the solver:\n");
	printf("For example: {{a12,b},{~a,b},{a,~b32},{~a,~b},{a},{~bade}} where ~ represents the not operator.\n");
	printf("Even if it's just the formula {a}, it should be represented as follows:\n");
	printf("You can use any index after the letter, for example {{a12312731283}}\n");
	printf("You can't use double negation because it's redudant.\n");

	scanf("%s",cformula);
	formula = cformula;
	LinkedList< LinkedList<atomic> > *lla = atomic::atomic_from_formula(formula);
	int size = formula.length();
	int cont = 1;
	char* s = (char*)malloc(sizeof(char)*256);
	sprintf(s, "%d", cont);
	tableaux.append(s);
	tableaux.append(". ");
	for(int i = 1; i < size-1; i++)
	{
		if (formula.at(i) != '}')
		{			
			tableaux.append(formula.substr(i,1));
		}
		else
		{
			cont++;
			sprintf(s, "%d", cont);
			tableaux.append("}\n");
			tableaux.append(s);
			tableaux.append(". ");
			i++;
		}
	}
	
	while(atomic::iteract_tableaux(lla))
	{
		printf("Solving Table by the resolution method\n");
		//do nothing
	}
	printf("Table solved\n");
	
	for(int i = 0; i < lla->size; i++)
	{
		printf("%d. {", i+1);
		if (lla->get(i)->size > 0)
		{
			for(int j = 0; j < lla->get(i)->size; j++)
			{
				if (j != lla->get(i)->size - 1)
					printf("%s,",lla->get(i)->get(j)->toString().c_str());
				else
					printf("%s}\n",lla->get(i)->get(j)->toString().c_str());
			}
		}
		else
			printf("}\n");
	}

	return 0;
}