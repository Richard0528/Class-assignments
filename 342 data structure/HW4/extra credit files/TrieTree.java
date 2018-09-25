package treemap;

import java.util.ArrayList;
import java.util.List;

public class TrieTree<AnyKey, AnyValue> {
	
    private TrieNode<AnyKey, AnyValue> root;
 
    public TrieTree() {
        root = new TrieNode<AnyKey, AnyValue>(null, null);
    }
 
    // Inserts key-value into the trie.
    public void put(AnyKey[] keys, AnyValue value) {
    	// write the code
    }
 
    // Returns if the key is in the trie.
    public AnyValue get(AnyKey[] akey) {
        TrieNode<AnyKey, AnyValue> t = searchNode(akey);
 
        if (t != null && t.isEntry) 
            return t.v;
        else
            return null;
    }
 
    // returns the address of the node containing the end of the entry
    // null if entry is not in the trie
    private TrieNode<AnyKey, AnyValue> searchNode(AnyKey[] akey){
        
        TrieNode<AnyKey, AnyValue> t, node;
        t = node = root;
        AnyKey key;
        for(int i = 0; i < akey.length; i++){
            key = akey[i];
            t = node.containsKey(key);
            if (t == null)
            	return null;
            node = t;
        } 
        if (t.isEntry)
        	return t;
        else
        	return null;
    }
    
    // replace with toString method
    public void printTrie() {
        TrieNode<AnyKey, AnyValue> p = root;
         
        StringBuffer sb = new StringBuffer();
        printTrieHelper(p, sb);
    }
     
    private void printTrieHelper(TrieNode<AnyKey, AnyValue> p, StringBuffer sb) {
        if (p == null) {
            return;
        }
         
        if (p.isEntry) {
            System.out.println(sb.toString() + p.v);
        }
         
        for (int i = 0; i < p.children.size(); i++) {
            if (p.children.get(i) != null) {
                char c = (char) p.children.get(i).k;
                sb.append(c);
                printTrieHelper(p.children.get(i), sb);
                sb.deleteCharAt(sb.length() - 1);
            }
        }
    }
    
    private class TrieNode<AnyKey, AnyValue> {
        AnyKey k;
        AnyValue v;
        boolean isEntry;
        List<TrieNode<AnyKey, AnyValue>> children;
     
        public TrieNode(AnyKey key, AnyValue val){
            this.k = key;
            this.v = val;
            this.isEntry = false;
            children = new ArrayList<TrieNode<AnyKey, AnyValue>>();
        }
        
        // checks if any of the children contain the key; returns the address of the child
        // if found, null otherwise
        public TrieNode<AnyKey, AnyValue> containsKey(AnyKey key) {
        	for (int i = 0; i < children.size(); i++)
        		if (children.get(i).k.equals(key))
        			return children.get(i);
        	return null;
        }
        
        public void append(TrieNode<AnyKey, AnyValue> newNode) {
        	children.add(newNode);
        }
        
        public void setEntry(AnyValue val) {
        	isEntry = true;
        	v = val;
        }
    }
}