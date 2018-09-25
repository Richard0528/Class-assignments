/*
 * TCSS 305 - Employee inheritance example.
 */

package model;

import java.math.BigDecimal;
import java.util.Calendar;

/**
 * Represents a LegalSecretary.
 * 
 * @author Alan Fowler with help from the entire TCSS 305 class!
 * @version 1.2
 */
public class LegalSecretary extends Secretary {
    
    /** The salary bonus for a LegalSecretary. */
    private static final BigDecimal SALARY_BONUS = new BigDecimal("5000");
    
    /** The vacation bonus for a LegalSecretary. */
    private static final int VACATION_BONUS = 0;

    /**
     * Initializes the instance fields.
     * 
     * @param theName the name of this Employee
     * @param theHireDate the hire date for this Employee
     */
    public LegalSecretary(final String theName, final Calendar theHireDate) {
        super(theName, theHireDate);
    }
    
    @Override
    protected BigDecimal getSalaryBonus() {
        return SALARY_BONUS;
    }
    
    @Override
    protected int getVacationBonus() {

        return VACATION_BONUS;
    }
    
    @Override
    public String provideService() {
        return super.provideService() + " I think they are in court...";
    }

}
