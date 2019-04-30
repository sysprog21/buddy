# Buddy Memory Allocator

This package implements a buddy memory allocator, which is an allocator that
allocates memory within a fixed linear address range. It spans the address
range with a binary  tree that tracks free space.

Both "malloc" and "free" are O(log N) time where N is the maximum possible
number of allocations. All of the metadata about the memory chunk (e.g.,
its size and whether it is currently being used) is stored at the beginning
of that block of memory. 

The "buddy" term comes from how the tree is used. When memory is allocated,
nodes in the tree are split recursively until a node of the appropriate size
is reached. Every split results in two child nodes, each of which is the
buddy of the other. When a node is freed, the node and its buddy can be merged
if the buddy is also free. This makes the memory available for larger
allocations again.

Reference: [Wikipedia](https://en.wikipedia.org/wiki/Buddy_memory_allocation)
