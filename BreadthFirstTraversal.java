/*
Queue Data Structure for adding vertices visited
*/

import java.io.*;
import java.util.*;
 
class BreadthFirstTraversal
{
    private int numOfVertices; 
    // Array of LinkedList denoting adjacency list
    private LinkedList<Integer> adj[];
 
    BreadthFirstTraversal(int v)
    {
        numOfVertices = v;
        // v array of LinkedList
        adj = new LinkedList[v];
        for (int i=0; i<v; ++i)
            // assigning memory to individual linkedlist
            adj[i] = new LinkedList<>();
    }
 
    void addEdge(int v,int w)
    {
        adj[v].add(w);
    }
 
    void BFS(int s)
    {
        boolean visited[] = new boolean[numOfVertices];
 
        // Create a queue for BFS
        LinkedList<Integer> queue = new LinkedList<Integer>();
 
        // Mark the current node as visited and enqueue it
        visited[s]=true;
        queue.add(s);
 
        while (queue.size() != 0)
        {
            // Dequeue a vertex from queue and print it
            s = queue.poll();
            System.out.print(s+" ");
 
            // Get all adjacent vertices of the dequeued vertex s
            // If a adjacent has not been visited, then mark it
            // visited and enqueue it
            Iterator<Integer> i = adj[s].listIterator();
            while (i.hasNext())
            {
                int n = i.next();
                if (!visited[n])
                {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }
 
    public static void main(String args[])
    {
        BreadthFirstTraversal g = new BreadthFirstTraversal(4);
 
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
 
        System.out.println("Following is Breadth First Traversal "+
                           "(starting from vertex 2)");
 
        g.BFS(2);

        System.out.println();
    }
}