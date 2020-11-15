#include <iostream>
#include <vector>

// Returns the index of the peak value
// Array is assumed to be strictly monotonically increasing, 
// then decreasing.
template <typename T> std::size_t peak_index(const std::vector<T>& a)
{
   using namespace std; 
   // Some basic parameter checking
   if(a.size() < 3) throw invalid_argument("Array must have 3 or more elements.");
   
   std::size_t low = 0, high = a.size() - 1; 
   while(low < high)
   {
       std::size_t mid = (low + high + 1)/2;
       if(a[mid-1]>a[mid]) high = mid - 1;
       else low = mid;
   }
   return low;
}