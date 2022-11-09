
import java.util.HashMap;

public final class Solution {

	private int id;
    
	private String name;
    
	private HashMap<String,String> testMap;
    
	public int getId() {
    	return id;
	}


	public String getName() {
    	return name;
	}

	public HashMap<String, String> getTestMap() {
    	return new HashMap<>(testMap);
	}
    
    
	public Solution(int i, String n, HashMap<String,String> hm){
    	this.id=i;
    	this.name=n;
    	this.testMap=new HashMap<>(hm);
	}


	public static void main(String[] args) {
    	HashMap<String, String> h1 = new HashMap<String,String>();
    	h1.put("1", "first");
    	h1.put("2", "second");
   	 
    	String s = "original";
   	 
    	int i=10;
   	 
    	Solution ce = new Solution(i,s,h1);
   	 
    	System.out.println(s==ce.getName()); // true
    	System.out.println(h1 == ce.getTestMap()); // true

    	System.out.println("ce id:"+ce.getId()); // 10
    	System.out.println("ce name:"+ce.getName()); // original
    	System.out.println("ce testMap:"+ce.getTestMap()); // 1 2 
   	 
    	//change the local variable values
    	i=20;
    	s="modified";
    	h1.put("3", "third");
    	//print the values again
    	System.out.println("ce id after local variable change:"+ce.getId()); // 10
    	System.out.println("ce name after local variable change:"+ce.getName()); // original 
    	System.out.println("ce testMap after local variable change:"+ce.getTestMap()); // 1 2 
   	 
    	HashMap<String, String> hmTest = ce.getTestMap();
    	hmTest.put("4", "new");
   	 
    	System.out.println("ce testMap after changing variable from accessor methods:"+ce.getTestMap()); // 1 2 

	}
}

/*
table  = moives
col: movie_name (varchar), movie_type(varchar)

get 


kuck hot 	romantic
rrr      	action
ddlj		romantic

romantic 	2
action 		1


select movie_type, count(movie_name) as counting
from movies
group by movie_type
order by counting desc;


getapi()
movieName = /getrecommendedmovie, path 
return list of movieobjects

getApi{
	Input:
	movieName;
	Output:
	list<movie> movieObject;
}


list<movie> getApi(movieName);


@spring ??


providing reccomm
user search


vehicle : maruti, tata

Vechicle veh = new Maruti();

string str = "tata"


public interface Vehicle {
	getMilegae();
}

public Tata implement Vehicle {
	int id = "t";
	int getMileage() {
		return 20;
	}
}


public Maruti implement Vehicle {
	int id = "m";
	int getMileage() {
		return 10;
	}
}


public enum Vehicle {

}

getVehicleMileage(string str) {
	
}




*/