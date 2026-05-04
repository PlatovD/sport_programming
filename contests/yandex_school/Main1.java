import java.io.*;
import java.util.*;

public class Main1 {

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
        int k = in.nextInt();

        Map<Character, PriorityQueue<Word>> wordsByFirstCh = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String wordStr = in.next();
            char firstChar = wordStr.charAt(0);
            Word word = new Word(wordStr);

            if (wordsByFirstCh.containsKey(firstChar)) {
                wordsByFirstCh.get(firstChar).add(word);
            } else {
                wordsByFirstCh.put(firstChar, new PriorityQueue<>());
                wordsByFirstCh.get(firstChar).add(word);
            }
        }

        for (int i = 0; i < k; i++) {
            char letter = in.next().charAt(0);
            PriorityQueue<Word> queue = wordsByFirstCh.get(letter);

            Word bestWord = queue.poll();
            out.println(bestWord.value);

            bestWord.usg++;
            queue.add(bestWord);
        }
    }

    static class Word implements Comparable<Word> {
        String value;
        int usg;

        Word(String value) {
            this.value = value;
            this.usg = 0;
        }

        @Override
        public int compareTo(Word other) {
            if (this.usg != other.usg) {
                return Integer.compare(this.usg, other.usg);
            }
            return this.value.compareTo(other.value);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Word word = (Word) obj;
            return Objects.equals(value, word.value);
        }

        @Override
        public int hashCode() {
            return Objects.hash(value);
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
