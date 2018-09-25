/*
 * Events/Inner Classes
 * TCSS 305
 */

package model;

/**
 * A class that stores a name, and prints that name and a message to standard
 * error when doSomething() is called.
 * 
 * @author Charles Bryan
 * @version 1.1
 */
public class QuoteToErrObject extends AbstractNamedObject {
    
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
    public QuoteToErrObject(final String theName, final String theQuote) {
        super(theName);
        myQuote = theQuote;
    }

    /**
     * Prints the quote to standard error.
     */
    @Override
    public void doSomething() {
        System.err.println(myQuote);
    }
}
