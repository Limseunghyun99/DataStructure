import java.io.*;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.*;
import java.lang.String;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int treeNum = sc.nextInt();
        //Iterate for treeNum
        for(int i=0;i<treeNum;i++) {
        	PriorityQueue<Integer> newOne = new PriorityQueue<Integer>();
        	//Input Tree's Node Number;
        	int depth = sc.nextInt();
        	for(int a =0; a<depth; a++) {
        		String val = sc.next();
        		int fre = sc.nextInt();
        		newOne.add(fre);
        	}
        	int ext = 0;
        	while(newOne.size() > 1) {
        		int num1 = newOne.poll();
        		int num2 = newOne.poll();
        		int sum = num1+num2;
        		newOne.add(sum);
        		ext += sum;
        	}
        	//Print External path Weight
        	System.out.println(ext);
        }
    }
}