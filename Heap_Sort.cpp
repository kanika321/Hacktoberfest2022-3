#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
#define MAX 1000
using namespace std;
template <class T>
class Hsort
{
  public:
    T A[MAX];
    int comparisons, heap_size, length;
    Hsort()
    {
      comparisons = 0;
    }
    void input();
	int left(int);
	int right(int);
	int parent(int);
    void heap_sort(T[]);
    void build_max_heap(T[]);
	void max_heapify(T[],int);
    void display()
    {
      cout<<"\nSorted array : \n";
      for(int i = 1; i <= length; i++)
        cout<<A[i]<<" ";
	}
};
template<class T>
int Hsort<T>::left(int i)
{
  return 2*i;
}
template<class T>
int Hsort<T>::right(int i)
{
  return 2*i + 1;
}
template<class T>
int Hsort<T>::parent(int i)
{
  return i/2;
}
template<class T>
void Hsort<T>::input()
{
  for (int i = 1; i <= length; i++)
     A[i] = rand();
}
template<class T>
void Hsort<T>::max_heapify(T A[], int i)
{
  int l = left(i);
  int r = right(i);
  int temp, largest;  
  if (l <= heap_size && A[l] > A[i])
    largest = l;
  else 
    largest = i;
  comparisons++;  
  if (r <= heap_size && A[r] > A[largest])
    largest = r;  
  comparisons++;  
  if (largest != i)
  {
    temp = A[i];
	A[i] = A[largest];
	A[largest] = temp;
	max_heapify(A, largest);
  } 
}
template<class T>
void Hsort<T>::build_max_heap(T A[])
{
  heap_size = length;
  int i;
  for (i = length/2; i >= 1; i--)
  {
    max_heapify(A, i);
  }
} 
template<class T>
void Hsort<T>::heap_sort(T A[])
{
  build_max_heap(A);
  int i, temp;
  for (i = length; i >= 2; i--)
  {
    temp = A[1];
	A[1] = A[i];
	A[i] = temp;
	heap_size = heap_size - 1;
	max_heapify(A, 1);
  }
}
int main()
{
  int size, c;
  ofstream fout;
  fout.open("HeapSortGraph.csv", ios::app);    
  cout<<"\t* * * Heap Sort with Time Complexities\' Graph * * *\n" ; 
  Hsort<int> list;
  cout<<"\nEnter array size to begin with {in range [30, 1000] }  : ";
  cin>>size;
  if (size < 30 || size > 1000)
  {
      cout<<"\nInvalid Size !!! \nEnter size from given range only i.e. [30, 1000] \nsize : ";
	  cin>>size;
  }
  else 
  {
    for (int k = size; k <= 1000; k += 30)
    {
	  list.length = k;
	  list.comparisons = 0;
      list.input();
	  list.heap_sort(list.A);
	  list.display();
	  cout<<"\n\nNumber of Comparisons : "<<list.comparisons;
      fout<<k<<","<<k*k<<","<<list.comparisons<<","<<log2(k)<<","<<k*log2(k)<<endl;
	}
  }
  fout.close();
  return 0;
}  
