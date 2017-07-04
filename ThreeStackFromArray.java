/*
Create 3 stacks from an array
*/

import java.util.*;
import java.io.*;

public class ThreeStackFromArray {

	private int numberOfStacks = 3;
	private int stackCapacity;
	private int[] values;
	private int[] sizes;

	public ThreeStackFromArray(int stackSize) {
		stackCapacity = stackSize;
		values = new int[stackSize * numberOfStacks];
		sizes = new int[numberOfStacks];
	}
	public void push(int stackNum, int value) {
		if(isFull(stackNum)) {
			return;
		}
		sizes[stackNum]++;
		values[indexOfTop(stackNum)] = value;
	}

	public int pop(int stackNum) {
		if(isEmpty(stackNum)){
			return 0;
		}
		int topIndex = indexOfTop(stackNum);
		int value = values[topIndex];
		values[topIndex] = 0; // Clear
		sizes[stackNum]--; // Shrink
		return value;
	}

	// Return top element
	public int peek(int stackNum) {
		if(isEmpty(stackNum)) {
			return 0;
		}
		return values[indexOfTop(stackNum)];
	}

	// Return if stack is empty
	public boolean isEmpty(int stackNum) {
		return sizes[stackNum] == 0;
	}

	public boolean isFull(int stackNum) {
		return sizes[stackNum] == stackCapacity;
	}

	private int indexOfTop(int stackNum) {
		int offset = stackNum * stackCapacity;
		int size = sizes[stackNum];
		return offset + size - 1;
	}

	public static void main(String[] args) {
		ThreeStackFromArray stack = new ThreeStackFromArray(3);
		stack.push(0,1);
		stack.push(1,2);
		stack.push(2,3);

		System.out.println(stack.peek(0));
		System.out.println(stack.peek(2));
	}
}