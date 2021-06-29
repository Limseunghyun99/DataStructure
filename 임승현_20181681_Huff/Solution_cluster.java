import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    static int[] height, Nodes;
    public static void main(String[] args) throws IOException {
    	
        
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	int N = Integer.parseInt(st.nextToken());
    	int M = Integer.parseInt(st.nextToken());
    	
        int ans = 0;

        height = new int [N];
        Nodes = new int[N];
        
        //Initialize
        for(int i=0; i<N;++i){
        	height[i] = 1;
        	Nodes[i] = i;
    	}

		for (int i = 0; i < M; i++) {
			StringTokenizer st2 = new StringTokenizer(br.readLine());
    		int u = Integer.parseInt(st2.nextToken());
    		int v = Integer.parseInt(st2.nextToken());
    		union(u,v);
    	}
    	for(int j=0; j<N;j++) {
    		if(Nodes[j] == j) ans += 1;
    	}
    	br.close();
    	/*
        for(int i=0; i<N;++i){
        	System.out.println("Height Is");
        	System.out.println(height[i]);
        	System.out.println(Nodes[i]);
    	}
    	*/
    	
        System.out.println(ans);
    }
    public static void union(int u, int v) {
    	//u's root
    	u = find(u);
    	//v's root
    	v = find(v);
    	if(u == v) return;
    	//In case v's Height is higher than u
    	if(height[u] < height[v]) {
    		//swap
    		int tmp = 0;
    		tmp = u;
    		u = v;
    		v = tmp;
    	}
    	//In case Height is same, ++
    	//Linking
    	Nodes[v] = u;
    	if(height[u] == height[v]) height[u]++;
    	
    	
    }
    
    public static int find(int input) {
    	if(Nodes[input] == input) return input;
		Nodes[input] = find(Nodes[input]);
    	return Nodes[input];
    	}
    }




