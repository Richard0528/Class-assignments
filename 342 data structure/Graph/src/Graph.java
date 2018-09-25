import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Graph {
		
	/** Number of vertices. */
    private int V;
    private LinkedList<Integer> adj[];

	public Graph(int v) {
		V = v;
		adj = new LinkedList[v];    // linked list for all the nodes
		for (int i = 0; i < v; i++) {
			adj[i] = new LinkedList();    // linked list for bucket of each node
		}
	}
	
	/**
	 * Using adjacent list to store a graph
	 * 
	 * @param v vertex
	 * @param w weight
	 */
	private void addEdge(int v, int w) {
		
		adj[v].add(w);
		
	}
	
	/**
	 * Breath first search
	 * 
	 * @param s BFS traversal from a source s
	 */
	private void BFS(int s) {
		
	}
	
	/**
	 * Depth first search
	 * 
	 * @param s DFS traversal from a source s
	 */
	private void DFS(int s) {
		boolean[] visited = new boolean[V];
		DFSUtil(s, visited);
	}
	
	private void DFSUtil(int v, boolean[] visited) {
		visited[v] = true;
		System.out.print(v + " ");
		
		Iterator<Integer> i = adj[v].listIterator();
        while (i.hasNext()) {
            int n = i.next();
            if (!visited[n]) {
            		DFSUtil(n, visited);
            }
        }
	}
	
	private void Dijkstra() {
		
	}


	public static void main(String args[]) {
		Graph g = new Graph(4);

		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 2);
		g.addEdge(2, 0);
		g.addEdge(2, 3);
		g.addEdge(3, 3);

		System.out.println("Following is Breadth First Traversal "+
				"(starting from vertex 2)");

		g.DFS(2);
//		g.BFS(2);
		
	}
    

	
}
