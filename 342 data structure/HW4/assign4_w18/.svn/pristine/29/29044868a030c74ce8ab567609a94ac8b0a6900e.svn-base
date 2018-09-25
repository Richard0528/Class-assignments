package mymaps;


import java.io.IOException;
import java.nio.file.Paths;
import java.util.Comparator;
import java.util.Date;
import java.util.Scanner;
import java.util.TreeMap;
    
/**
    Program to read in strings from a file
    and insert them into a dictionary.
    
    */
public class DictionaryAppComparatorTest {
       
    /**
     * The driver method to show natural and comparator usage.
     */
    public static void main(String[] args) {
        
        TreeMap<Integer, String> javaTreeMap1 = new TreeMap<Integer, String>();
        
        for (int i = 0; i < 30; i++)
        	javaTreeMap1.put((Integer) i, "str=" + i);
    
        
        System.out.println(javaTreeMap1);

        TreeMap<Integer, String> javaTreeMap2 = new TreeMap<Integer, String>(new MyComp());
        
        for (int i = 0; i < 30; i++)
        	javaTreeMap2.put((Integer) i, "str=" + i);
           
        System.out.println(javaTreeMap2);
    }
    
}
class MyComp implements Comparator<Integer> {
   public int compare(Integer x, Integer y) {
        return y-x;
   }
}
