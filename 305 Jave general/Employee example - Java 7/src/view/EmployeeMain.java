/*
 * TCSS 305 - Employee inheritance example.
 */

package view;

import java.text.NumberFormat;
import java.util.GregorianCalendar;

import model.Employee;
import model.Lawyer;
import model.LegalSecretary;
import model.Marketer;
import model.Secretary;
import model.ServiceProvider;

/**
 * A class that uses Employee objects.
 * 
 * @author Alan Fowler (acfowler@uw.edu)
 * @version 1.2
 */
public final class EmployeeMain {

    /** A formatter for currency. */
    private static final NumberFormat NF = NumberFormat.getCurrencyInstance();

    /**
     * A private constructor to inhibit instantiation.
     */
    private EmployeeMain() {
        // do nothing
    }

    /**
     * @param theArgs command line parameters are not used in this program
     */
    public static void main(final String[] theArgs) {
        final Employee e1 = new Lawyer("Howie Cheatum", new GregorianCalendar());

        final Employee e2 = new Marketer("Penny Wise", new GregorianCalendar(2000, 0, 1));

        final Employee e3 = new Secretary("Polly Ester", new GregorianCalendar(2001, 8, 11));

        final Employee e4 =
                new LegalSecretary("Sandy Beach", new GregorianCalendar(2005, 11, 25));

        printInfo(e1);
        printInfo(e2);
        printInfo(e3);
        printInfo(e4);

    }

    /**
     * Displays some information about an Employee.
     * 
     * @param theEmployee an Employee object to display
     */
    public static void printInfo(final Employee theEmployee) {
        System.out.println(theEmployee);
        System.out.println("Seniority = " + theEmployee.getYears() + " years");
        System.out.println("Salary = " + NF.format(theEmployee.getSalary()));
        System.out.println("Vacation days = " + theEmployee.getVacationDays());
        System.out.println("Vacation form = " + theEmployee.getVacationForm());
        System.out.println("Service provided = "
                           + ((ServiceProvider) theEmployee).provideService());
        System.out.println();
    }

}
