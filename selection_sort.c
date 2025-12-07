void selection_sort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int min_ind = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min_ind]) {
                min_ind = j;
            }
        }
        if (min_ind != i) {
            int temp = arr[i];
            arr[i] = arr[min_ind];
            arr[min_ind] = temp;
        }
    }
}
