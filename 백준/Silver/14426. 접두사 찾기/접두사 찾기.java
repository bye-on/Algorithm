import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
	static class TrieNode {
		Map<Character, TrieNode> node;
		boolean endOfWord;
		
		public TrieNode() {
			this.node = new HashMap<>();
			this.endOfWord = false;
		}
	}
	
	static class trie {
		TrieNode root = new TrieNode();
		
		void insert(String str) {
			TrieNode child = root;
			
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
				if(child.node.containsKey(c)) {
					child = child.node.get(c);
				}
				else {
					child.node.put(c, new TrieNode());
					child = child.node.get(c);
				}
			}
			
			child.endOfWord = true;
		}
		
		boolean search(String str) {
			TrieNode child = root;
			
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
				if(child.node.containsKey(c)) {
					child = child.node.get(c);
				}
				else {
					return false;
				}
			}
			
			return true;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		trie strTrie = new trie();
		
		String[] NM = br.readLine().split(" ");
		int N = Integer.parseInt(NM[0]);
		int M = Integer.parseInt(NM[1]);
		
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			strTrie.insert(str);
		}
		
		int result = 0;
		for (int i = 0; i < M; i++) {
			String str = br.readLine();
			if(strTrie.search(str))
				result++;
		}
		
		System.out.println(result);
	}
}
