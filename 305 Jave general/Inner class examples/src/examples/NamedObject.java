/*
 * Events/Inner Classes
 * TCSS 305
 */

package examples;

/**
 * A class that stores a name, and prints that name and a message to standard
 * error when doSomething() is called.
 * 
 * @author Daniel M. Zimmerman
 * @version 1.0
 */
public class NamedObject {

    /**
     * The name of this object.
     */
    private final String myName;

    /**
     * Constructs a new object with the specified name.
     * 
     * @param theName The name.
     */
    public NamedObject(final String theName) {
        myName = theName;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        return myName;
    }

    /**
     * Prints a message to standard error.
     */
    public void doSomething() {
        System.err.println(this + " did something!");
    }
}
