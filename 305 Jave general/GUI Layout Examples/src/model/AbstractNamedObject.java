/*
 * Events/Inner Classes
 * TCSS 305
 */

package model;

/**
 * A class that stores a name, and its children 
 * do something when doSomething() is called.
 * 
 * @author Charles Bryan
 * @version 1.1
 */
public abstract class AbstractNamedObject implements DoSomething {

    /**
     * The name of this object.
     */
    private final String myName;

    /**
     * Constructs a new object with the specified name.
     * 
     * @param theName The name.
     */
    public AbstractNamedObject(final String theName) {
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
     * {@inheritDoc}
     */
    @Override
    public abstract void doSomething(); 
}
