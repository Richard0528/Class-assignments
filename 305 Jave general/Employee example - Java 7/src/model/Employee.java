/*
 * TCSS 305 - Employee inheritance example.
 */

package model;

import java.math.BigDecimal;

/**
 * Defines behavior common to all Employee subclasses.
 * 
 * @author Alan Fowler (acfowler@uw.edu)
 * @version 1.2
 */
public interface Employee {
    
    // constants (static final fields) could also be defined here

    /**
     * Returns the annual salary for this Employee in dollars.
     * 
     * @return the annual salary for this Employee
     */
    BigDecimal getSalary();

    /**
     * Returns the total number of vacation days for this Employee including any bonus days.
     * 
     * @return the number of annual vacation days for this Employee
     */
    int getVacationDays();

    /**
     * Returns the total number of years this Employee has worked for the company.
     * 
     * @return the number of years seniority for this Employee
     */
    int getYears();

    /**
     * Returns the color of the correct vacation request form for this Employee.
     * 
     * @return the color of the correct vacation form for this Employee
     */
    String getVacationForm();

}
