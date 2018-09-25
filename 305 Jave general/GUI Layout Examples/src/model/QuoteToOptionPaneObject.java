/*
 * Events/Inner Classes
 * TCSS 305
 */

package model;

import javax.swing.JOptionPane;

/**
 * A class that stores a name, and prints that name and a message to a 
 * JOptionPane when doSomething() is called.
 * 
 * @author Charles Bryan
 * @version 1.1
 */
public class QuoteToOptionPaneObject extends AbstractNamedObject {
    
    /**
     * The quote this object returns.
     */
    private final String myQuote;

    /**
     * Constructs a new object with the specified name.
     * 
     * @param theName The name.
     * @param theQuote The quote.
     */
    public QuoteToOptionPaneObject(final String theName, final String theQuote) {
        super(theName);
        myQuote = theQuote;
    }

    /**
     * Prints the quote to standard error.
     */
    @Override
    public void doSomething() {
        JOptionPane.showMessageDialog(null, myQuote);
    }
}
