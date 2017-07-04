import java.io.*;
import java.util.*;

class Node {
    public int data;
    public Node left, right;

    Node(int d){
        data = d;
        left = right = null;
    }
}

class BinaryTreeFromSortedArray {
    static Node root;

    Node arrToBST(int arr[], int start, int end) {
        if(start > end)
            return null;

        int mid = (start+end+1)/2;

        Node node = new Node(arr[mid]);

        node.left = arrToBST(arr, start, mid-1);
        node.right = arrToBST(arr, mid+1, end);

        return node;
    }

    void preOrder(Node node) {
        if(node == null)
            return ;

        System.out.print(node.data+" ");
        preOrder(node.left);
        preOrder(node.right);

    }    

    public static void main(String [] args) {
        BinaryTreeFromSortedArray bst = new BinaryTreeFromSortedArray();
        int arr[] = {7,6,5,4,3,2,1};
        Arrays.sort(arr);
        int n = arr.length;
        root = bst.arrToBST(arr, 0, n-1);
        System.out.println("Preorder traversa of BST: ");
        bst.preOrder(root);
        System.out.print("\n");
    }
}