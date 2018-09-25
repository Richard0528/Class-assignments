/**
 * 
 */
package model;

import static org.junit.Assert.*;

import java.math.BigDecimal;
import org.junit.Before;
import org.junit.Test;

/**
 * @author richardyang
 * @version 10.18
 */
public class ItemTest {

    
    // Create the objects I will use in the tests.
    /** A Item to use in the tests. */
    private Item myItem1;
    
    /** Another Item to use in the tests. */
    private Item myItem2;
    
    /**
     * A method initialize the test fixture before each test.
     */
    @Before
    public void setUp() { // no need to throw any exceptions
        
        // myItem1 to test the first constructor
        myItem1 = new Item("Richard's Macbook", new BigDecimal("1999.9"));
        
        // myItem2 to test the second constructor
        myItem2 = new Item("Richard's Iphone", new BigDecimal("424.24"), 10, 
                           new BigDecimal("2244.24"));
    }

    /**
     * Test method for {@link model.Item#hashCode()}.
     */
    @Test
    public void testHashCode() {
        
        final Item itm3 = new Item("Richard's Iphone", new BigDecimal("424.24"), 10, 
                                new BigDecimal("2244.24"));
        
        assertEquals(itm3.hashCode(), myItem2.hashCode());
    }

    /**
     * Test of the overload constructor.
     */
    @Test
    public void testOverloadConstructor1() {
        
        final Item itm1 = new Item("Silly", new BigDecimal("4.41"), 
                                   6, new BigDecimal("10.04"));
        
        assertEquals("Silly", itm1.getName());
        assertEquals(new BigDecimal("4.41"), itm1.getPrice());
        assertEquals(6, itm1.getBulkQuantity());
        assertEquals(new BigDecimal("10.04"), itm1.getBulkPrice());
    }
    
    /**
     * Test of the overload constructor.
     */
    @Test
    public void testOverloadConstructor2() {
        
        final Item itm2 = new Item("Silly", new BigDecimal("4.41"));
        
        assertEquals("Silly", itm2.getName());
        assertEquals(new BigDecimal("4.41"), itm2.getPrice());
    }
    
    /**
     * Test method for {@link model.Item#getName()}.
     */
    @Test
    public void testGetName() {
        
        assertEquals("Richard's Iphone", myItem2.getName());      
    }

    /**
     * Test method for {@link model.Item#getPrice()}.
     */
    @Test
    public void testGetPrice() {
        
        assertEquals(new BigDecimal("1999.9"), myItem1.getPrice());
    }

    /**
     * Test method for {@link model.Item#getBulkQuantity()}.
     */
    @Test
    public void testGetBulkQuantity() {
        
        assertEquals(10, myItem2.getBulkQuantity());
    }

    /**
     * Test method for {@link model.Item#getBulkPrice()}.
     */
    @Test
    public void testGetBulkPrice() {
        
        assertEquals(new BigDecimal("2244.24"), myItem2.getBulkPrice());
    }

    /**
     * Test method for {@link model.Item#isBulk()}.
     */
    @Test
    public void testIsBulk1() {
        
        assertEquals(false, myItem1.isBulk());
    }
    
    /**
     * Test method for {@link model.Item#isBulk()}.
     */
    @Test
    public void testIsBulk2() {
        
        assertEquals(true, myItem2.isBulk());
    }
    

    /**
     * Test method for {@link model.Item#toString()}.
     */
    @Test
    public void testToString1() {
        
        assertEquals("toString() produced an unexpected result!", 
                     "Richard's Macbook, $1999.9", myItem1.toString());
    }
    
    /**
     * Test method for {@link model.Item#toString()}.
     */
    @Test
    public void testToString2() {
        
        assertEquals("toString() produced an unexpected result!", 
                     "Richard's Iphone, $424.24 (10 for $2244.24)", 
                     myItem2.toString());
    }

    /**
     * Test method for {@link model.Item#equals(java.lang.Object)}.
     */
    @Test
    public void testEqualsObject1() {
        
        final Item itmNew = myItem2;
        
        assertEquals(itmNew, myItem2);
    }
    
    /**
     * Test method for {@link model.Item#equals(java.lang.Object)}.
     */
    @Test
    public void testEqualsObject11() {
        
        final Item itmNew = new Item("Richard's Macbook", new BigDecimal("1999.9"));
        
        assertEquals(itmNew, myItem1);
    }
    
    /**
     * Test method for {@link model.Item#equals(java.lang.Object)}.
     */
    @Test
    public void testEqualsObject2() {
        
        assertNotEquals(myItem2, null);
    }
    
    /**
     * Test method for {@link model.Item#equals(java.lang.Object)}.
     */
    @Test
    public void testEqualsObject3() {
        
        final Item itmNew = new Item("Richard's Iphone", new BigDecimal("424.24"), 10, 
                                     new BigDecimal("2244.24"));
        
        assertEquals(myItem2, itmNew);
    }
    
    /**
     * Test method for {@link model.Item#equals(java.lang.Object)}.
     */
    @Test
    public void testEqualsObject31() {
        
        final Item itmNew = new Item("Richard's Macbook", new BigDecimal("1999.9"));
        
        assertEquals(myItem1.getClass(), itmNew.getClass());
    }
    
    /**
     * Test method for {@link model.Item#equals(java.lang.Object)}.
     */
    @Test
    public void testEqualsObject4() {
       
        assertNotEquals(myItem2, "Richard");
    }
    
    /**
     * Test method for {@link model.Item#equals(java.lang.Object)}.
     */
    @Test
    public void testEqualsObject5() {
        
        final Item itmNew = new Item("Richard's Iphone4s", new BigDecimal("424.24"), 10, 
                                     new BigDecimal("2244.24"));
        
        assertNotEquals(myItem2, itmNew);
    }
    
    /**
     * Test method for {@link model.Item#equals(java.lang.Object)}.
     */
    @Test
    public void testEqualsObject6() {
        
        final Item itmNew = new Item("Richard's Iphone", new BigDecimal("424.11"), 10, 
                                     new BigDecimal("2244.24"));
        
        assertNotEquals(myItem2, itmNew);
    }
    
    /**
     * Test method for {@link model.Item#equals(java.lang.Object)}.
     */
    @Test
    public void testEqualsObject7() {
        
        final Item itmNew = new Item("Richard's Iphone", new BigDecimal("424.24"), 11, 
                                     new BigDecimal("2244.24"));
        
        assertNotEquals(myItem2, itmNew);
    }
    
    /**
     * Test method for {@link model.Item#equals(java.lang.Object)}.
     */
    @Test
    public void testEqualsObject8() {
        
        final Item itmNew = new Item("Richard's Iphone", new BigDecimal("424.24"), 10, 
                                     new BigDecimal("2244.11"));
        
        assertNotEquals(myItem2, itmNew);
    }
    
    

}
