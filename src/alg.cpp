// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int a = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (*(arr + i) + *(arr + j) == value) {
                a++;
            }
        }
    }
    return a;
}
int countPairs2(int *arr, int len, int value) {
    int a = 0;
    for (int i = 0; i < len; i++) {
        for (int j = len; i < j; j--) {
            if (*(arr + i) + *(arr + j) == value) {
                a++;
            }
        }
     }
     return a;
}
int countPairs3(int *arr, int len, int value) {
    int a = 0;
    for (int i = 0; i < len - 1; i++) {
        int left = i, right = len;
        while (right - 1 > left) {
            int middle = (left + right) / 2;
            if (*(arr + i) + *(arr + middle) == value) {
                a++;
                int newmiddle = middle + 1;
                while (*(arr + i) + *(arr + newmiddle) == value && newmiddle < right) {
                    a++;
                    newmiddle++;
                }
                newmiddle = middle - 1;
                while (*(arr + i) + *(arr + newmiddle) == value && newmiddle > left) {
                    a++;
                    newmiddle--;
                }
                break;
            }
            if (*(arr + i) + *(arr + middle) > value) {
                right = middle;
            } else {
                left = middle;
            }
        }
    }
    return a;
}
