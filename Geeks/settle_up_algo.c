#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
minimum(int a, int b)
{
    if(a < b)
	return a;
    else
	return b;
}


typedef struct node_
{
    char name[100];
    int  credit;
    int	 debit;
}person_t;


int
get_min(int *arr, int n)
{
    int min = 0;

    for(int i=1; i<n; i++)
    {
	if(arr[min] > arr[i])
	    min = i;
    }

    return min;
}

int
get_max(int *arr, int n)
{   
    int max = 0;
    
    for(int i=1; i<n; i++)
    {   
        if(arr[max] < arr[i])
            max = i;
    }   
    
    return max;
}

void
print_amount(int *amount, int n)
{
    printf("Amount : ");
    for(int i=0; i<n; i++)
    {
	printf("%d  ", amount[i]);
    }
    printf("\n\n");
}

int
settle_up(int *amount, int n, person_t *per)
{
    int max_credit, max_debit, min;

    max_credit = get_max(amount, n);
    max_debit  = get_min(amount, n);

    if(amount[max_credit] == 0 && amount[max_debit] == 0)
	return 0;

    min = minimum(abs(amount[max_credit]), abs(amount[max_debit]));
    
    amount[max_credit] = amount[max_credit] - min;//Pay creditor min amount
    amount[max_debit] = amount[max_debit] + min; // Debit the same. Here min is added as debit
						 // will always be negative.

    printf("%s paid %d to %s\n", per[max_debit].name, min,  per[max_credit].name);
    //printf("%s paid %d to %s\n", (per+max_credit)->name, min,  (per+max_debit)->name);
    print_amount(amount, n);
    return settle_up(amount, n, per);

}

int
main()
{
    int amount[4];
    person_t per[4] = { {"Satti",	0,	150},
			{"Anil M R",	550,	50},
			{"Venky",	50,	0},
			{"Anil K K",	50,	450}
		      };

    for(int i=0; i<4; i++)
	amount[i] = per[i].credit - per[i].debit;

    print_amount(amount, 4);
    settle_up(amount, 4, per);
    return 0;
}


