/**
 * 
 */
package model;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import org.junit.Test;

/**
 * Unit tests for class Truck.
 * 
 * @author richardyang
 * @version 10.26
 */
public class TruckTest {

    /**
     * The number of times to repeat a test to have a high probability that all
     * random possibilities have been explored.
     */
    private static final int TRIES_FOR_RANDOMNESS = 50;

    /** Test method for Human constructor. */
    @Test
    public void testTruckConstructor() {
        final Truck t1 = new Truck(1, 1, Direction.EAST);
        
        assertEquals("Truck x coordinate not initialized correctly!", 1, t1.getX());
        assertEquals("Truck y coordinate not initialized correctly!", 1, t1.getY());
        assertEquals("Human direction not initialized correctly!",
                     Direction.EAST, t1.getDirection());
        assertEquals("Human death time not initialized correctly!", 0, t1.getDeathTime());
        assertTrue("Human isAlive() fails initially!", t1.isAlive());
        
    }
    
    /** Test method for Truck setters. */
    @Test
    public void testTruckSetters() {
        final Truck t2 = new Truck(1, 1, Direction.EAST);
        
        t2.setX(19);
        assertEquals("Truck setX failed!", 19, t2.getX());
        t2.setY(9);
        assertEquals("Truck setY failed!", 9, t2.getY());
        t2.setDirection(Direction.WEST);
        assertEquals("Truck setDirection failed!", Direction.WEST, t2.getDirection());
    }
    
    /**
     * Test method for {@link Truck#canPass(Terrain, Light)}.
     */
    @Test
    public void testCanPass() {
        
        final List<Terrain> validTerrain = new ArrayList<>();
        validTerrain.add(Terrain.STREET);
        validTerrain.add(Terrain.CROSSWALK);
        validTerrain.add(Terrain.LIGHT);
                
        final Truck t3 = new Truck(19, 9, Direction.WEST);
        // test each terrain type as a destination
        for (final Terrain destinationTerrain : Terrain.values()) {
            // try the test under each light condition
            for (final Light currentLightCondition : Light.values()) {
                if (destinationTerrain == Terrain.STREET) {
                
                    // Trucks can pass STREET under any light condition
                    assertTrue("Truck should be able to pass STREET"
                               + ", with light " + currentLightCondition,
                               t3.canPass(destinationTerrain, currentLightCondition));
                } else if (destinationTerrain == Terrain.CROSSWALK) {
                           // Trucks can pass CROSSWALK
                           // if the light is RED but not GREEN or YELLOW

                    if (currentLightCondition == Light.GREEN 
                                    || currentLightCondition == Light.YELLOW) {
                        assertTrue("Truck should be able to pass " + destinationTerrain
                            + ", with light " + currentLightCondition,
                            t3.canPass(destinationTerrain,
                                          currentLightCondition));
                    } else { // light is red
                        assertFalse("Truck should be NOT able to pass " + destinationTerrain
                            + ", with light " + currentLightCondition,
                            t3.canPass(destinationTerrain,
                                          currentLightCondition));
                    }
                    
                } else if (destinationTerrain == Terrain.LIGHT) {
                    // Trucks can pass Light under any light condition
                    assertTrue("Truck should be able to pass LIGHT"
                                    + ", with light " + currentLightCondition,
                                    t3.canPass(destinationTerrain, currentLightCondition));
                } else if (!validTerrain.contains(destinationTerrain)) {
 
                    assertFalse("Truck should NOT be able to pass " + destinationTerrain
                        + ", with light " + currentLightCondition,
                        t3.canPass(destinationTerrain, currentLightCondition));
                }
            }
        }
    }
    
    /**
     * Test method for {@link Truck#chooseDirection(java.util.Map)}.
     */
    @Test
    public void testChooseDirectionSurroundedByStreet() {
        final Map<Direction, Terrain> neighbors = new HashMap<Direction, Terrain>();
        neighbors.put(Direction.WEST, Terrain.STREET);
        neighbors.put(Direction.NORTH, Terrain.STREET);
        neighbors.put(Direction.EAST, Terrain.STREET);
        neighbors.put(Direction.SOUTH, Terrain.STREET);
        
        boolean seenWest = false;
        boolean seenNorth = false;
        boolean seenEast = false;
        boolean seenSouth = false;
        
        final Truck t4 = new Truck(1, 1, Direction.EAST);
        
        for (int count = 0; count < TRIES_FOR_RANDOMNESS; count++) {
            final Direction d = t4.chooseDirection(neighbors);
            
            if (d == Direction.SOUTH) {
                seenSouth = true;
            } else if (d == Direction.NORTH) {
                seenNorth = true;
            } else if (d == Direction.EAST) {
                seenEast = true;
            } else if (d == Direction.WEST) { // this should NOT be chosen
                seenWest = true;
            }
        }
 
        assertTrue("Truck chooseDirection() fails to select randomly "
                   + "among all possible valid choices!",
                   seenSouth && seenNorth && seenEast);
            
        assertFalse("Truck chooseDirection() reversed direction when not necessary!",
                    seenWest);
        
    }
    
    /**
     * Test method for {@link Truck#chooseDirection(java.util.Map)}.
     */
    @Test
    public void testChooseDirectionSurroundedByLight() {
        final Map<Direction, Terrain> neighbors = new HashMap<Direction, Terrain>();
        neighbors.put(Direction.WEST, Terrain.LIGHT);
        neighbors.put(Direction.NORTH, Terrain.LIGHT);
        neighbors.put(Direction.EAST, Terrain.LIGHT);
        neighbors.put(Direction.SOUTH, Terrain.LIGHT);
        
        boolean seenWest = false;
        boolean seenNorth = false;
        boolean seenEast = false;
        boolean seenSouth = false;
        
        final Truck t4 = new Truck(1, 1, Direction.EAST);
        
        for (int count = 0; count < TRIES_FOR_RANDOMNESS; count++) {
            final Direction d = t4.chooseDirection(neighbors);
            
            if (d == Direction.SOUTH) {
                seenSouth = true;
            } else if (d == Direction.NORTH) {
                seenNorth = true;
            } else if (d == Direction.EAST) {
                seenEast = true;
            } else if (d == Direction.WEST) { // this should NOT be chosen
                seenWest = false;
            }
        }

        assertTrue("Truck chooseDirection() fails to select randomly "
                   + "among all possible valid choices!",
                   seenSouth && seenNorth && seenEast);
            
        assertFalse("Truck chooseDirection() reversed direction when not necessary!",
                    seenWest);
    }
    
    
    /**
     * Test method for {@link Truck#chooseDirection(java.util.Map)}.
     */
    @Test
    public void testChooseDirectionSurroundedByCrosswalk() {
        final Map<Direction, Terrain> neighbors = new HashMap<Direction, Terrain>();
        neighbors.put(Direction.WEST, Terrain.CROSSWALK);
        neighbors.put(Direction.NORTH, Terrain.CROSSWALK);
        neighbors.put(Direction.EAST, Terrain.CROSSWALK);
        neighbors.put(Direction.SOUTH, Terrain.CROSSWALK);
        
        boolean seenWest = false;
        boolean seenNorth = false;
        boolean seenEast = false;
        boolean seenSouth = false;
        
        final Truck t4 = new Truck(1, 1, Direction.EAST);
        
        for (int count = 0; count < TRIES_FOR_RANDOMNESS; count++) {
            final Direction d = t4.chooseDirection(neighbors);
            
            if (d == Direction.SOUTH) {
                seenSouth = true;
            } else if (d == Direction.NORTH) {
                seenNorth = true;
            } else if (d == Direction.EAST) {
                seenEast = true;
            } else if (d == Direction.WEST) { // this should NOT be chosen
                seenWest = true;
            }
        }
 
        assertTrue("Truck chooseDirection() fails to select randomly "
                   + "among all possible valid choices!",
                   seenSouth && seenNorth && seenEast);
            
        assertFalse("Truck chooseDirection() reversed direction when not necessary!",
                    seenWest);
        
    }
    
    
    /**
     * Test method for {@link Human#chooseDirection(java.util.Map)}.
     */
    @Test
    public void testChooseDirectionOnStreetMustReverse1() {
        for (final Terrain t : Terrain.values()) {
            if (t != Terrain.STREET && t != Terrain.CROSSWALK && t != Terrain.LIGHT) {
                
                final Map<Direction, Terrain> neighbors = new HashMap<Direction, Terrain>();
                neighbors.put(Direction.WEST, Terrain.STREET);
                neighbors.put(Direction.NORTH, t);
                neighbors.put(Direction.EAST, t);
                neighbors.put(Direction.SOUTH, t);
                
                final Truck t5 = new Truck(1, 1, Direction.EAST);
                
                // the Truck must reverse and go WEST
                assertEquals("Truck chooseDirection() failed "
                                + "when reverse was the only valid choice!",
                             Direction.WEST, t5.chooseDirection(neighbors));
            }
                
        }
    }
    
}
