/**
 * 
 */
package model;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Random;


/**
 * Represents a Truck.
 * 
 * @author richardyang
 * @version 10.22
 */
public final class Truck extends AbstractVehicle {

    /** . */
    private static final int TRUCK_DEATH_TIME = 0;
    
    /**
     * Initializes the instance fields.
     * 
     * @param theX the coordinate x of the Truck
     * @param theY the coordinate y of the Truck
     * @param theDir the direction of the Truck
     */
    public Truck(final int theX, final int theY, final Direction theDir) {
        super(theX, theY, theDir, TRUCK_DEATH_TIME);
    }
    

    @Override
    public boolean canPass(final Terrain theTerrain, final Light theLight) {
        
        boolean result = false;
        
        if (theTerrain == Terrain.STREET || theTerrain == Terrain.LIGHT
                        || (theTerrain == Terrain.CROSSWALK 
                        && theLight != Light.RED)) {
            result = true;
        }
        
        return result;
    }

    @Override
    public Direction chooseDirection(final Map<Direction, Terrain> theNeighbors) {
        
        final List<Direction> pickDirection = new ArrayList<>();
        pickDirection.add(getDirection().left());
        pickDirection.add(getDirection().right());
        pickDirection.add(getDirection());
        
        final Random rand = new Random();
        Direction result;
        
        if (helperReverse(theNeighbors)) {
            result = getDirection().reverse();
        } else {
            result = pickDirection.get(rand.nextInt(pickDirection.size()));
            while (theNeighbors.get(result) != Terrain.STREET
                            && theNeighbors.get(result) != Terrain.CROSSWALK
                            && theNeighbors.get(result) != Terrain.LIGHT) {
                result = pickDirection.get(rand.nextInt(pickDirection.size()));
            }
            
        }
//        previous way but did not work
//        final Random rand = new Random();
//        final Direction result;
//        
//        final List<Direction> pickDirection = new ArrayList<>();
//
//        final Terrain leftBlock = theNeighbors.get(getDirection().left());
//        final Terrain rightBlock = theNeighbors.get(getDirection().right());
//        final Terrain headBlock = theNeighbors.get(getDirection());
//        
//        if (headBlock != Terrain.STREET || headBlock != Terrain.LIGHT 
//                        || headBlock != Terrain.CROSSWALK) {
//            pickDirection.add(getDirection());
//        }
//        
//        if (leftBlock != Terrain.STREET || leftBlock != Terrain.LIGHT 
//                        || leftBlock != Terrain.CROSSWALK) {
//            pickDirection.add(getDirection().left());
//        }
//
//        if (rightBlock != Terrain.STREET || rightBlock != Terrain.LIGHT 
//                        || rightBlock != Terrain.CROSSWALK) {
//            pickDirection.add(getDirection().right());
//        }
//
//        if (pickDirection.size() == 0) {
//            pickDirection.add(getDirection().reverse());
//        }
//        
//        result = pickDirection.get(rand.nextInt(pickDirection.size()));
//        
        return result;
    }
    
    /**
     * A helper function to decrease complexity for chooseDirection.
     * 
     * @param theNbs theNeighbors
     * @return result whether the truck should reverse or not
     */
    private boolean helperReverse(final Map<Direction, Terrain> theNbs) {
        
        return theNbs.get(getDirection()) != Terrain.STREET 
                        && theNbs.get(getDirection()) != Terrain.LIGHT
                        && theNbs.get(getDirection()) != Terrain.CROSSWALK
                        && theNbs.get(getDirection().left()) != Terrain.STREET
                        && theNbs.get(getDirection().left()) != Terrain.LIGHT
                        && theNbs.get(getDirection().left()) != Terrain.CROSSWALK
                        && theNbs.get(getDirection().right()) != Terrain.STREET
                        && theNbs.get(getDirection().right()) != Terrain.LIGHT
                        && theNbs.get(getDirection().right()) != Terrain.CROSSWALK; 
        
    }
    
}





