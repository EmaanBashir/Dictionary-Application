#ifndef SORTINGALGORITHM_H
#define SORTINGALGORITHM_H
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

//class SortingAlgorithm
class SortingAlgorithm {

    //public methods
public:

    //quick sort method
    static void quickSort(vector<string> &array, int firstIndex, int lastIndex);

    //partition method
    static int partition(vector<string> &array, int firstIndex, int lastIndex);

};
#endif // SORTINGALGORITHM_H
