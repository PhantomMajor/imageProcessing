# Day 3

#### Linked List:
It is an ordered set of elements each containing a link to the successor (and in some cases to the predecessor)

It hs the element such that one part contains the pointer to the next element, and the other part contains the data stored in the element.

#### Queue:
A queue is a container of objects (a linear collection) that are inserted and removed according to the first-in first-out (FIFO) principle.

#### Stack:
A stack is a container of objects that are inserted and removed according to the last-in first-out (LIFO) principle


#### Graphs:
A graph is a data structure that consists of nodes  (vertices) and edges. Graphs can be used for mission training. The two types of graphs are:
* Directed
* Undirected

##### Representation of graphs:

__By Matrix__:
We can represent a graph by an adjacency matrix. It is a nxn matrix where n is the number of nodes. The (i, j)th element is zero if there exists no link from i to j, and one if there exists a link from i to j.

__By Linked List__:
We can represent a graph by an adjacency linked list. We create an array of linked lists. Then LL elements are created in such a way, that the i-th element of the array indicates the i-th node of the graph and is also the head of the LL of all the nodes that are neighbours of i and can be reached from i.


* When vertices are less, we use Adjacency LL.
* When edges are more, we use Adjacency Matrix.


## SEARCHING ALGORITHMS FOR GRAPHS:

### Breadth First Search (BFS):
In this algorithm, we create a queue and an array to keep track of the elements that have been visited. In the queue, we keep adding all the neighbours of a node, and keep adding the neighbours of the last-out element and add them to the queue while keeping track of whether or not we have visited it or not.

### Depth First Search (DFS):
In this algorithm, we create a stack and an array to keep track of the elements that we have visited. We keep going to the depth of one path while adding the other possible paths (elements) to the stack while keeping a track of whether or not we've visited the element or not.


Pseudo-code for blob detection (BFS):

```cpp
// the image has a white background and black blobs

"create a struct called point";

int main()
{
    "linear search  for first black pixel";
    "two for loop"
        {
            if (pixel_is_black && not_visited)
            {
                "call BFS"
                "increase blob counter by one"
            }
        }
}

void BFS(passed parameters)
{
    "create a queue of type point";
    "now create a point and initialize it with the passed parameters";

    "push the point into the queue";
    // queue tail-  |    |    |   |point|  - head

    "while the queue is NOT empty"
    {
        point = queue.front(); // put the value of the front-most guy in the queue, in point
        // queue tail-  |some_guy|some_guy|some_guy|point|  - head

        queue.pop(); // the first guy leaves now
        // queue tail-  |      |some_guy|some_guy|some_guy|  - head ---> point

        "Create 4 cases for 4 neighbours"
        /*  
                   _
                  |_|
                |_|_|_|
                  |_|
        */

        if (
            (neighbour(point) == isValid)
            (neighbour(point) != visited) &&
            (neighbour(point) == black) &&   
        ){
            point p_next;
            "ini the point with the neighbour's coordinates"

            "1. paint the img_out black at p_next"
            "2. update the value to visited for p_next"
            "3. push p2 in the queue"
        }


    }

    "We have completely found the blob when we exit the loop i.e. the queue becomes empty"
}

```

----

Pseudo-code for blob detection (BFS):

```cpp
// the image has a white background and black blobs

int main()
{
    "linear search  for first black pixel";
    "two for loop"
    {
        {
            if (pixel_is_black && not_visited)
            {
                "call DFS"
                "increase blob counter by one"
            }
        }
    }
}

DFS ()
{
    "create a stack"
    "put first black point in stack"
    while(stack != empty)
    {
        "call DFS_METHOD"
    }
}

DFS_METHOD ()
{
    "pop the top most element and return it to point"
    "paint it on the output image"
    "mark it visited"

    "look at contesting neighbours of this returned element"
    {
        if (
            neighbours(point) == isValid &&
            neighbours(point) != visited &&
            neighbours(point) == black            
        ){
            "put neighbours in the stack"
            "look at the topmost point in the stack"
            "call DFS_METHOD" // use this function recurcively
        }
}

```

---


## Motiion planning and path planning
it is a term used in robotics for the process of breaking down a desired __movement task__ into discrete ___motions___ that satisfy __movement constraints__ and possibly optimize some aspect of the movement.

The two algorithms that we studied were:
1. Dijkstra's Algorithm
2. A* Algorithm

___Dijkstra's Algorithm__
Pseudo-code for the algo :-
```cpp

// OVERVIEW OF THE ALGO

"create a sptSet" // this keeps track of all the vertices in the shortest path tree

"assign distance value to all nodes";
"initialize the distance value to INF for all nodes";
"give dist. value 0 to the source node"; // now it will be picked first

while(splSet != include all vertices)
{
    "pick a vertex 'u', which is NOT in splSet and has min value";
    "include 'u' to splSet";
    update(distance values of all adjacent vertices of u);
}

update()
{
    "iterate through all adjacent vertices 'v' ";
    for(every v)
    {
        if(
            (sum of dist. value from source of 'u' and the corresponding weight of the edge) < (distance value of 'v' from the source)
        ){
                distance_value_of_v = dist_val_of_u + edge_weight;
        }
    }
}

```

```cpp
// A MORE FORMAL ALGO

#include<stdio.h>
#include<limits.h>

#define v 9 // define the number of vertices

int main()
{
    // Adjacency matrix representation of the graph
    int graph[V][V] = "create the graph / import it"

    dijkstra(graph, 0); // call the function on graph and source 0

    return 0;
}


void dijktra(int graph, int src)
{
    int dist[V]; // dist[i] holds shortest dist. of i from src

    bool splSet[V]; // it'll be false if not visited, true if visited

    // initialize dist to INF and splSet to FALSE
    for(int i=0; i<V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // distance of src from itself is zero
    dist[src] = 0;

    // find the shortest path of each vertex
    for (int i=0; i<V-1; i++)
    {
        // u is the minimum distance vertex
        int u = minDistance(dist, sptSet)

        // mark the picked vertex
        sptSet[u] = true;

        // update the distance values of adjacent nodes
        for(int j=0; j<V; j++)
        {
            // update dist[v] only if it is not in splSet
            // and there is an edge from u to v
            // and total dist of v from src through u smaller than curent value of dist[v]

            if(
                 ( splSet[v] != true ) &&
                 ( graph[u][v] != 0 ) &&
                 ( ( dist[u] + graph[u][v] ) < dist[v] ) &&
                 ( dist[u] != INT_MAX )
             ){
                 dist[v] = ( dist[u] + graph[u][v] );
             }
        }
    }
}

```

---

__A* Algorithm__

Consider a grid having a starting cell and an end cell. We want to reach the end cell (if possible) as quickly as possible. It picks the node having the least value of "f".

"f" is a parameter defined as a sum of "g" and "h"
```
    f = g + h;
```
here, "g" is defined as the movement cost from the current cell to the next cell.

Hence, the adjacent cells will get a cost 1 and the diagonally adjacent cells will get a cost 1.44 (rounded off to 1.5)

"h" is defined as the geometrical path length from the current cell to the destination cell (irrespective of the fact that walls and obstacles may be present)

In A* algorithm, the path is always directed "towards" the destination. It is therefore a smart algorithm.

---

## Hough Line Transform:
It is a feature extraction technique used in image processing. The purpose of the technique is to find imperfect cases of an ideal case by a voting procedure.

Example -- To detect a straight line, voting is done for almost straight and "imperfect" lines.

The algorithm works in the following way:

1. A "checker point" moves over the Edge-detected image linearly and stops on any edge point as soon as it lands on one.

2. It then uese the parametric line ( xcos(theta)+ysin(theta) = p). Here theta is the parametric angle going from 0 to 2*pi and r is the distance parameter going from 0 to the diagonal-length

3. While keeping the "checker-point" constant the parameters (theta and r) are varied.

4. Voting by edge-points is done about the number of edge-points lying on a particular line (i.e. for a given set of theta and r)

5. A feature space is plotted.

6. The points of intersection of the feature-curves are noted.

7. The points with the maximum intersections (shown by maximum intensity) corresponds to lines in the edge-image.

8. We create a threshold intensity for the feature space so that any point with # of intersections greater than the threshold value will be considered a line.

9. Finally, we can plot the lines corresponding to each of these fature-points (which give us theta-r values, and hence the equations of the lines)


NOTE: Can read about the RRT algorithm.
