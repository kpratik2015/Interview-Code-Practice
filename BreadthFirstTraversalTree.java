import java.util.Queue;
import java.util.LinkedList;

/*
Time Complexity: O(n) where n is number of nodes in binary tree
*/

class Node { // This was not there in BFT-Graph
	int data;
	Node left, right;
	public Node(int item) {
		data = item;
		left = null;
		right = null;
	}
}

class BreadthFirstTraversalTree {
	Node root;

	void PrintLevelOrder() { // no start point 's' like in graph
		Queue<Node> queue = new LinkedList<>();
		// in graph, visited had to be marked
		queue.add(root);
		while(!queue.isEmpty()) {
			Node tempNode = queue.poll();
			System.out.print(tempNode.data+" ");
			
			if(tempNode.left != null) {
				queue.add(tempNode.left);
			}

			if(tempNode.right != null) {
				queue.add(tempNode.right);
			}
		}
	}

	public static void main(String[] args) {
		BreadthFirstTraversalTree tree_level = new BreadthFirstTraversalTree();
		tree_level.root = new Node(1);
		tree_level.root.left = new Node(2);
		tree_level.root.right = new Node(3);
		tree_level.root.left.left = new Node(4);
		tree_level.root.left.right = new Node(5);

		System.out.println("Level order traversal of tree: ");
		tree_level.PrintLevelOrder();
	}
}
