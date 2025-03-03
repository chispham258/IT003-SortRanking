#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
mt19937_64 RND(seed);

const int N = 1e6;
double a[10][N + 1];


class QuickSort{
    public:
    static int compare(const void* a, const void* b) {
        double arg1 = *(double*)a;
        double arg2 = *(double*)b;
    
        if (arg1 < arg2) return -1;
        else if (arg1 > arg2) return 1;
        else return 0;
    }
    
    
    void quickSort(double arr[]){
        qsort(arr + 1, N, sizeof(double), compare);
    }
}q_sort;

class HeapSort{
    public:
    void heapify(double arr[], int N, int i) {
        int largest = i; 
        int left = 2 * i;
        int right = 2 * i + 1; 
    
        if (left <= N && arr[left] > arr[largest])
            largest = left;
    
        if (right <= N && arr[right] > arr[largest])
            largest = right;
    
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, N, largest); 
        }
    }
    
    void heapSort(double arr[], int N) {
        for (int i = N / 2; i >= 1; i--)
            heapify(arr, N, i);
    
        for (int i = N; i > 1; i--) {
            swap(arr[1], arr[i]);
            heapify(arr, i - 1, 1);
        }
    }

}h_sort;

class MergeSort{
    public:
    void merge(double arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        double leftArr[n1 + 1], rightArr[n2 + 1];
    
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];
    
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
    
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
    
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    
    void mergeSort(double arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
    
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
    
            merge(arr, left, mid, right);
        }
    }

}m_sort;

class CppSort{
    public:
    void cppSort(double arr[]){
        sort(arr + 1, arr + 1 + N);
    }

}c_sort;

map<int, string> h;

void read_input(){
    for(int index = 0; index < 10; ++index){
        string file = "data/data" + to_string(index) + ".txt"; 
        char * path = file.data();
        
        fstream inp;
        inp.open(path);
        
        for(int i = 1; i <= N; ++i)
        inp >> a[index][i];
    }
} 

int main(){
    // auto start = chrono::high_resolution_clock::now();
    // auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double, milli> duration = end - start; 
    
    cout << fixed << setprecision(10);
    h[0] = "QuickSort";
    h[1] = "HeapSort";
    h[2] = "MergeSort";
    h[3] = "cppsort";
    
    fstream out;
    out.open("result.txt");

    for(int j = 0; j < 4; ++j){
        read_input();
        out << h[j] << " ";    
        for(int i = 0; i < 10; ++i){
            auto start = chrono::high_resolution_clock::now();
            if(j == 0) q_sort.quickSort(a[i]);
            if(j == 1) h_sort.heapSort(a[i], N);
            if(j == 2) m_sort.mergeSort(a[i], 1, N);
            if(j == 3) c_sort.cppSort(a[i]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start; 
            
            out << round(duration.count()) << " ";
        }
        out << endl;
    }
    return 0;
}