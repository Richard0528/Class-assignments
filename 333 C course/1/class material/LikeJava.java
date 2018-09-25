public class LikeJava {


public static void main(String[] args) {

    int i = 1;
    
    System.out.print("HI\n");
    
    if (3 < 5) {
        System.out.print("A\n");    
    } else {
        System.out.print("B\n");
    }
    
    System.out.print("C\n");
    
    while (i < 4) {
        System.out.print("D\n");
        i++;
    }
    
    System.out.print("E\n");
    
    switch(3) {
       case 2:
           System.out.print("F\n");
           break;
       case 3:
           System.out.print("G\n");
       case 4:
           System.out.print("H\n");
           break;
       case 5:
           System.out.print("K\n");
           break;
    }
    
    System.out.print("L\n");
    
    for (i = 0; i < 4; i++) {
        System.out.print("M\n");
    }
    
    for (i = 0; i < 4; i++) {
        if (i % 2 == 0)
            continue;
        System.out.print(i + "N\n");
    }
    
    for (i = 0; i < 4; i++) {
        if (i % 2 == 0)
             break;
        System.out.print("O\n");
    }        
    
}

} // class 