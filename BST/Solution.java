import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	public static void main(String[] args) throws IOException {
		
		Dictionary<Integer, String> dict = new BST<>();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String line;
		while((line = br.readLine()) != null) {
			StringTokenizer st = new StringTokenizer(line);
			String operation = st.nextToken().strip();
			
			int k;
			String v;
			switch(operation) {
				case "insert":
					k = Integer.parseInt(st.nextToken());
					v = st.nextToken().strip();
					dict.insert(k, v);
					break;
				case "remove":
					k = Integer.parseInt(st.nextToken());
					v = dict.remove(k);
					if(v != null)
						System.out.println("Removed value: " + v);
					break;
				case "find":
					k = Integer.parseInt(st.nextToken());
					v = dict.find(k);
					if(v != null)
						System.out.println("Found value: " + v);
					break;
				case "size":
					System.out.println("Dict size: " + dict.size());
					break;
				case "clear":
					System.out.println(inorder(((BST<Integer, String>) dict).root));
					System.out.println(preorder(((BST<Integer, String>) dict).root));
					dict.clear();
					System.out.println("Dict is initialized.");
					break;
			}	
		}
		
		br.close();
	
	}
	
	public static <K, V> String inorder(BinNode<K, V> rt){
		String ret = "";
		
		if(rt == null) return ret;
		
		ret += inorder(rt.left);
		ret += rt.key + ": " + rt.value + "\n";
		ret += inorder(rt.right);
		
		return ret;
	}
	
	public static <K, V> String preorder(BinNode<K, V> rt){
		String ret = "";
		
		if(rt == null) return ret;
		
		ret += rt.key + ": " + rt.value + "\n";
		ret += inorder(rt.left);
		ret += inorder(rt.right);
		
		return ret;
	}
	
}

interface Dictionary<K, V>{
	public void clear();
	public void insert(K k, V v);
	public V remove(K k);
	public V find(K k);
	public int size(); 
}

class BinNode<K, V> {
	public K key;
	public V value;
	public BinNode<K, V> left;
	public BinNode<K, V> right;
	public BinNode(K key, V value, BinNode<K, V> left, BinNode<K, V> right){
		this.key = key;
		this.value = value;
		this.left = left;
		this.right = right;
	}
}

class BST<K extends Comparable<K>, V> implements Dictionary<K, V>{

	BinNode<K, V> root;
	int size;
	
	public BST() {
		size = 0;
	}
	
	public V find(K k) {
		return find_helper(k, root);
	}
	
	private V find_helper(K k, BinNode<K, V> rt) {
		if(rt == null) {
			return null;
		}
		else {
			if(k.compareTo(rt.key) < 0)
				return find_helper(k, rt.left);
			else if(k.compareTo(rt.key) > 0)
				return find_helper(k, rt.right);
			else
				return rt.value;
		}
	}

	/* code here! */
    public int size(){
        return size;
    }
    public void clear(){
        root = null;
        size = 0;
    }
    public void insert(K k, V v){
        //Call Insert_Logic Recursively
        root = insert_logic(root,k,v);
        //Increase Size
        size++;
    }
    //Recursive Func
    public BinNode <K, V> insert_logic(BinNode<K, V> rt, K k, V v){
        //In Case Input Node is null -> Leaf
        // Create and return new BinNode Object 
        if(rt == null){
            return new BinNode<K, V>(k,v,null,null); 
        }
        //If Key Value is already exist, Update Value & Decrease size
        else if(k.compareTo(rt.key)==0){
            rt.value = v;
            size--;
        }
        //if input is smaller than key value, move to left and call Recursive Func
        else if(k.compareTo(rt.key)<0) rt.left = insert_logic(rt.left, k, v);
        //If Input is bigger than key, move to right and call Recursive func
        else rt.right = insert_logic(rt.right, k, v);
        return rt;
    }
    public V remove(K k){
        //Call Find Function
        V tmp = find_helper(k, root);
        //if return value is null, There is no key
        if(tmp==null) return null;
        //If Key Value is exist, Call Recursive Func
        else root = remove_logic(k, root);
        //Decrease Size, Because Node is deleted
        size--;
        //return Deleted Node's Value
        return tmp;
    }
    //Get Min Value
    public BinNode<K,V> MIN(BinNode<K,V> input){
        //If Left is empty -> Current Node is Min Value
        if(input.left == null) return input;
        //In Case there's smaller value
        else return MIN(input.left);
    }
    
    public BinNode<K,V> DEL(BinNode<K,V> input){
        //InCase left Node is Empty, return Right Node
        if(input.left == null) return input.right;
        //InCase right Node is empty, return input Value
        else input.left = DEL(input.left);return input;
    }
    
    //Delete Logic
    public BinNode<K, V> remove_logic(K k, BinNode<K,V> rt){
        //Incase input node is null, return null
        if(rt==null) return null;
        //InCase input node is smaller than key, move to left and call Recursive Func
        else if(k.compareTo(rt.key)<0) rt.left = remove_logic(k, rt.left);
        //InCase input node is bigger than key, move to right and call Recursive Func
        else if(k.compareTo(rt.key)>0) rt.right = remove_logic(k, rt.right);
        //InCase Key Value is Same
        else{
            //In Case left is null, return right
            if(rt.left == null) return rt.right;
            //In Case Right is empty, return left
            else if(rt.right == null) return rt.left;
            else{
                BinNode<K, V> tmp = MIN(rt.right);
                rt.value = tmp.value;
                rt.key = tmp.key;
                rt.right = DEL(rt.right);
            }
        }
        return rt;
    }
}