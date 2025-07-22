import java.io.*;
import java.util.*;

public class Main {
    private static final int MOD = 10000;

    public static int fibo(long n) {
        long m00 = 1, m01 = 1, m10 = 1, m11 = 0;
        long v0 = 1, v1 = 0;

        while (n > 0) {
            if ((n & 1) == 1) {
                long t0 = (m00 * v0 + m01 * v1) % MOD;
                long t1 = (m10 * v0 + m11 * v1) % MOD;
                v0 = t0;
                v1 = t1;
            }
            long a = (m00 * m00 + m01 * m10) % MOD;
            long b = (m00 * m01 + m01 * m11) % MOD;
            long c = (m10 * m00 + m11 * m10) % MOD;
            long d = (m10 * m01 + m11 * m11) % MOD;
            m00 = a; m01 = b;
            m10 = c; m11 = d;

            n >>= 1;
        }
        return (int) v1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Long> inputs = new ArrayList<>();
        String line;

        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (!line.isEmpty()) {
                inputs.add(Long.parseLong(line));
            }
        }
        if (!inputs.isEmpty()) {
            inputs.remove(inputs.size() - 1);
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (long n : inputs) {
            bw.write(fibo(n) + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}