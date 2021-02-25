#include <bits/stdc++.h>
#include <time.h>
using namespace std;

void printArray(int stream[], int n) {
    for (int i = 0; i < n; i++)
        cout << stream[i] << " ";
    cout << endl;
}

void selectKItems(int stream[], int n, int k) {
    int i;
    int reservoir[k];

    for (i = 0; i < k; i++) reservoir[i] = stream[i];

    srand(time(NULL));

    for (; i < n; i++) {
        int j = rand() % (i + 1);
        if (j < k) reservoir[j] = stream[i];
    }

    cout << "Following are k randomly selected items \n";
    printArray(reservoir, k);
}

int main()
{
    int stream[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(stream) / sizeof(stream[0]);
    int k = 5;
    selectKItems(stream, n, k);
    return 0;
} 