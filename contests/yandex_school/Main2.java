import java.io.*;
import java.util.*;

public class Main2 {
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

        String[] firstSeq = new String[n];
        for (int i = 0; i < n; i++) firstSeq[i] = in.next();

        String[] secondSeq = new String[n];
        for (int i = 0; i < n; i++) secondSeq[i] = in.next();

        Map<String, Node> nodes = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String s1 = firstSeq[i];
            String s2 = secondSeq[i];

            boolean isNum1 = Character.isDigit(s1.charAt(0));
            boolean isNum2 = Character.isDigit(s2.charAt(0));

            if (isNum1 && isNum2) {
                if (!s1.equals(s2)) {
                    out.println("NO");
                    return;
                }
            } else if (!isNum1 && !isNum2) {
                Node node1 = nodes.computeIfAbsent(s1, k -> new Node());
                Node node2 = nodes.computeIfAbsent(s2, k -> new Node());
                node1.connected.add(node2);
                node2.connected.add(node1);
            } else {
                String varName = isNum1 ? s2 : s1;
                int val = Integer.parseInt(isNum1 ? s1 : s2);
                Node node = nodes.computeIfAbsent(varName, k -> new Node());

                if (node.value != null && node.value != val) {
                    out.println("NO");
                    return;
                }
                node.value = val;
            }
        }

        for (Node startNode : nodes.values()) {
            if (!startNode.viewed) {
                Integer componentValue = null;
                Stack<Node> stack = new Stack<>();
                stack.push(startNode);

                while (!stack.isEmpty()) {
                    Node curr = stack.pop();
                    if (curr.viewed) continue;

                    curr.viewed = true;

                    if (curr.value != null) {
                        if (componentValue == null) {
                            componentValue = curr.value;
                        } else if (!componentValue.equals(curr.value)) {
                            out.println("NO");
                            return;
                        }
                    }

                    for (Node neighbor : curr.connected) {
                        if (!neighbor.viewed) {
                            stack.push(neighbor);
                        }
                    }
                }
            }
        }

        out.println("YES");
    }


    static class Node {
        Integer value = null;
        List<Node> connected = new ArrayList<>();
        boolean viewed = false;

        public Node() {
        }

        public Node(int value) {
            this.value = value;
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

        String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}