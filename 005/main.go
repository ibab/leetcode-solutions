// Problem 5 - Longest Palindromic Substring
//
// Given a string S, find the longest palindromic substring in S. You may
// assume that the maximum length of S is 1000, and there exists one unique
// longest palindromic substring.

package main

// Finds the longest palindromic substring in O(n^2) time.
// The problem could also be solved in O(n) using Manacher's algorithm.
func longestPalindrome(s string) string {
	max_left := 0
	max_right := 0

	// We imagine that the string contains placeholder characters in between each
	// character and at the end, like this:
	//     aba -> a#b#a#
	//
	// This allows us to treat even and odd palindromes the same way:
	//     bb  -> b#b#     is symmetric around the first #
	//     aba -> a#b#a#   is symmetric around b
	//
	// This is why we iterate over a total length of 2 * len(s) here.
	// We perform O(n) iterations of this loop.
	for i := 0; i < 2*len(s); i++ {
		left := i
		right := i
		// Extend radially outwards from i, stopping if we overstep the string
		// boundaries or if there's a mismatch. This inner loop has a time
		// complexity of O(n), which means we have an overall time complexity of O(n^2).
		for left >= 0 && right < 2*len(s) {
			// If left%2 == 0, then we are testing non-placeholder characters,
			// otherwise we know that the comparison must succeed, so we can skip it.
			// We map the indices back into the original string.
			if left%2 == 0 && s[left/2] != s[right/2] {
				break
			}
			left--
			right++
		}

		// We take a step back to recover the indices from whichever condition
		// terminated the loop.
		left++
		right--

		// Convert back to indices in the original string, narrowing the selection.
		// This means that we round the left index up, and the right index down.
		// Note the extra + 1 for the right index, which allows us to use the index
		// difference as the length, and allows the right index to be used to
		// extract the slice.
		real_left := (left + left%2) / 2
		real_right := right/2 + 1
		if real_right-real_left > max_right-max_left {
			max_left = real_left
			max_right = real_right
		}
	}

	return s[max_left:max_right]
}

func main() {
	println(longestPalindrome("qqabbax"))
}
