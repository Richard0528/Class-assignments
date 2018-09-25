/*
 * TCSS 305 - Employee inheritance example.
 */

package model;

import java.math.BigDecimal;
import java.util.Calendar;

/**
 * Represents a Lawyer.
 * 
 * @author Alan Fowler
 * @version 1.2
 */
public class Lawyer extends AbstractEmployee {
    
    /** The salary bonus for a Lawyer. */
    private static final BigDecimal SALARY_BONUS = new BigDecimal("10000");
    
    /** The vacation form for a Lawyer. */
    private static final String VACATION_FORM = "Pink";
    
    /** The vacation bonus for a Lawyer. */
    private static final int VACATION_BONUS = 5;

    /**
     * Initializes the instance fields.
     * 
     * @param theName the name of this Employee
     * @param theHireDate the hire date for this Employee
     */
    public Lawyer(final String theName, final Calendar theHireDate) {
        super(theName, theHireDate, VACATION_FORM);
    }

    @Override
    protected BigDecimal getSalaryBonus() {
        return SALARY_BONUS;
    }
        
    @Override
    protected int getVacationBonus() {

        return super.getVacationBonus() + VACATION_BONUS;
    }

    @Override
    public String provideService() {
        return "I'll see you in court!";
    }

}
