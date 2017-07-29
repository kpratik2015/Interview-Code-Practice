import java.util.*;
import java.io.*;

/*

For HashSet:
	- This class makes no guarantees as to the iteration order of the set; 
		in particular, it does not guarantee that the order will remain constant over time.
	- This class permits the null element.

** A LinkedHashSet maintains insertion order. **

*/

public class MutualExclusionString {
	public static void main(String[] args) {
		char[] str1 ={ 'h', 'H', 'c', 'z', 'e' }; 
		char[] str2 ={ 'k', 'p', 'o', 't', 'e' };

		// To show this is possible
		String toString1 = String.valueOf(str1);
		String toString2 = String.valueOf(str2);
		System.out.println("Given two character arrays: "+toString1+" & "+toString2);

		System.out.println("The conversion to 0-25 number depending on character for str1: ");

		for(int i = 0 ; i < str1.length ; i++) {
			System.out.print(Character.toLowerCase(str1[i])-'a'+" ");
		}

		System.out.println();

		LinkedHashSet<Character> a1 = new LinkedHashSet<>();
		LinkedHashSet<Character> a2 = new LinkedHashSet<>();

		for(char c : str1){
			a1.add(c);
		}

		for(char c : str2){
			a2.add(c);
		}

		LinkedHashSet <Character> a1C = new LinkedHashSet<>(a1);
		LinkedHashSet <Character> a2C = new LinkedHashSet<>(a2);
		
		a1C.removeAll(a2);
		a2C.removeAll(a1);

		LinkedHashSet <Character> a3 = new LinkedHashSet<>();
		a3.addAll(a1C);
		a3.addAll(a2C);

		System.out.println("Elimination Commons and concatenating: ");

		for(char c : a3){
			System.out.print(c);
		}

		System.out.println();

	}
}