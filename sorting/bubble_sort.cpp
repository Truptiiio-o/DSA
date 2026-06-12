void bubble(vector<int> &arr) {
    int n = arr.size();
    for (int i = n - 1; i > 0; i--) {
        bool is_swapped = false;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                is_swapped = true;
            }
        }
        if (!is_swapped) {
            break;
        }
    }
}
