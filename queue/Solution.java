import java.util.Arrays;
import java.util.Random;

interface MyQueue<E> {
	public void clear();
	public void enqueue(E item);
	public E dequeue();
	public E front();
	public int length();
}

class AQueue<E> implements MyQueue<E> {
	private static int DEFAULT_CAPACITY = 10; 
	E[] data;
	int front, rear, size;
	
	public AQueue() {
		data = (E[]) new Object[DEFAULT_CAPACITY];
		front = 0;
		rear = 0;
        size = data.length;
	}
	
	/* Code here! */
    public void clear(){
        for(int i=0; i<data.length; i++){
            data[i] = null;
        }
        front = 0;
        rear = 0;
        size = 0;
    };
    
	public void enqueue(E item){
        //In case Queue is Full
        if(rear == data.length-1){
            data = Arrays.copyOf(data, data.length*2);
        }
        data[rear] = item;
        rear = (rear+1)%data.length;
        size = (size+1)%data.length;
    };
	public E dequeue(){
        if(front == rear) return null;
        
        E tmp = data[front];
        data[front] = null;
        front = (front+1)%data.length;
        size = (size-1)%data.length;
        
        return tmp;
    };
	public E front(){
        if(rear == 0) return null;
        else return data[front];
    };
	public int length(){
        return size;
    };
}

/* Do not modify codes below */
class Solution {
    public int solution(int[] nums) {
        AQueue<Integer> queue = new AQueue<>();

		int checksum = 0;

		for (int n : nums) {
			if(n >= 0) {
				queue.enqueue(n);
				checksum += n;
				checksum %= 7919;
			}
			else {
				int x = queue.dequeue();
				checksum += x;
				checksum %= 7919;
			}
			checksum += queue.length();
			checksum %= 7919;
		}
		
		checksum += queue.length();
		checksum %= 7919;
		
		queue.clear();
		checksum += queue.length();
		checksum %= 7919;

		return checksum;
    }
}