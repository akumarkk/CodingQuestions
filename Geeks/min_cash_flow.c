#include<stdio.h>
#include <string.h>
 
// Number of persons (or vertices in the graph)
#define N 4 

typedef struct node_
{
    char name[100];
    int  amt;
}node_t;

// A utility function that returns index of minimum value in arr[]
int getMin(int arr[])
{
    int minInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}
 
// A utility function that returns index of maximum value in arr[]
int getMax(int arr[])
{
    int maxInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}
 
// A utility function to return minimum of 2 values
int minOf2(int x, int y)
{
    return (x<y)? x: y;
}
 
int count;
// amount[p] indicates the net amount to be credited/debited
// to/from person 'p'
// If amount[p] is positive, then i'th person will amount[i]
// If amount[p] is negative, then i'th person will give  -amount[i]
void minCashFlowRec(int amount[])
{
    count++;
    // Find the indexes of minimum and maximum values in amount[]
    // amount[mxCredit] indicates the maximum amount to be given
    //                  (or credited) to any person .
    // And amount[mxDebit] indicates the maximum amount to be taken
    //                  (or debited) from any person.
    // So if there is a positive value in amount[], then there must
    // be a negative value
    int mxCredit = getMax(amount), mxDebit = getMin(amount);
    
    printf("[%d] mxCredit(%d) = %d	    mxDebit(%d) = %d\n",count, mxCredit, amount[mxCredit], mxDebit, amount[mxDebit]);
    // If both amounts are 0, then all amounts are settled
    if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
        return;
 
    // Find the minimum of two amounts
    int min = minOf2(-amount[mxDebit], amount[mxCredit]);
    printf("[%d] minOf2 = %d\n", count, min);
    amount[mxCredit] -= min;
    amount[mxDebit] += min;
 
    // If minimum is the maximum amount to be
    
    printf("[%d] Person %d	pays %d tp persion %d\n",count, mxDebit, min, mxCredit); 
    // Recur for the amount array.  Note that it is guaranteed that
    // the recursion would terminate as either amount[mxCredit] 
    // or  amount[mxDebit] becomes 0
    minCashFlowRec(amount);
}
 
// Given a set of persons as graph[] where graph[i][j] indicates
// the amount that person i needs to pay person j, this function
// finds and prints the minimum cash flow to settle all debts.
void minCashFlow(int graph[][N])
{
    // Create an array amount[], initialize all value in it as 0.
    int amount[N] = {0};
 
    // Calculate the net amount to be paid to person 'p', and
    // stores it in amount[p]. The value of amount[p] can be
    // calculated by subtracting debts of 'p' from credits of 'p'
    for (int p=0; p<N; p++)
       for (int i=0; i<N; i++)
          amount[p] += (graph[i][p] -  graph[p][i]);
 
    minCashFlowRec(amount);
}
 
// Driver program to test above function
int main()
{
    // graph[i][j] indicates the amount that person i needs to
    // pay person j
    int graph[N][N] = { {0, 100, 0, 50},
                        {0, 0,   50, 0},
                        {0, 0,   0, 0},
			{0, 450, 0, 0}
		      };
 
    // Print the solution
    minCashFlow(graph);
    return 0;
}
