// Problem 3 - Longest Substring Without Repeating Characters
//
// Given a string, find the length of the longest substring without repeating
// characters.

package main

// BEGIN
// We maintain a map from previously seen letters to their indices in the
// string. If we encounter a letter that has been seen before, we reset the map
// and jump back to the position right after that letter occured previously.
// The answer is the maximum size of the map throughout the iteration.
func lengthOfLongestSubstring(s string) int {
  answer := 0
  seen := make(map[uint8]int)
  i := 0

  for i < len(s) {
    idx, ok := seen[s[i]];

    if (ok) {
      // Letter has been seen previously
      if answer < len(seen) {
        answer = len(seen)
      }
      seen = make(map[uint8]int)
      i = idx + 1
    }

    seen[s[i]] = i
    i++
  }

  if answer < len(seen) {
    answer = len(seen)
  }

  return answer
}
// END

func main() {
  lengthOfLongestSubstring("abcabcbb");
}
