import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws IOException {

		PriorityQueue<Integer> pq = new Heap<Integer>();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String line;
		while((line = br.readLine()) != null) {
			StringTokenizer st = new StringTokenizer(line);
			String operation = st.nextToken().strip();
			
			Integer k;
			switch(operation) {
				case "insert":
					k = Integer.parseInt(st.nextToken());
					pq.insert(k);
					break;
				case "removemax":
					k = pq.removeMax();
					if(k != null)
						System.out.println("Removed value: " + k);
					break;
				case "getmax":
					k = pq.getMax();
					if(k != null)
						System.out.println("Found value: " + k);
					break;
				case "size":
					System.out.println("PQ size: " + pq.size());
					break;
				case "clear":
					System.out.println(pq);
					pq.clear();
					System.out.println("PQ is initialized.");
					break;
			}
			
		}
		
		
		br.close();
	}
}

interface PriorityQueue<E>{
	public void insert(E e);
	public E removeMax();
	public E getMax();
	public int size();
	public void clear();
}

class Heap<E extends Comparable<E>> implements PriorityQueue<E>{

	final int DEFAULT_CAPACITY = 10;
	E[] data;
	int size;
	
	private int parent(int pos) {
		return (pos-1)/2;
	}
	
	private int leftchild(int pos) {
		return pos * 2 + 1;
	}
	
	private int rightchild(int pos) {
		return pos * 2 + 2;
	}
	
	private boolean isleaf(int pos) {
		return pos * 2 + 1 >= size && pos < size;
	}
	
	public Heap(E[] data) {
		size = data.length;
		for(int i=size/2-1; i>=0; i--) {
			siftdown(i);
		}
	}
	
	public Heap() {
		data = (E[]) new Comparable[DEFAULT_CAPACITY];
		size = 0;
	}
	
	public String toString() {
		return Arrays.toString(Arrays.copyOf(data, size)); 
	}
    
    /* code here! */
    public void insert(E e){
        //If Data Array has no spare address
        if(size + 1 >= data.length) data = Arrays.copyOf(data, data.length*2);
        //insert input at data[size]
        data[size] = e;
        //save size value & increase size
        int tmp = size++;
        // size is no zero && data[tmp] is bigger than parent
        while(tmp != 0 && data[tmp].compareTo(data[parent(tmp)]) > 0){
            //System.out.println("This Part is Insert");
            //Swap data[tmp] <-> parent
            E foo = data[tmp];
            data[tmp] = data[parent(tmp)];
            data[parent(tmp)] = foo;
            tmp = parent(tmp);
        }
    }
	public E removeMax(){
        //In Case Tree is Empty!
        if(size == 0) return null;
        //In Case Tree has only root!
        else if(size == 1){
            size = 0;
            return data[0];
        }
        //In Case Tree has more than 2 nodes.
        else{
            //save tmp for return;
            E tmp = data[0];
            //set Root with last node
            size--;
            data[0] = data[size];
            siftdown(0);
            return tmp;
        }
        
    }
	public E getMax(){
        //In Case Tree is Empty
        if(size == 0) return null;
        return data[0];
    }
    private void siftdown(int position){
        int tmp = position;
        //left child
        int left = leftchild(tmp);
        //right child
        int right = rightchild(tmp);
        
        //Until reach to Leaf Node
        while(!isleaf(tmp)){
            //for Comparing left and right
            int bigOne;
            //In Case left is bigger than right one
            if(data[left].compareTo(data[right])>0) bigOne = left;
            //In Case right is bigger than left one
            else bigOne = right;
            
            //if data[tmp] is bigger or same with bigOne, stop
            if(data[tmp].compareTo(data[bigOne]) >= 0) break;
            //swap
            else{
                E foo = data[tmp];
                data[tmp] = data[bigOne];
                data[bigOne] = foo;
                tmp = bigOne;
            }
            //Update Left Child with latest tmp
            left = leftchild(tmp);
            //Update Right Child with latest tmp
            right = rightchild(tmp);
        }
        
    }
	public int size(){
        return size;
    }
	public void clear(){
        size = 0;
        data[0] = null;
    }
}