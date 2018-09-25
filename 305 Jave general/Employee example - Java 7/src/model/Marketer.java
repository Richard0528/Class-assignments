/*
 * TCSS 305 - Employee inheritance example.
 */

package model;

import java.math.BigDecimal;
import java.util.Calendar;

/**
 * Represents a Marketer.
 * 
 * @author Alan Fowler with help from the entire TCSS 305 class!
 * @version 1.2
 */
public class Marketer extends AbstractEmployee {
    
    /** The salary bonus for a Marketer. */
    private static final BigDecimal SALARY_BONUS = new BigDecimal("10000");
    
    /** The vacation form for a Marketer. */
    private static final String VACATION_FORM = "Yellow";

    /**
     * Initializes the instance fields.
     * 
     * @param theName the name of this Employee
     * @param theHireDate the hire date for this Employee
     */
    public Marketer(final String theName, final Calendar theHireDate) {
        super(theName, theHireDate, VACATION_FORM);
    }

    @Override
    protected BigDecimal getSalaryBonus() {
        return SALARY_BONUS;
    }
    
    @Override
    public String provideService() {
        return "Act now while supplies last!";
    }

}
