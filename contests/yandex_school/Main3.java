import java.io.*;
import java.util.*;

public class Main3 {

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        solve(in, out);
        out.close();
    }

    public static void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();

        List<Point> points = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = Math.abs(in.nextInt());
            int y = Math.abs(in.nextInt());
            points.add(new Point(x, y));
        }

        points.sort((a, b) -> {
            if (a.x != b.x) return Integer.compare(a.x, b.x);
            return Integer.compare(a.y, b.y);
        });

        List<Point> uq = new ArrayList<>();
        for (Point p : points) {
            while (!uq.isEmpty() && uq.get(uq.size() - 1).y <= p.y) {
                uq.remove(uq.size() - 1);
            }
            uq.add(p);
        }

        int m = uq.size();
        long[] dp = new long[m + 1];
        Arrays.fill(dp, Long.MAX_VALUE);
        dp[0] = 0;

//      пробую на каждом либо покрыть новым прямоугольником, либо достроить один из старых, увеличить его
        for (int i = 1; i <= m; i++) {
            long maxY = 0;
            for (int j = i; j >= 1; j--) {
                maxY = Math.max(maxY, uq.get(j - 1).y);
                long area = 4L * uq.get(i - 1).x * maxY;
                dp[i] = Math.min(dp[i], dp[j - 1] + area);
            }
        }

        out.println(dp[m]);
    }

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
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