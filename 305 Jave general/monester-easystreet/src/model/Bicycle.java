/**
 * 
 */
package model;

import java.util.Map;

/**
 * Represents a Bicycle.
 * 
 * @author richardyang
 * @version 10.22
 */
public final class Bicycle extends AbstractVehicle {

    /** . */
    private static final int BICYCLE_DEATH_TIME = 15;
    
    /**
     * Initializes the instance fields.
     * 
     * @param theX the coordinate x of the Bicycle
     * @param theY the coordinate y of the Bicycle
     * @param theDir the direction of the Bicycle
     */
    public Bicycle(final int theX, final int theY, final Direction theDir) {
        super(theX, theY, theDir, BICYCLE_DEATH_TIME);
    }

    @Override
    public boolean canPass(final Terrain theTerrain, final Light theLight) {
        
        boolean result = false;
        
        if (theTerrain == Terrain.STREET 
                        || theTerrain == Terrain.TRAIL
                        || ((theTerrain == Terrain.LIGHT 
                        || theTerrain == Terrain.CROSSWALK) 
                        && theLight == Light.GREEN)) {
            result = true;
        }
        
        return result;
    }

    @Override
    public Direction chooseDirection(final Map<Direction, Terrain> theNeighbors) {
        final Direction result;
        
        if (theNeighbors.get(getDirection()) == Terrain.TRAIL) {
            result = getDirection();
        } else if (theNeighbors.get(getDirection().left()) == Terrain.TRAIL) {
            result = getDirection().left();
        } else if (theNeighbors.get(getDirection().right()) == Terrain.TRAIL) {
            result = getDirection().right();
        } else if (canGo(theNeighbors)) {   
            result = getDirection();
        } else if (canGoLeft(theNeighbors)) {
            result = getDirection().left();
        } else if (canGoRight(theNeighbors)) {
            result = getDirection().right();
        } else {
            result = getDirection().reverse();
        }
        
        return result;
    }

    
    /**
     * A helper function to decrease complexity for chooseDirection.
     * 
     * @param theNbs theNeighbors
     * @return result whether the bicycle can go ahead or not
     */
    private boolean canGo(final Map<Direction, Terrain> theNbs) {
        
        return theNbs.get(getDirection()) == Terrain.STREET
                        || theNbs.get(getDirection()) == Terrain.CROSSWALK
                        || theNbs.get(getDirection()) == Terrain.LIGHT;
        
    }
    
    /**
     * A helper function to decrease complexity for chooseDirection.
     * 
     * @param theNbs theNeighbors
     * @return result whether the bicycle can go left or not
     */
    private boolean canGoLeft(final Map<Direction, Terrain> theNbs) {
        
        return theNbs.get(getDirection().left()) == Terrain.STREET
                        || theNbs.get(getDirection().left()) == Terrain.CROSSWALK
                        || theNbs.get(getDirection().left()) == Terrain.LIGHT;
        
    }
    
    /**
     * A helper function to decrease complexity for chooseDirection.
     * 
     * @param theNbs theNeighbors
     * @return result whether the bicycle can go right or not
     */
    private boolean canGoRight(final Map<Direction, Terrain> theNbs) {
        
        return theNbs.get(getDirection().right()) == Terrain.STREET
                        || theNbs.get(getDirection().right()) == Terrain.CROSSWALK
                        || theNbs.get(getDirection().right()) == Terrain.LIGHT;
        
    }
    


}
