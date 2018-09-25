/*
 * TCSS 305 - String Concatenation Demo
 */

import java.util.Scanner;

/**
 * Illustrates the speed difference between + operator and StringBuilder.append,
 * when performing many concatenations.
 * 
 * @author Java Practices (http://www.javapractices.com/)
 * @author Daniel M. Zimmerman
 * @author Alan Fowler
 * @version 2.0
 */
public final class AvoidConcatenation {
    /**
     * The numbers of iterations to run.
     */
    private static final int[] NUM_ITERATIONS = {10, 100, 1000, 10000, 100000};

    /**
     * The string for "milliseconds".
     */
    private static final String MS_STRING = "ms";

    /**
     * The string to append.
     */
    private static final String APPEND_STRING = "append";

    /**
     * Private constructor.
     */
    private AvoidConcatenation() {
        // do nothing
    }

    /**
     * The main method.
     * 
     * @param theArgs Command line arguments, ignored.
     */
    public static void main(final String... theArgs) {
        final Scanner scanner = new Scanner(System.in);

        for (final int iterations : NUM_ITERATIONS) {
            System.out.print("Press enter to run test for " + iterations + " iterations:");
            scanner.nextLine();

            long start = System.currentTimeMillis();
            doWithStringBuilder(iterations);
            long finish = System.currentTimeMillis();

            StringBuilder message = new StringBuilder("Task using StringBuilder.append: ");
            message.append(finish - start);
            message.append(MS_STRING);
            System.out.println(message);

            start = System.currentTimeMillis();
            doWithConcatenationOperator(iterations);
            finish = System.currentTimeMillis();
            message = new StringBuilder();
            message.append("Task using + operator: ");
            message.append(finish - start);
            message.append(MS_STRING);
            System.out.println(message);
            System.out.println();

        }

        scanner.close();
    }

    /**
     * Perform concatenation for the_iterations iterations with "+".
     * 
     * @param theIterations The number of iterations.
     * @return the concatenated string.
     */
    private static String doWithConcatenationOperator(final int theIterations) {
        String result = APPEND_STRING;
        for (int idx = 0; idx < theIterations; idx++) {
            result = result + APPEND_STRING;
        }
        return result;
    }

    /**
     * Perform concatenation for the_iterations iterations with a StringBuilder.
     * 
     * @param theIterations The number of iterations.
     * @return the concatenated string.
     */
    private static String doWithStringBuilder(final int theIterations) {
        final StringBuilder result = new StringBuilder(APPEND_STRING);
        for (int idx = 0; idx < theIterations; idx++) {
            result.append(APPEND_STRING);
        }
        return result.toString();
    }
}
