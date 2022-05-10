Bubble Sort : 
  Basic::
    bubbleSort(array)
      for i <- 1 to indexOfLastUnsortedElement-1
        if leftElement > rightElement
          swap leftElement and rightElement
    end bubbleSort
  Optimized:
    bubbleSort(array)
      swapped <- false
      for i <- 1 to indexOfLastUnsortedElement-1
        if leftElement > rightElement
          swap leftElement and rightElement
          swapped <- true
    end bubbleSort

  Complexity Analysis: 
     Time complexity:
       Best  =Omega(n)
     Average = Wrost = O(n^2);
     Space Complexity:
       O(1);
     No of Comparision : n(n-1)/2;

Selection Sort: 

  selectionSort(array, size)
    repeat (size - 1) times
    set the first unsorted element as the minimum
    for each of the unsorted elements
      if element < currentMinimum
        set element as new minimum
    swap minimum with first unsorted position
  end selectionSort

  Compelexity Analysis: 
    Best	O(n2)
    Worst	O(n2)
    Average	O(n2)
    Space Complexity	O(1)
    Stability	No
    Comparisions: n(n-1)/2;



Quicksort 

  Psuedocode:
    quickSort(array, leftmostIndex, rightmostIndex)
      if (leftmostIndex < rightmostIndex)
        pivotIndex <- partition(array,leftmostIndex, rightmostIndex)
        quickSort(array, leftmostIndex, pivotIndex - 1)
        quickSort(array, pivotIndex, rightmostIndex)

    partition(array, leftmostIndex, rightmostIndex)
      set rightmostIndex as pivotIndex
      storeIndex <- leftmostIndex - 1
      for i <- leftmostIndex + 1 to rightmostIndex
      if element[i] < pivotElement
        swap element[i] and element[storeIndex]
        storeIndex++
      swap pivotElement and element[storeIndex+1]
    return storeIndex + 1


MergeSort:

  PsuedoCode: 
    MergeSort(A, p, r):
    if p > r 
        return
    q = (p+r)/2
    mergeSort(A, p, q)
    mergeSort(A, q+1, r)
    merge(A, p, q, r)

    Merge Step: 
      Have we reached the end of any of the arrays?
      No:
          Compare current elements of both arrays 
          Copy smaller element into sorted array
          Move pointer of element containing smaller element
      Yes:
          Copy all remaining elements of non-empty array
    
    Merge Sort Complexity
      Time Complexity	 
      Best	O(n*log n)
      Worst	O(n*log n)
      Average	O(n*log n)
      Space Complexity	O(n)
      Stability	Yes
  

counting sort: 
  PsuedoCode: 
    countingSort(array, size)
      max <- find largest element in array
      initialize count array with all zeros
      for j <- 0 to size
        find the total count of each unique element and 
        store the count at jth index in count array
      for i <- 1 to max
        find the cumulative sum and store it in count array itself
      for j <- size down to 1
        restore the elements to array
        decrease count of each element restored by 1
  Complexity Analysis: 
    Time Complexity	 
      Best	O(n+k)
      Worst	O(n+k)
      Average	O(n+k)
      Space Complexity	O(max)
      Stability	Yes


Radix Sort: 
  PsuedoCode: 
    radixSort(array)
      d <- maximum number of digits in the largest element
      create d buckets of size 0-9
      for i <- 0 to d
        sort the elements according to ith place digits using countingSort
    countingSort(array, d)
      max <- find largest element among dth place elements
      initialize count array with all zeros
      for j <- 0 to size
        find the total count of each unique digit in dth place of elements and
        store the count at jth index in count array
      for i <- 1 to max
        find the cumulative sum and store it in count array itself
      for j <- size down to 1
        restore the elements to array
        decrease count of each element restored by 1

  Complexity Analysis: 
    Radix Sort Complexity	 
      Best	O(n+k)
      Worst	O(n+k)
      Average	O(n+k)
      Space Complexity	O(max)
      Stability	Yes


