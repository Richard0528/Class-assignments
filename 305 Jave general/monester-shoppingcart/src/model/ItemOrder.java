/*
 * TCSS 305
 * Assignment 2 - shopping cart
 * part 2 - item order
 */

package model;

/**
 * a purchase order for a particular item.
 * 
 * <br> no pre-condition will be considered in this assignment
 * 
 * @author richardyang
 * @version 10.15
 */
public final class ItemOrder {

    /**
     * a reference to the item.
     */
    private final Item myItem;
    
    /**
     * the quantity for this itemOrder.
     */
    private int myQuantity;

    /**
     * Store information about a purchase order for a particular item.
     * 
     * @param theItem a reference to the item
     * @param theQuantity the quantity for the item
     */
    public ItemOrder(final Item theItem, final int theQuantity) {
        
        myItem = theItem;
        myQuantity = theQuantity;
        
    }

    /**
     * return a reference of the item.
     * 
     * @return a reference of the item
     */
    public Item getItem() {
        
        return myItem;
    }
    
    /**
     * return the quantity for this itemOrder.
     * 
     * @return the quantity for this itemOrder
     */
    public int getQuantity() {
        
        return myQuantity;
    }

    /**
     * {@inheritDoc}
     * 
     * The String representation of the item will be formatted as follows:
     * <br>Item, [quantity] 
     */
    @Override
    public String toString() {
        final StringBuilder builder = new StringBuilder();
        builder.append(getItem());
        builder.append(", [");
        builder.append(getQuantity());
        builder.append("]");
        return builder.toString();
    }

}
