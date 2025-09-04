import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
	static class TrieNode {
		Map<Integer, TrieNode> node;
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
				int n = str.charAt(i) - '0';
				
				if(!child.node.containsKey(n))
					child.node.put(n, new TrieNode());
				
				child = child.node.get(n);
			}
			
			child.endOfWord = true;
		}
		
		
		boolean search(String str) {
			TrieNode child = root;
			
			for (int i = 0; i < str.length(); i++) {
				int n = str.charAt(i) - '0';
				
				if(child.node.containsKey(n)) {
					child = child.node.get(n);
					
					if(child.endOfWord)
						return false;
				}
				else 
					return true;
			}
			
			return child.endOfWord;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			trie strTrie = new trie();
			int n = Integer.parseInt(br.readLine());
			
			boolean flag = false;
			for (int j = 0; j < n; j++) {
				String str = br.readLine();
				if(strTrie.search(str))
					strTrie.insert(str);
				else
					flag = true;
			}
			
			if(flag)
				sb.append("NO\n");
			else 
				sb.append("YES\n");
		}
		System.out.println(sb);
	}
}
