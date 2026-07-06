#!/usr/bin/env bash
# Reorganizes Leetcode_problems repo into topic folders.
# Run this from the ROOT of your cloned repo (where the 0001-two-sum etc. folders live).
set -e

move() {
  local folder="$1"
  local dest="$2"
  if [ ! -d "$folder" ]; then
    echo "SKIP (not found): $folder"
    return
  fi
  mkdir -p "$dest"
  git mv "$folder" "$dest/$folder"
  echo "moved $folder -> $dest/"
}

# ---------- CYCLE SORT ----------
move "0041-first-missing-positive" "CYCLE SORT"
move "0268-missing-number" "CYCLE SORT"
move "0287-find-the-duplicate-number" "CYCLE SORT"
move "0448-find-all-numbers-disappeared-in-an-array" "CYCLE SORT"
move "0645-set-mismatch" "CYCLE SORT"

# ---------- 1-D DP ----------
move "0509-fibonacci-number" "1-D DP"
move "0070-climbing-stairs" "1-D DP"
move "0746-min-cost-climbing-stairs" "1-D DP"
move "0198-house-robber" "1-D DP"
move "0213-house-robber-ii" "1-D DP"
move "0646-maximum-length-of-pair-chain" "1-D DP"
move "0343-integer-break" "1-D DP"
move "1262-greatest-sum-divisible-by-three" "1-D DP"

# ---------- LIS ----------
move "0300-longest-increasing-subsequence" "LIS"
move "0673-number-of-longest-increasing-subsequence" "LIS"

# ---------- Greedy ----------
move "0455-assign-cookies" "Greedy"
move "3074-apple-redistribution-into-boxes" "Greedy"
move "0055-jump-game" "Greedy"
move "0045-jump-game-ii" "Greedy"
move "1871-jump-game-vii" "Greedy"

# ---------- Top K Elements ----------
move "0347-top-k-frequent-elements" "Top K Elements"

# ---------- Tree Traversal - Post-Order ----------
move "0145-binary-tree-postorder-traversal" "Tree Traversal - Post-Order"
move "0226-invert-binary-tree" "Tree Traversal - Post-Order"
move "1110-delete-nodes-and-return-forest" "Tree Traversal - Post-Order"
move "0236-lowest-common-ancestor-of-a-binary-tree" "Tree Traversal - Post-Order"
move "0652-find-duplicate-subtrees" "Tree Traversal - Post-Order"
move "0543-diameter-of-binary-tree" "Tree Traversal - Post-Order"

# ---------- Tree Traversal - Level Order ----------
move "0102-binary-tree-level-order-traversal" "Tree Traversal - Level Order"
move "0103-binary-tree-zigzag-level-order-traversal" "Tree Traversal - Level Order"
move "0104-maximum-depth-of-binary-tree" "Tree Traversal - Level Order"
move "0116-populating-next-right-pointers-in-each-node" "Tree Traversal - Level Order"
move "0117-populating-next-right-pointers-in-each-node-ii" "Tree Traversal - Level Order"
move "0199-binary-tree-right-side-view" "Tree Traversal - Level Order"
move "0637-average-of-levels-in-binary-tree" "Tree Traversal - Level Order"
move "0662-maximum-width-of-binary-tree" "Tree Traversal - Level Order"
move "0958-check-completeness-of-a-binary-tree" "Tree Traversal - Level Order"

# ---------- Tree Traversal - Pre-Order ----------
move "0100-same-tree" "Tree Traversal - Pre-Order"
move "0101-symmetric-tree" "Tree Traversal - Pre-Order"
move "0108-convert-sorted-array-to-binary-search-tree" "Tree Traversal - Pre-Order"
move "0112-path-sum" "Tree Traversal - Pre-Order"
move "0113-path-sum-ii" "Tree Traversal - Pre-Order"
move "0144-binary-tree-preorder-traversal" "Tree Traversal - Pre-Order"
move "0222-count-complete-tree-nodes" "Tree Traversal - Pre-Order"
move "0257-binary-tree-paths" "Tree Traversal - Pre-Order"
move "0404-sum-of-left-leaves" "Tree Traversal - Pre-Order"
move "0437-path-sum-iii" "Tree Traversal - Pre-Order"

# ---------- Tree Traversal - In Order ----------
move "0094-binary-tree-inorder-traversal" "Tree Traversal - In Order"
move "0098-validate-binary-search-tree" "Tree Traversal - In Order"
move "0173-binary-search-tree-iterator" "Tree Traversal - In Order"
move "0230-kth-smallest-element-in-a-bst" "Tree Traversal - In Order"
move "0530-minimum-absolute-difference-in-bst" "Tree Traversal - In Order"
move "0783-minimum-distance-between-bst-nodes" "Tree Traversal - In Order"

# ---------- Binary Search ----------
move "0004-median-of-two-sorted-arrays" "Binary Search"
move "0033-search-in-rotated-sorted-array" "Binary Search"
move "0034-find-first-and-last-position-of-element-in-sorted-array" "Binary Search"

# ---------- Monotonic Stack ----------
move "0084-largest-rectangle-in-histogram" "Monotonic Stack"

# ---------- Monotonic Queue ----------
move "0239-sliding-window-maximum" "Monotonic Queue"

# ---------- Fast and Slow Pointers ----------
move "0142-linked-list-cycle-ii" "Fast and Slow Pointers"

# ---------- Stacks ----------
move "0020-valid-parentheses" "Stacks"
move "0155-min-stack" "Stacks"

# ---------- Kadane's Algorithm ----------
move "0053-maximum-subarray" "Kadane's Algorithm"

# ---------- Linked List ----------
move "0002-add-two-numbers" "Linked List"
move "0019-remove-nth-node-from-end-of-list" "Linked List"
move "0024-swap-nodes-in-pairs" "Linked List"

# ---------- Prefix Sum ----------
move "0560-subarray-sum-equals-k" "Prefix Sum"

# ---------- Sliding Window - Fixed Size ----------
move "0438-find-all-anagrams-in-a-string" "Sliding Window - Fixed Size"
move "0567-permutation-in-string" "Sliding Window - Fixed Size"

# ---------- Sliding Window - Dynamic Size ----------
move "0003-longest-substring-without-repeating-characters" "Sliding Window - Dynamic Size"

# ---------- Hash Tables ----------
move "0049-group-anagrams" "Hash Tables"
move "0128-longest-consecutive-sequence" "Hash Tables"
move "0205-isomorphic-strings" "Hash Tables"
move "0219-contains-duplicate-ii" "Hash Tables"
move "0535-encode-and-decode-tinyurl" "Hash Tables"

# ---------- Two Pointers ----------
move "0001-two-sum" "Two Pointers"
move "0011-container-with-most-water" "Two Pointers"
move "0015-3sum" "Two Pointers"
move "0042-trapping-rain-water" "Two Pointers"
move "0167-two-sum-ii-input-array-is-sorted" "Two Pointers"

# ---------- Arrays ----------
move "0169-majority-element" "Arrays"
move "0238-product-of-array-except-self" "Arrays"
move "0283-move-zeroes" "Arrays"

# ---------- Strings ----------
move "0392-is-subsequence" "Strings"

echo ""
echo "Done. Review with: git status"
