/*
 * TCSS 305
 * Assignment 2 - shopping cart
 * part 1 - item
 */

package model;
import java.math.BigDecimal;
import java.util.Objects;
//import java.util.Objects;
/**
 * 
 * @author richardyang
 * @version 10.15
 */
public final class Item {
    
    // instance field
    
    /**
     * the name of the item.
     */
    private String myName;
    
    /**
     * the price of the item.
     */
    private BigDecimal myPrice;
    
    /**
     * the bulk quantity of the item.
     */
    private int myBulkQuantity;
    
    /**
     * the bulk price of the item.
     */
    private BigDecimal myBulkPrice;
    
    /**
     * whether the item is bulk or not.
     */
    private boolean myIsBulk;
    
    // Constructor
    
    /**
     * Constructor that takes two arguments.
     * 
     * @param theName takes a name
     * @param thePrice takes a price
     */
    public Item(final String theName, final BigDecimal thePrice) {
        myName = theName;
        myPrice = thePrice;
    }

    /**
     * Constructor that takes four arguments.
     * 
     * @param theName takes a name
     * @param thePrice takes a price
     * @param theBulkQuantity takes a bulk quantity
     * @param theBulkPrice takes a bulk price
     */
    public Item(final String theName, final BigDecimal thePrice, final int theBulkQuantity,
                final BigDecimal theBulkPrice) {
        
        myName = theName;
        myPrice = thePrice;
        myBulkQuantity = theBulkQuantity;
        myBulkPrice = theBulkPrice;
    }

    /**
     * return name of the item.
     * 
     * @return name of the item
     */
    public String getName() {
        
        return myName;
    }
    
    /**
     * return price of the item.
     * 
     * @return price of the item
     */
    public BigDecimal getPrice() {
        
        return myPrice;
    }
    
    /**
     * return bulk quantity of the item.
     * 
     * @return bulk quantity of the item
     */
    public int getBulkQuantity() {
        
        return myBulkQuantity;
    }
    
    /**
     * return bulk price of the item.
     * 
     * @return bulk price of the item
     */
    public BigDecimal getBulkPrice() {
        
        return myBulkPrice;
    }

    /**
     * return whether the item is bulk or not.
     * 
     * @return whether the item is bulk or not
     */
    public boolean isBulk() {
        
        if (getBulkPrice() != null) {
            myIsBulk = true;
        } else {
            myIsBulk = false;
        }
        return myIsBulk;
    }

    /**
     * {@inheritDoc}
     * 
     * The String representation of the item will be formatted as follows:
     * <br>name, price 
     *     or name, price (quantity for price) if bulk price exists
     */
    @Override
    public String toString() {
        final StringBuilder builder = new StringBuilder();
        
        builder.append(getName());
        builder.append(", $");
        builder.append(getPrice());
        if (isBulk()) {
            builder.append(" (");
            builder.append(getBulkQuantity());
            builder.append(" for $");
            builder.append(getBulkPrice());
            builder.append(")");
        }
        return builder.toString();
    }

    /**
     * {@inheritDoc}
     * 
     * This method compares name, price, bulk quantity, bulk price to determine the
     * equality of item objects. All four fields must be equal for 2 items objects to 
     * be considered equal.
     */
    @Override
    public boolean equals(final Object theOther) {

        boolean returnValue = false;
        
        if (this == theOther) {
            returnValue = true;
        } else if (theOther != null && this.getClass() == theOther.getClass()) {
            final Item otherItem = (Item) theOther;
            
            returnValue = Objects.equals(myName, otherItem.myName)
                            && Objects.equals(myPrice, otherItem.myPrice)
                            && Objects.equals(myBulkQuantity, otherItem.myBulkQuantity)
                            && Objects.equals(myBulkPrice, otherItem.myBulkPrice);
        }
        
        return returnValue;
    }

    @Override
    public int hashCode() {
        
        return Objects.hash(myName, myPrice, myBulkQuantity, myBulkPrice);
    }

}
