// A Dynamic Programming based solution for 0-1 Knapsack problem
#include <iostream>

using namespace std;

int max(int a, int b) { return (a > b)? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity maxWeight
int knapSack(int maxWeight, int wt[], int val[], int n)
{
   int i, currWeight;
   int K[n+1][maxWeight+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (currWeight = 0; currWeight <= maxWeight; currWeight++)
       {
           if (i==0 || currWeight==0)
               K[i][currWeight] = 0;
           else if (wt[i-1] <= currWeight)
                 K[i][currWeight] = max(val[i-1] + K[i-1][currWeight-wt[i-1]],  K[i-1][currWeight]);
           else
                 K[i][currWeight] = K[i-1][currWeight];
           cout<<K[i][currWeight]<<"\t";
       }
       cout<<endl;
   }
 
   return K[n][maxWeight];
}
 
int main()
{
    int val[] = {2, 3, 5};
    int wt[] = {1, 2, 3};
    int  maxWeight = 3;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<"Maximum Vaue: "<<knapSack(maxWeight, wt, val, n);
    return 0;
}