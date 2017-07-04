// C++ program to print largest contiguous array sum
#include <iostream>

using namespace std;
 
int maxSubArraySum(int a[], int size)
{
    int max_so_far = a[0];
    int curr_max = a[0];
    cout<<"Starting up...\nLet: max_so_far = curr_max = a[0] = "<<a[0]<<endl;
    cout<<"Entering for loop... \n";
    for (int i = 1; i < size; i++)
    {
        cout<<"curr_max = max( a[i], curr_max + a[i] );\ncurr_max = max( "<<a[i]<<", "<<curr_max<<" + "<<a[i]<<" );"<<endl;
        curr_max = max(a[i], curr_max+a[i]);
        cout<<"max_so_far = max( max_so_far, curr_max );\nmax_so_far = max( "<<max_so_far<<", "<<curr_max<<" );"<<endl;
        max_so_far = max(max_so_far, curr_max);

        cout<<"--------\ncurr_max = "<<curr_max<<" ;\nmax_so_far = "<<max_so_far<<" ;\n--------\n";
    }
    
    return max_so_far;
}
 
int main()
{
    int a[] = {-2, -3, 4, 1, -2, -1, 5, 3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    return 0;
}