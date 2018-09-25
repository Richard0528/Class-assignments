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
public class InnerClassExample {

    /**
     * The secret integer (shh!).
     */
    private int mySecret;

    /**
     * Constructs an instance with the specified secret integer.
     * 
     * @param theSecret The secret integer.
     */
    public InnerClassExample(final int theSecret) {
        mySecret = theSecret;
    }

    /**
     * @return the secret integer (yes, it's not that closely guarded a secret).
     */
    public int getSecret() {
        return mySecret;
    }

    /**
     * Constructs and manipulates some instances of this class.
     * 
     * @param theArgs
     *            Command line arguments, ignored.
     */
    public static void main(final String[] theArgs) {
        // Same as in StaticNestedClassTest
        final InnerClassExample outerObject = new InnerClassExample(2);
        System.err.println("The first secret integer is "
            + outerObject.getSecret());

        // Same as in StaticNestedClassTest
        final InnerClassExample anotherOuterObject = new InnerClassExample(12);
        System.err.println("The second secret integer is "
            + anotherOuterObject.getSecret());

        // Different - no need to pass a reference to the manipulate method
        final InnerClassExample.InnerClass innerObj = outerObject.new InnerClass();
        innerObj.manipulateSecretInteger();

        // Different - no need to pass a reference to the manipulate method
        final InnerClassExample.InnerClass innerObj2 = anotherOuterObject.new InnerClass();
        innerObj2.manipulateSecretInteger();

        System.err.println("The first secret integer (after manipulation) is "
            + outerObject.getSecret());
        System.err.println("The second secret integer (after manipulation) is "
            + anotherOuterObject.getSecret());
    }

    /**
     * A class that does sneaky things with the secret integer.
     * 
     * @author Daniel M. Zimmerman
     * @author Alan Fowler - added comments, fixed code to follow course conventions
     * @version 1.2
     */
    private class InnerClass {

        /**
         * Modifies the secret integer of my instance of NestedClass.
         */
        public void manipulateSecretInteger() {

            /*
             * A non-static inner class is able to access the members of the
             * outer class directly. Notice that there is no need to pass a
             * reference to this method.
             */

            /*
             * The symbol '<<' in the code below is a 'left shift' operator.
             * This causes a shift to the left of all bits in the internally
             * stored binary representation of the int.
             */

            mySecret = mySecret << 1;
        }
    } // end of inner class

}
