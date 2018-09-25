/*
 * TCSS 305 example code
 */

package gui;

import java.util.Observable;

/**
 * Encapsulates a String which is Observable.
 * 
 * @author Alan Fowler
 * @version 1.2
 */
public class ObservableString extends Observable {

    /** The encapsulated text. */
    private String myText;

    /**
     * Constructs this ObservableString.
     * 
     * @param theText the String to encapsulate in this object
     */
    public ObservableString(final String theText) {
        super();
        myText = theText;
    }

    /**
     * Sets the encapsulated String.
     * 
     * @param theText the String to encapsulate in this object
     */
    public void setText(final String theText) {
        if (!theText.equals(myText)) {
            myText = theText;
            setChanged();
            notifyObservers(myText);
        }
    }

}
