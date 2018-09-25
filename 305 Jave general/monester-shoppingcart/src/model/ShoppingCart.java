/*
 * TCSS 305
 * Assignment 2 - shopping cart
 * part 3 - main body
 */

package model;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.List;

/**
 * ShoppingCart stores information about the customer's overall purchases.
 * 
 * @author richardyang
 * @version 10.17
 */
public class ShoppingCart {

    /**
     * An arraylist to construct shopping cart.
     */
    private List<ItemOrder> myCart;
    
    /**
     * A boolean used to determine membership status.
     */
    private boolean myMembership;

    /**
     * 
     */
    public ShoppingCart() {
         
        myCart = new ArrayList<ItemOrder>();
        
    }

    /**
     * Add itemOrder into Arraylist myCart.
     * if it exists a same previous order with different quantity,
     * the method will replace the order with a new order containing wanted quantity
     * 
     * @param theOrder the customer`s purchase order
     */
    public void add(final ItemOrder theOrder) {

        // this is wrong! I took me 5 hrs to find our what's happened
        // So I won't delete it
//        if (myCart.isEmpty()) {
//            myCart.add(theOrder);
//        } else {
//            for (int i = 0; i < myCart.size(); i++) {
//                if (theOrder.getItem().equals(myCart.get(i).getItem())) {
//                    System.out.print("RESTART"+myCart);
//                    myCart.set(i,theOrder);
//                } else {
//                    System.out.print("RESTART"+myCart);
//                    myCart.add(theOrder);
//                }
//            }
//        }

        if (myCart.size() < 2) {
            myCart.add(theOrder);
        } else {
            myCart.add(theOrder);
            for (int i = 0; i < myCart.size() - 1; i++) {
                if (myCart.get(i).getItem().equals(theOrder.getItem())) {
                    myCart.remove(i);
                }
            }
        }
        
        
    }

    /**
     * Sets the membership status on or off.
     * 
     * @param theMembership decide the membership status
     */
    public void setMembership(final boolean theMembership) {
        
        myMembership = theMembership;
    }

    /**
     * Calculates and returns the total cost of customer's orders.
     * 
     * @return the total cost of customer's orders
     */
    public BigDecimal calculateTotal() {

        BigDecimal totalCost = BigDecimal.ZERO;

        for (int i = 0; i < myCart.size(); i++) {
            
            BigDecimal curCost = BigDecimal.ZERO;
            final int eachQuant = myCart.get(i).getQuantity();
            final Item orderItem = myCart.get(i).getItem(); 
            final int bulkNum = orderItem.getBulkQuantity();
            
            if (myMembership && orderItem.isBulk()) {
                final int actualQuantity = eachQuant / bulkNum; 
                final int actualRemain = eachQuant % bulkNum;
                curCost = (new BigDecimal(actualQuantity).
                                multiply(orderItem.getBulkPrice())).
                                add(new BigDecimal(actualRemain).
                                    multiply(orderItem.getPrice()));
             
            } else {
                curCost = (new BigDecimal(eachQuant)).multiply(orderItem.getPrice());
                
            }
            totalCost = totalCost.add(curCost);
            
        }
        
        return totalCost.setScale(2, RoundingMode.HALF_EVEN);
    }
    
    /**
     * removes all the elements in the myCart.
     */
    public void clear() {
        myCart = new ArrayList<ItemOrder>();
    }

    /**
     * {@inheritDoc}
     * 
     * The String representation of the item will be formatted as follows:
     * <br>Item, [quantity]
     * <br>Membership Status:XXX, [Total cost: XXXX]
     */
    @Override
    public String toString() {
        final StringBuilder builder = new StringBuilder();
        for (int i = 0; 0 < myCart.size(); i++) {
            builder.append(myCart.get(i));
        }
        builder.append("\nMembership Status: ");
        builder.append(myMembership);
        builder.append(", [Total cost: ");
        builder.append(calculateTotal());
        builder.append("]");
        return builder.toString();
    }

}
