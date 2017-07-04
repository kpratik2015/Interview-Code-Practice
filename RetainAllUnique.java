import java.util.HashSet;
import java.util.HashSet;


public class RetainAllUnique {

	public static void main(String[] args) {

		int [] arr1 = {1, 3, 5, 7, 9};
		int [] arr2 = {1, 2, 5, 6, 9};
		
		HashSet <Integer> a1 = new HashSet<>();
		for(int i : arr1) a1.add(i);
		HashSet <Integer> a2 = new HashSet<>();
		for(int i : arr2) a2.add(i);
		
		HashSet <Integer> a1C = new HashSet<>(a1);
		HashSet <Integer> a2C = new HashSet<>(a2);
		
		a1C.removeAll(a2);
		a2C.removeAll(a1);
		
		HashSet <Integer> a3 = new HashSet<>();
		a3.addAll(a1C);
		a3.addAll(a2C);
		System.out.print("Set of Unique numbers: ");
		for(int i : a3)
			System.out.print("["+i+"]");
		System.out.println();
	}
}

/*
OUTPUT:
Set of Unique numbers: [2][3][6][7]
*/