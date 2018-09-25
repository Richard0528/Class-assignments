/*
 * TCSS 305 - Employee inheritance example.
 */

package model;

import java.math.BigDecimal;
import java.text.DateFormat;
import java.util.Calendar;
import java.util.Date;

/**
 * Represents default behavior for Employee subclasses.
 * 
 * Employees are immutable objects - no state changes after instantiation.
 * 
 * @author Alan Fowler
 * @version 1.2
 */
public abstract class AbstractEmployee implements Employee, ServiceProvider {
    
    // These constants could be defined in the Employee Interface instead
    
    /** All Employees earn this base salary. */
    private static final BigDecimal BASE_SALARY = new BigDecimal("50000");
    
    /** All Employees earn this number of vacation days / year. */
    private static final int BASE_VACATION_DAYS = 10;

    /** The number of millisecond in a year. */
    private static final long MILLISECONDS_PER_YEAR = 365L * 24 * 60 * 60 * 1000;
    
    // instance fields
    
    /** The name of this Employee. */
    private final String myName;
    
    /** The hire date of this Employee. */
    private final Calendar myHireDate; // mutable state! Handle with care!
    
    /** The vacation form used by this Employee. */
    private final String myVacationForm;
    
    

    /**
     * Initialize the instance fields.
     * 
     * @param theName the name of this Employee
     * @param theHireDate the hire date for this Employee
     * @param theVacationForm the vacation form for this Employee
     */
    protected AbstractEmployee(final String theName,
                               final Calendar theHireDate,
                               final String theVacationForm) {
        myName = theName;
        myHireDate = (Calendar) theHireDate.clone(); // defensive copy
        myVacationForm = theVacationForm;
    }

    @Override
    public BigDecimal getSalary() {
 
        return BASE_SALARY.add(getSalaryBonus());
    }

    /**
     * Return the salary bonus for this Employee.
     * 
     * @return the salary bonus for this employee
     */
    protected abstract BigDecimal getSalaryBonus();


    @Override
    public int getVacationDays() {
        return BASE_VACATION_DAYS + getVacationBonus();
    }

    /**
     * Return the vacation bonus for this Employee.
     * 
     * @return the vacation bonus for this Employee
     */
    protected int getVacationBonus() {

        return 2 * getYears();
    }


    @Override
    public int getYears() {
        final Date today = new Date();
        final long elapsedTime = today.getTime() - myHireDate.getTimeInMillis();
        return (int) (elapsedTime / MILLISECONDS_PER_YEAR);
    }

    @Override
    public String getVacationForm() {
       
        return myVacationForm;
    }
    

    @Override
    public String toString() {
        final DateFormat df = DateFormat.getDateInstance(DateFormat.MEDIUM);
        final StringBuilder sb = new StringBuilder(64);
        sb.append(getClass().getSimpleName());
        sb.append("\nName = ");
        sb.append(myName);
        sb.append("\nHire date = ");
        sb.append(df.format(myHireDate.getTime()));
        return sb.toString();
    }

}
