import java.util.*;
import java.io.*;
import java.math.*;
import java.util.regex.Pattern;
import java.nio.charset.Charset;

class FastIn{
	private final int buf_sz;
	private DataInputStream istream;
	private byte[] buf;
	private int p_buf, len;

	public FastIn(int buf_sz){
		this.buf_sz = buf_sz;
		istream = new DataInputStream(System.in);
		buf = new byte[buf_sz];
		p_buf = 0;
		len = 0;
	}

	private void fillBuf() throws IOException {
		len = istream.read(buf, p_buf = 0, buf_sz);
		if (len == -1) {
			buf[0] = -1;
			len = 1;
		}
	}

	private byte read() throws IOException {
		if (p_buf >= len) fillBuf();
		return buf[p_buf++];
	}

	public long readLong() throws IOException {
		long res = 0;
		byte b;
		do b = read(); while (b <= ' ');
		boolean neg = (b == '-');
		if (neg) b = read();
		while (0x30 <= b && b <= 0x39){
			res = res * 10 + (b - 0x30);
			b = read();
		}
		return neg ? -res : res;
	}
}

class FastOut{
	private final int buf_sz;
	private DataOutputStream ostream;
	private byte[] buf;
	private int p_buf;

	public FastOut(int buf_sz){
		this.buf_sz = buf_sz;
		ostream = new DataOutputStream(System.out);
		buf = new byte[buf_sz];
		p_buf = 0;
	}

	public void writeLong(long x) throws IOException {
		if (p_buf + 20 >= buf_sz) flush();
		if (x < 0) {
			buf[p_buf++] = '-';
			x = -x;
		}
		int start = p_buf;
		do {
			buf[p_buf++] = (byte) ('0' + x % 10);
		} while ((x/=10) > 0);
		for (int i = start, j = p_buf - 1; i < j; i++, j--) {
			byte temp = buf[i];
			buf[i] = buf[j];
			buf[j] = temp;
		}
	}

	public void write(final byte[] s) throws IOException {
		for (int i = 0; i < s.length; i++) {
			if (p_buf >= buf_sz) flush();
			buf[p_buf++] = s[i];
		}
	}

	public void flush() throws IOException {
		if (p_buf > 0) {
			ostream.write(buf, 0, p_buf);
			p_buf = 0;
		}
	}
}

class pair<T, U>{
	public T first;
	public U second;

	public pair(T first, U second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public String toString() {
		return "(" + first + ", " + second + ")";
	}
}

public class a{
	public static void main(String[] args){
		try{
			FastIn fin = new FastIn(1 << 20);
			FastOut fout = new FastOut(1 << 20);
			// fout.write("Hello, World!".getBytes(Charset.forName("UTF-8")));

			int n = (int)fin.readLong();

			LinkedList<Integer>[] a = new LinkedList[n];
			for(int i = n; i-->0;) 
				a[i] = new LinkedList<>();

			for(int i=n-1; i-->0;){
				int x = (int)fin.readLong();
				int y = (int)fin.readLong();
				--x; --y;
				a[x].add(y);
				a[y].add(x);
			}

			int[] r = new int[n];
			boolean[] v = new boolean[n];
			LinkedList<pair<Integer, Integer>> q = new LinkedList<>();

			v[0] = true;
			q.add(new pair<>(0, 0));

			while(q.size() > 0){
				pair<Integer, Integer> cur = q.poll();

				r[cur.first] = cur.second;

				for(int i : a[cur.first]){
					if(v[i]) continue;
					v[i] = true;
					q.add(new pair<>(i, cur.first));
				}
			}

			for(int i=1; i<n; ++i){
				fout.writeLong(r[i] + 1);
				fout.write(new byte[]{'\n'});
			}

			fout.flush();
		}catch (Exception e){
		}

	}
}
