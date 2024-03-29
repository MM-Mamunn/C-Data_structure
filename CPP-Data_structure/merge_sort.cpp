#include <iostream>
using namespace std;


void Merge(int arr[], int p, int q, int r) {

  //creating two subarrays L & M
  //n1 & n2 are the sizes of L & M
  int n1 = q - p + 1;
  int n2 = r - q;


  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  //i is the current index pointer of L & j is the current index pointer of M & k is the current index pointer of arr
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{

  //l<r because we need atleast size of 2 elements of array to divide into 2 sub arrays,
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    // int m = l + (r - l) / 2;
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    Merge(arr, l, m, r);
  }
}



int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  //int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, 5);

  cout << "Sorted array: \n";
  for(int i =0;i<6;i++)
    cout<<arr[i]<<" ";
  return 0;
}