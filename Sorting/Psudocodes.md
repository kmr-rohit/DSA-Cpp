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
