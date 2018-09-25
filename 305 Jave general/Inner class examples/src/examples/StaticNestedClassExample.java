/*
 * Nested and Inner Classes
 * TCSS 305
 */

package examples;

/**
 * A class that illustrates nested class concepts.
 * 
 * @author Daniel M. Zimmerman
 * @author Alan Fowler - added comments, fixed code to follow course conventions
 * @version 1.2
 */
public class StaticNestedClassExample {
 
    /**
     * The secret integer (shh!).
     */
    private int mySecret;

    /**
     * Constructor that sets the initial secret integer.
     * 
     * @param theSecret The secret integer.
     */
    public StaticNestedClassExample(final int theSecret) {
        mySecret = theSecret;
    }

    /**
     * @return the secret integer (yes, it's not that closely guarded a secret).
     */
    public int getSecret() {
        return mySecret;
    }

    /**
     * Creates and manipulates some instances of this class.
     * 
     * @param theArgs - Command line arguments, ignored.
     */
    public static void main(final String[] theArgs) {
        final StaticNestedClassExample outerObj = new StaticNestedClassExample(2);
        System.err.println("The first secret integer is "
            + outerObj.getSecret());

        final StaticNestedClassExample anotherOuterObj = new StaticNestedClassExample(12);
        System.err.println("The second secret integer is "
            + anotherOuterObj.getSecret());

        // The inner class is static so we access it using the name of the outer class
        final StaticNestedClassExample.StaticNestedClass insideObj
            = new StaticNestedClassExample.StaticNestedClass();

        // To access outer class members,
        // the static inner class must be passed an outer class reference
        insideObj.manipulateSecretInteger(outerObj);
        insideObj.manipulateSecretInteger(anotherOuterObj);

        System.err.println("The first secret integer (after manipulation) is "
            + outerObj.getSecret());
        System.err.println("The second secret integer (after manipulation) is "
            + anotherOuterObj.getSecret());
    }

    /**
     * A class that does sneaky things with the secret integer.
     * 
     * @author Daniel M. Zimmerman
     * @author Alan Fowler - changed some names - added some comments
     * @version 1.2
     */
    public static class StaticNestedClass {

        /**
         * Modifies the secret integer of the specified instance of NestedClass.
         * 
         * @param theInstance - The instance.
         */
        public void manipulateSecretInteger(final StaticNestedClassExample theInstance) {

            /*
             * In order for a static nested class to access non-static members
             * of the outer class (like the field 'my_secret') the static nested
             * class will need a reference to an object of the outer class. That
             * is why 'the_instance' is passed in as a parameter to this method.
             */

            /*
             * The symbol '<<' in the code below is a 'left shift' operator.
             * This causes a shift to the left of all bits in the internally
             * stored binary representation of the int.
             * 
             * The effect is that the number is multiplied by 2.
             */

            theInstance.mySecret = theInstance.mySecret << 1;
        }
    }

}
