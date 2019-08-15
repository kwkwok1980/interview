void quickSort(int arr[], int low, int high) {
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before / partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}*/
/* This function takes last element as pivot, places  the pivot element 
   at its correct position in sorted  array, and places all smaller (smaller
   than pivot) to left of pivot and all greater elements to right  of pivot */
int partition (int arr[], int low, int high)
{
   int start = low;
   int end = high - 1;

   auto print = [&]()
   {
      for (int i=low; i<=high; ++i)
      {
         std::cout << arr[i] << " ";
      }
      std::cout << std::endl;
   };

   while (true)
   {
      while(start < end)
      {
         if (arr[start] > arr[high])
         {
            break;
         }
         else
         {
            ++start;
         }
      }
      
      while(end > start)
      {
         if (arr[end] <= arr[high])
         {
            break;
         }
         else
         {
            --end;
         }
      }
      
      if (start < end)
      {
         std::swap(arr[start], arr[end]);
         //print();
      }
      else
      {
         if (arr[start] > arr[high])
         {
            std::swap(arr[start], arr[high]);
            //print();
            return start;
         }
         else
         {
            //print();
            return high;
         }
      }
   }

   // Your code here
}
