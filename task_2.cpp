/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<sstream>
#include<fstream>
using namespace std;


//HeapSort
void heapify(double arr[], int n, int i) 
{ 
   
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
    
    if (l < n) {
        if ( arr[l] > arr[largest]) {
            largest = l; 
        
        }
    }  
  
    if (r < n){
        if (arr[r] > arr[largest]) {
            largest = r; 
        }
    }
   
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
        } 
}


void build_heap(double arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);
}
  
int heap_sort(double arr[], int n) 
{
    build_heap(arr, n);
    for (int i = n - 1; i >= 0; i--) { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
} 


//Get Frequency

void get_frequencies(double arr [], int n){
    double temp;
    temp = arr[0];
    int counter = 0;
    cout << "Element" << "   " << "Frequency" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < n; i++){
        if (temp == arr[i]){
            counter++;
        } else {
            cout << arr[i-1] << "            " << counter << endl;
            counter = 1;
            temp = arr[i];
        }
    }
    cout << temp << "            " << counter << endl;
}




double most_frequent(double arr[], int n){
    double temp;
    int max_freq = 0;
    double most_freq_element;
    temp = arr[0];
    int counter = 0;

    for (int i = 0; i < n; i++){
        if (temp == arr[i]){
            counter++;
        } else {
            if (counter > max_freq) {
                max_freq = counter;
                most_freq_element = arr[i-1];
            }
            //cout << arr[i-1] << "            " << counter << endl;
            counter = 1;
            temp = arr[i];
        }
    }
    return most_freq_element;
}

int main()
{
    ifstream f("numbers.txt");
    string num;
    


    double arr[1000];
    int count = 0;
    while (getline (f, num)) {
        // Output the text from the file
        //cout << num << endl;
        stringstream my_num(num);
        int x = 0;
        my_num >> x;
        arr[count] = x;
        count++;
    }
    heap_sort(arr, 1000);
    cout << "Most Frequent Element: " << most_frequent(arr, 1000) << endl << endl;
   
    get_frequencies(arr, 1000);
    
    
}
