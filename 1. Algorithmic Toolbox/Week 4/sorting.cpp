#include <iostream>
#include <vector>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

vector<int> partition3(vector<int> &a, int l, int r) {
    int x = a[l];
    vector<int> j = {l, r};
    int i = l + 1;
    while (i <= j[1]) {
        if (a[i] < x) {
            j[0]++;
            swap(a[i++], a[j[0]]);
        } else if (a[i] == x) {
            swap(a[i], a[j[1]]);
            j[1]--;
        } else {
            i++;
        }
    }

    swap(a[l], a[j[0]]);

    int q = j[0];
    for (int z = j[1] + 1; z <= r; z++) {
        ++q;
        swap(a[q], a[z]);
    }
    j[1] = q;

    return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    vector<int> m = partition3(a, l, r);

    randomized_quick_sort(a, l, m[0] - 1);
    randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
