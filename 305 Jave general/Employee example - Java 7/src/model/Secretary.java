/*
 * TCSS 305 - Employee inheritance example.
 */

package model;

import java.math.BigDecimal;
import java.util.Calendar;

/**
 * Represents a Secretary.
 * 
 * @author Alan Fowler with help from the entire TCSS 305 class!
 * @version 1.2
 */
public class Secretary extends AbstractEmployee {
    
    /** The salary bonus for a Secretary. */
    private static final BigDecimal SALARY_BONUS = BigDecimal.ZERO;
    
    /** The vacation form for a Secretary. */
    private static final String VACATION_FORM = "Yellow";

    /**
     * Initializes the instance fields.
     * 
     * @param theName the name of this Employee
     * @param theHireDate the hire date for this Employee
     */
    public Secretary(final String theName,
                     final Calendar theHireDate) {
        super(theName, theHireDate, VACATION_FORM);
    }
    
    @Override
    protected BigDecimal getSalaryBonus() {
        return SALARY_BONUS;
    }
    
    @Override
    public String provideService() {
        return "Hold please ...";
    }

}
