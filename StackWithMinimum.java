import java.io.*;
import java.util.*;

// extending functionality of Stack to find minimum in a stack
// in O(1) time.
class StackWithMinimum extends Stack<Integer>{

	Stack<Integer> s2;

	public StackWithMinimum() {
		s2 = new Stack<Integer>();
	}

	public void push(int value) {
		if(value <= min()) {
			// push the new minimum value on our minimum stack
			s2.push(value);	
		}
		// call the original push method
		super.push(value);
	}

	public Integer pop() {
		int value = super.pop();
		// pop the minimum value as this value 
		// has been removed from original stack
		if(value == min()) {
			s2.pop();	
		}
		return value;
	}

	public int min() {
		if(s2.isEmpty()) {
			return Integer.MAX_VALUE;
		}
		else {
			return s2.peek();
		}
	}

	public static void main(String []args){

		StackWithMinimum obj = new StackWithMinimum();

		obj.push(10);
		obj.push(24);
		obj.push(8);
		obj.push(23);
		obj.push(5);
		obj.pop();

		System.out.println(obj.min());

	}

}