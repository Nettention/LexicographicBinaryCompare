# LexicographicBinaryCompare
This C/C++ program compares two binaries in lexicographical order.

# Pros

Faster than `lexicographical_compare` generic function, which does one-byte naive comparison.

One out-of-the-box header file.

# Cons

If there is a specialized template function for `lexicographical_compare`, you may want to compare the performance.

Not optimized for 64bit binary yet. Somebody do it. :)

# How to use

Include the header file into your project.

Call the function.

Check out `main()` function for the detailed usage.

# Do we really need this?

No, actually. :)

You can simply implement the lexicographical comparer with a `memcmp` call and a length comparison. HAHAHA
