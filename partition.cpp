// Partition(A, left, right)
// pivot := A[right]
// cut := left - 1
// for i := left to right - 1 do
//      if A[i] ≤ pivot then
//          cut := cut + 1
//          A[cut] ⇌ A[i]
// A[cut + 1] ⇌ A[right]
// return cut + 1