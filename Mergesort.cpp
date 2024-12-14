// Rekursiivinen hajoita & hallitse algoritmi
//
// Mergesort(A, left, right)
// if left < right then
// mid := [(left+right)/2]
// Mergesort(A, left, mid)
// Mergesort(A, mid+1, right)
// Merge(A,left,mid,right)


// Input Requirement:

// The merge step requires two already sorted lists (or subarrays) as input.
// The algorithm assumes these two lists are sorted and combines them into one sorted list.


// Merge(A, left, mid, right)
// for i := left to right do
//      Tmp[i] := A[i]
// out := left
// in_l := left; in_r := mid + 1
// white in_l ≤ mid and in_r ≤ right do
//      if Tmp[in_l] ≤ Tmp[in_r] then
//          A[out] := Tmp[in_l]
//          in_l := in_l + 1
//      else
//          A[out] := Tmp[in_r]
//          in_r := in_r + 1
//          out := out + 1
// if in_l > mid then
//      in_rest := in_r
// else
//      in_rest := in_l
// for i := 0 to right-out do
//      A[out + 1] := Tmp[in_rest = i]