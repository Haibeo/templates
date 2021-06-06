#include<stdio.h>

void swap(int* a,int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int bin_search(int* a,int i,int j,int num){
    if(i > j){
        return 0;
    }
    if(i == j){
        if(a[i] == num){
            return 1;
        }else{
            return 0;
        }
    }
    int mid = (i+j)/2;
    if(num == a[mid]){
        return 1;
    }
    if(num > a[mid]){
        return bin_search(a,mid+1,j,num);
    }
    return bin_search(a,i,mid-1,num);
}

//heap sort
void heapify(int* x,int size,int i){
    int largest = i;
    int left = i*2 +1;
    int right  = i*2 + 2;
    if(right < size && x[right] > x[largest]){
        largest = right;
    }
    if(left < size && x[left] > x[largest]){
        largest = left;
    }
    if( largest != i){
        swap(&x[i],&x[largest]);
        heapify(x,size,largest);
    }
}

void heap_sort(int* x,int size){
    int i;
    for(i = size/2-1;i>=0;i--){
        heapify(x,size,i);
    }
    for(i = size-1;i>0;i--){
        swap(&x[0],&x[i]);
        heapify(x,i,0);
    }
}


int bin_search_process(int* a,int i,int j,int q){
    heap_sort(a,j+1);
    int count  =0;
    int m;
    for(m =0;m<=j;m++){
        if( q - a[m] < 0){
            continue;
        }else{
            count += bin_search(a,m+1,j,q-a[m]);
        }
    }
    return count;
}

int main(){
    int a[] ={1,4,2,3};
    printf("%d",bin_search_process(a,0,3,5));
    return 0;
}