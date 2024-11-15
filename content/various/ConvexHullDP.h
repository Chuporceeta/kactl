/**
 * Author: John Baldwin
 * License: CC0
 * Source: https://codeforces.com/blog/entry/63823
 * Description: When using DP to quickly calculate the max(mj * x + cj) over some set S of j for some 
 * value x and insertion must also efficient, the problem is equivalent to being given a set of lines 
 * and asked for the maximum y value any of line can give at a particular x. If you draw a bunch of 
 * straight lines on a plane, the maximums are along what appears to be a convex hull. So, a strategy
 * can be to only maintain the convex hull and not keep the useless lines. To querying at x = qi,
 * just compare the value at x of the rightmost line with that of the line next to it. If it is lower
 * remove it and repeat. When done, get the value at x of the rightmost line as the answer to the 
 * query. To insert a line, if the intersection point of this line and the leftmost line lies to the 
 * right of that of the leftmost line and the line to the right of it, the leftmost line is no longer
 * on the hull. Remove it, and repeat. Parallel lines pose an exception to this since they will never
 * intersect, and must be handled separately if such a situation is possible in the problem.
 * Time: O(N + Q) for N lines and Q queries
 */