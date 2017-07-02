/*
We use Heap because the elements need not be sorted in array to determine the median.
If we do by sort method then it takes O(n^2) time complexity.
There are 2 heaps for 2 halves...
If heaps of same size:
	average lower max. and higher max.
If heaps of different size:
	max. of lower half || max. of upper half whichever is higher 
*/

#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
 
double average(int n1, int n2)
{
	return (n1 + n2) / 2.0;
}
 
// This method maintains the condition that maxHeap size 
// is always greater than or equal to minHeap size.
void addNewNumber(int randomNumber, priority_queue< int, vector<int>, greater<int> >& minHeap, priority_queue< int, vector<int>, less<int> >& maxHeap)
{
	if(minHeap.size() == maxHeap.size())
	{
		if((!minHeap.empty()) && (randomNumber > minHeap.top()))
		{
			// since the randomNumber is greater than
			// first element of right half then it needs
			// to be assigned as new minHeap.top()
			// maxHeap.top will now have the previous
			// minHeap.top()
			maxHeap.push(minHeap.top());		
			minHeap.pop();
			minHeap.push(randomNumber);
		}
		else
		{
			// if first element then push to left half of array (maxHeap)
			maxHeap.push(randomNumber);
		}
	}
	// meanHeap and maxHeap size is unequal that is:
	// Array has even number of elements
	else
	{
		// number is greater than ending element
		// of left half of array then
		// let it be starting number of right half
		if(randomNumber > maxHeap.top())
		{
			minHeap.push(randomNumber);
		}
		// number is lower than ending element of
		// left half of array then
		// make the current ending element of left half
		// as top of right half (minHeap)
		// and the number will be ending element of 
		// left half of array
		else
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(randomNumber);
		}
	}
}
 
double getMedian(priority_queue< int, vector<int>, greater<int> > minHeap, priority_queue< int, vector<int>, less<int> > maxHeap)
{
	// maxHeap is always at least as big as minHeap.
	// So if maxHeap is empty, then minHeap is empty too.
	if(maxHeap.empty())
		return 0;
 
	// If both maxHeap and minHeap have same sizes 
	// then return average of their top elements.
	if(maxHeap.size() == minHeap.size())
		return average(maxHeap.top(), minHeap.top());
 
	// if maxHeap and minHeap are of different sizes then
	// maxHeap must have one extra element. So return top of maxHeap.
	return maxHeap.top();
}
 
void printMedian(int arr[], int size)
{
    double median = 0; // effective median
    // minHeap will be right half of greater numbers 
    // with top most element smallest (beginning of 2nd half) of all 
    // those numbers.
    priority_queue< int, vector<int>, greater<int> > minHeap;
    // maxHeap will be left half of smaller numbers
    // with top most element biggest (ending of 1st half) of all
    // those numbers.
	priority_queue< int, vector<int>, less<int> > maxHeap;
 
	for(int i = 0; i < size; i++)
    {
		addNewNumber(arr[i], minHeap, maxHeap);
        median = getMedian(minHeap, maxHeap);
        cout << median << endl;
    }
}
 
int main()
{
	int arr[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    // In lieu of A, we can also use data read from a stream
    printMedian(arr, size);
 
    return 0;
}