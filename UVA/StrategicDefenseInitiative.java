import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;

class Main {
	public static void solve(ArrayList<Integer> correct,
			ArrayList<Integer> possible) {
		int n = correct.size();
		int LCS[][] = new int[n + 1][n + 1];
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (correct.get(i) == possible.get(j))
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				else
					LCS[i][j] = Math.max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
		StringBuilder stringBuilder = new StringBuilder();
		stringBuilder.append("Max hits: ").append(LCS[n-1][n-1]).append('\n');
		int i = n-1, j = n-1;
		Stack<Integer> backtrack = new Stack<>();
		while (LCS[i][j] != 0) {
			if (correct.get(i) == possible.get(j)) {
				backtrack.add(correct.get(i));
				i--;
				j--;
			} else {
				if (LCS[i - 1][j] > LCS[i][j - 1])
					i--;
				else
					j--;
			}
		}
		while(!backtrack.isEmpty())
			stringBuilder.append(backtrack.pop()).append('\n');
		System.out.print(stringBuilder);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int c = Integer.parseInt(in.readLine());
		in.readLine();
		while (c-- > 0) {
			String line;
			ArrayList<Integer> possible = new ArrayList<>();
			possible.add(Integer.MIN_VALUE);
			while (!(line = in.readLine()).isEmpty()) {
				possible.add(Integer.valueOf(line));
			}
			
			ArrayList<Integer> correct = new ArrayList<>(possible);
			Collections.sort(correct);
			solve(correct, possible);
			if(c!=0)
				System.out.println();
		}
	}

}
