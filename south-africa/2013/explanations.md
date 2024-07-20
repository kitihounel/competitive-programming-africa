# Explanations

## A — Isle of the birds

This problem asks to find the convex hull of a set of points. The solution we provide use Graham scan algorithm.

## C — Fitness

This problem is about number theory.

One of the number theory theorems states that if A ≡ B mod M, then M | (A - B). We are looking for the greatest divisor of A - B which is less or equal to M.

## E — Similarity

This problem is about Levenshtein distance. You can find an introduction in this Wikipedia [article](https://en.wikipedia.org/wiki/Levenshtein_distance).

A very good explanation of the algorithm is given [here](http://blog.ce-se.de/2010/10/11/levenshtein-distance-edit-distance-easily-explained).

## F — Railways

We have to find the second best minimum spanning tree of a given graph.

Our solution is based on the explanations by Amandeep Singh on [Quora](https://www.quora.com/How-do-I-find-the-second-best-minimum-spanning-tree).

1. Sort the edges in O(E log E), then find MST using Kruskal algorithm in O(E).
2. Now, for each edge in MST (We will have V-1 edges in it):
    - Temporarily exclude it from the edge list so that it cannot be chosen.
    - Then, again try to find the MST in O(E).
3. Do this for all the edges in MST, and take the best of all.

Note that we don’t need to sort the edges again in point (2). So, the overall time taken will be O(E log E + VE).

## H — Student IDs

Easy problem. You can solve it. :stuck_out_tongue_winking_eye:
