/*
 * TCSS 305 - Employee inheritance example.
 */

package model;

/**
 * Defines common behavior for all service providers.
 * 
 * @author Alan Fowler (acfowler@uw.edu)
 * @version 1.2
 */
public interface ServiceProvider {

    /**
     * Returns a description of the service provided.
     * 
     * @return a description of the service provided
     */
    String provideService();

}
