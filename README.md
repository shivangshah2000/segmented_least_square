# Segmented Least Squares

Implementing Segmented least square algorithm in C++

## Least Squares

This is the problem of fitting a single line so as to minimize the sum of the squared errors of the set of points.

## Segmented Least Squares

This is the problem of finding a set of `l` segments such that they do not overlap, and they minimize the tradeoff function.

The Tradeoff function is the sum of the squared errors and the cost of each segment.

## Example

For input (in `x y` format)
```
3 5
2 4
1 7
6 9
9 6
2 5
10 2
11 13
21 50
7 8
```
For `c = 5`, the number of optimal segments was 3.
![](/home/kush/segmented_least_square/assets/example_c_5.png)

For `c = 100`, the number of optimal segments was 2.
![](/home/kush/segmented_least_square/assets/example_c_100.png)


## Time Complexity Analysis

The time complexity of the implemented solution is `O(n^3)`, where `n` is the number of points in the input set.

The times were averaged over 10 runs.

| Size of Input | Time (ms) |
|---------------|-----------|
| 100 | 3.6 |
| 200 | 21.9 |
| 300 | 51.2 |
| 400 | 83.7 |
| 500 | 127.1 |

![](/home/kush/segmented_least_square/assets/benchmarks.jpeg)

## Memory Complexity Analysis

The memory complexity of the implemented solution is `O(n)`, where `n` is the number of points in the input set.

| Size of Input | Memory(kb) |
|---------------|------------|
| 100 | 3964 |
| 200 | 4456 |
| 300 | 5660 |
| 400 | 7444 |
| 500 | 9556 |

![](/home/kush/segmented_least_square/assets/membench.jpeg)

## Building

`$ g++ -std=c++17 src/main.cpp -O3 -o main`

## Team

- Kushagra Gupta    2018A7PS0208H
- Shivang Shah      2018A7PS0295H
- Shreyas R         2018A7PS0430H
- Pranay Pant       2018A7PS0161H
