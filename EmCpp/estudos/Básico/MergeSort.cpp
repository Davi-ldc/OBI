#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right, vector<int> &OriginalVector) {
    int i = 0, j = 0, k = 0;

    cout << "Merge iniciado\n";
    cout << "Left: ";
    for (int num : left) cout << num << " ";
    cout << "\nRight: ";
    for (int num : right) cout << num << " ";
    cout << "\n";

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            OriginalVector[k] = left[i];
            i++;
        } else {
            OriginalVector[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size()) {
        OriginalVector[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size()) {
        OriginalVector[k] = right[j];
        j++;
        k++;
    }

    cout << "Resultado da fusão: ";
    for (int num : OriginalVector) cout << num << " ";
    cout << "\n--------------------------\n";

    return OriginalVector;
}

void mergeSort(vector<int>& V) {
    if (V.size() <= 1) return;

    int middle = V.size() / 2;
    vector<int> left(V.begin(), V.begin() + middle);
    vector<int> right(V.begin() + middle, V.end());

    cout << "Dividindo vetor: ";
    for (int num : V) cout << num << " ";
    cout << "\n-> Esquerda: ";
    for (int num : left) cout << num << " ";
    cout << "\n-> Direita: ";
    for (int num : right) cout << num << " ";
    cout << "\n==========================\n";

    mergeSort(left);
    mergeSort(right);
    merge(left, right, V);
}

int main() {
    vector<int> V = {8, 6, 4, 7, 2, 10, 1, 3};

    cout << "Vetor original: ";
    for (int num : V) cout << num << " ";
    cout << "\n\n";

    mergeSort(V);

    cout << "\nVetor ordenado: ";
    for (int num : V) cout << num << " ";
    cout << "\n";

    return 0;
}
