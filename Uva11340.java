import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

class Uva11340 {

    public static DecimalFormat df = new DecimalFormat("0.00");

    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        for (int i = 0; i < n; i++) {
            int k = Integer.parseInt(bf.readLine());
            Map<Character, Integer> charValues = new HashMap<Character, Integer>();
            for (int j = 0; j < k; j++) {
                StringTokenizer st = new StringTokenizer(bf.readLine());
                char c = st.nextToken().charAt(0);
                int value = Integer.parseInt(st.nextToken());
                charValues.put(c, value);
            }
            int m = Integer.parseInt(bf.readLine());
            long total = 0;
            for (int z = 0; z < m; z++) {
                String line = bf.readLine();
                for (int ch = 0; ch < line.length(); ch++) {
                    if (charValues.containsKey(line.charAt(ch))) {
                        total += charValues.get(line.charAt(ch));
                    }
                }
            }

            System.out.println(df.format(total / 100.0) + "$");
        }
    }
}
