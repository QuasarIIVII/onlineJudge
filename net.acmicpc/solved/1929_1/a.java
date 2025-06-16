import java.util.*;
import java.io.*;
import java.math.*;
import java.util.regex.Pattern;

public class a{
	public static void main(String[] argv){
		Scanner sc = new Scanner(System.in);

		boolean[] a = new boolean[1_000_001];
		a[1] = true;

		for(int i=2; i*i <= 1_000_000; ++i){
			if(a[i]) continue;
			for(int j=i*2; j <= 1_000_000; j += i)
				a[j] = true;
		}

		int p = sc.nextInt(), q = sc.nextInt();
		StringBuilder sb = new StringBuilder();

		for(int i=p; i <= q; ++i){
			if(!a[i])
				sb.append(i).append('\n');
		}

		System.out.print(sb);
	}
}
