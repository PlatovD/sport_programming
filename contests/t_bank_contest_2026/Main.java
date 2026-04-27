import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        solve(in, out);
        out.close();
    }

    public static void solve(InputReader in, PrintWriter out) {
        int a = in.nextInt();
        int b = in.nextInt();
        int n = in.nextInt();

        int[][] candidates = new int[n][2];
        for (int i = 0; i < n; i++) {
            candidates[i][0] = in.nextInt();
            candidates[i][1] = in.nextInt();
        }

        Arrays.sort(candidates, (p1, p2) ->
                Integer.compare(p2[0] - p2[1], p1[0] - p1[1])
        );

        long[] prefix = new long[n + 1];
        PriorityQueue<Integer> queueBack = new PriorityQueue<>();
        long sumX = 0;
        for (int i = 0; i < n; i++) {
            int x = candidates[i][0];
            sumX += x;
            queueBack.add(x);
            if (queueBack.size() > a) {
                int min = queueBack.poll();
                sumX -= min;
            }
            prefix[i + 1] = sumX;
        }

        long[] suffix = new long[n + 2];
        PriorityQueue<Integer> queueML = new PriorityQueue<>();
        long sumY = 0;
        for (int i = n - 1; i >= 0; i--) {
            int y = candidates[i][1];
            sumY += y;
            queueML.add(y);
            if (queueML.size() > b) {
                int min = queueML.poll();
                sumY -= min;
            }
            suffix[i] = sumY;
        }

        long ans = 0;
        for (int i = a; i <= n - b; i++) {
            ans = Math.max(ans, prefix[i] + suffix[i]);
        }

        out.println(ans);
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}