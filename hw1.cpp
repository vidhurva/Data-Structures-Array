// Vidhur Vashisht
// Data Structures: Hw 1
// February 9th 2018

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

int SIZE = 8;
int size = 6;
int d = 2;
int n = 7;
//int n1 = sizeof(arr4) / sizeof(arr4[0]);
//int n2 = sizeof(arr5) / sizeof(arr5[0]);

using namespace std;

void initialize(int arr[]);
void print(int arr[]);
void print2(int arr[]);
void rotate(int arr[], int d, int n);
void maxProfit(int prices[], int size);
void pushZerosToEnd(int arr[], int n);
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]);
int findMajority(int arr[], int size);

int main()
{	 
   int arr1[SIZE];
   int prices[size];
   int arr3[SIZE];
   int arr4[] = {1, 3, 4, 5};
   int arr5[] = {2, 4, 6, 8};
   int arr7[size];
   int n3 = sizeof(arr3) / sizeof(arr3[0]);
   int n1 = sizeof(arr4) / sizeof(arr4[0]);
   int n2 = sizeof(arr5) / sizeof(arr5[0]);
   int arr6[n1 + n2];

   // Question 1

   initialize(arr1);
   cout << "Original Array: ";
   print(arr1);
   rotate(arr1, d, n);
   cout << "New Array:      ";
   print(arr1);
   cout << endl;

   // Question 2
   cout << "prices = ";
   initialize(prices);
   print(prices);
   maxProfit(prices, size);
   cout << endl;

   // Question 3

   initialize(arr3);
   cout << "Original Array: ";
   print(arr3);
   pushZerosToEnd(arr3, n3);
   cout << "New Array:      ";
   print(arr3);
   cout << endl;

   // Question 4
   cout << "arr1[] = ";
   for(int j = 0; j < 4; ++j)
      cout << setw(3) << arr4[j];
   cout << endl;

   cout << "arr2[] = ";
   for(int y = 0; y < 4; ++y)
      cout << setw(3) << arr5[y];
   cout << endl;  

   cout << "arr3[] = ";
   mergeArrays(arr4, arr5, n1, n2, arr6);
   cout << endl;

   // Question 5

   initialize(arr7);
   print(arr7);
   findMajority(arr7, size);  
   cout << endl;

   return 0;
}   

void initialize(int arr[])
{
   srand(time(NULL));
      for(int n = 0; n < SIZE; ++n)
         arr[n] = (7.0 * rand() / RAND_MAX);
}

void print(int arr[])
{
   cout << "{";	
   for(int j = 0; j < SIZE; ++j)
      cout << arr[j] << ",";
   cout << "}" << endl;
}

void print2(int arr[])
{
   for(int y = 0; y < SIZE; ++y)
      cout << setw(4) << arr[y];
   cout << endl;
}
		
void rotate(int arr[], int d, int n)
{
   int temp[d];
   int it = 0;
   
   for(int i = 0; i < d; ++i)
      temp[i] = arr[i];   	   
   for(int k = 1; k < n; ++k)
      arr[k] = arr[k + d];
   for(int p = n - d; p < n; ++p)
      arr[p] = temp[it++]; 	
}

void maxProfit(int prices[], int size)
{
   int max = prices[1], min = prices[0];
   int max_diff = max - min;

   for(int i = 0; i < size; ++i)
   {
      if(prices[i] > max)
         max = prices[i];
      if(prices[i] < min)
	 min = prices[i];
      if(max - min > max_diff)
	max_diff = max - min;
   }     
   cout << "Max difference =" << max << " - " << min;
   cout << " = " << max_diff << endl;
}    

void pushZerosToEnd(int arr[], int n)
{
   int count = 0;	
   for(int j = 0; j < n; ++j)	   
      if(arr[j] != 0)
         arr[count++] = arr[j];
   while (count < n)
      arr[count++] = 0;   
}   
      
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
   int i = 0, j = 0, k = 0; 	
   
   while(i < n1 && j < n2) 	   
   {
      if(arr1[i] < arr2[j])
	arr3[k++] = arr1[i++];
      else
	arr3[k++] = arr2[j++];
     }
      
   while(i < n1)
      arr3[k++] = arr1[i++];
   while(j < n2)
      arr3[k++] = arr2[j++];
   
   for(int f = 0; f < n1 + n2; f++)
      cout << arr3[f] << " ";
   cout << endl;   

}   

int findMajority(int arr[], int size)
{
   int count = 0;
   int majority = 0;
   for(int i = 0; i < size; i++)
   {
      if(count == 0)
         majority = arr[i];
      if(arr[i] == majority)
	 count++;
      else
	 count--;
   }
      if(count > size/2)
	 return majority;
      else
	 cout << "There is no majority element";
}     

