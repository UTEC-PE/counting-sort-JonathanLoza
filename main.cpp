#include <cstdlib>
#include <iostream>

using namespace std;

void print(int numbers[], int size);
void countingSort(int numbers[], int size);

int main(int argc, char *argv[]) {
    int numbers[] = {1, 4, 1, 2, 7, 5, 2};
    int size = sizeof(numbers) / sizeof(*numbers);

    print(numbers, size);
    countingSort(numbers, size);
    print(numbers, size);

    //system("read");
    return 0;
}

void print(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

void countingSort(int numbers[], int size) {
    int max=0;
    int num2[size]={0};
    for (int i = 0; i <size; i++) {
      num2[i]=numbers[i];
      if(max<numbers[i]){
          max=numbers[i];
      }
    }
    int list1[max+1]={0};
    for (int i = 0; i <size; i++){
      list1[numbers[i]]++;
    }
    for (int i = 1; i <max+1; i++){
      list1[i]+=list1[i-1];

    }
    for(int i=0; i<size;i ++){
      numbers[list1[num2[i]]-1]=num2[i];
      list1[num2[i]]--;
    }
}
