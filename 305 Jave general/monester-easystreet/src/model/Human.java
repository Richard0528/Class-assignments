/**
 * 
 */
package model;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Random;

/**
 * Represents a Human.
 * 
 * @author richardyang
 * @version 10.22
 */
public final class Human extends AbstractVehicle {

    /** . */
    private static final int HUMAN_DEATH_TIME = 20;
    
    /**
     * Initializes the instance fields.
     * 
     * @param theX the coordinate x of the Human
     * @param theY the coordinate y of the Human
     * @param theDir the direction of the Human
     */
    public Human(final int theX, final int theY, final Direction theDir) {
        super(theX, theY, theDir, HUMAN_DEATH_TIME);
    }

    @Override
    public boolean canPass(final Terrain theTerrain, final Light theLight) {
        
        return theTerrain == Terrain.GRASS 
                        || (theTerrain == Terrain.CROSSWALK && theLight != Light.GREEN);
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
        } else if (theNeighbors.get(getDirection()) == Terrain.CROSSWALK) {
            result = getDirection();
        } else if (theNeighbors.get(getDirection().left()) == Terrain.CROSSWALK) {
            result = getDirection().left();
        } else if (theNeighbors.get(getDirection().right()) == Terrain.CROSSWALK) {
            result = getDirection().right();
        } else {
            result = pickDirection.get(rand.nextInt(pickDirection.size()));
            while (theNeighbors.get(result) != Terrain.GRASS 
                            && theNeighbors.get(result) != Terrain.CROSSWALK) {
                result = pickDirection.get(rand.nextInt(pickDirection.size()));
            }
            
        }
        
        return result;
    }
    
    /**
     * A helper function to decrease complexity for chooseDirection.
     * 
     * @param theNbs theNeighbors
     * @return result whether the truck should reverse or not
     */
    private boolean helperReverse(final Map<Direction, Terrain> theNbs) {
        
        return theNbs.get(getDirection()) != Terrain.GRASS 
                        && theNbs.get(getDirection()) != Terrain.CROSSWALK
                        && theNbs.get(getDirection().left()) != Terrain.GRASS
                        && theNbs.get(getDirection().left()) != Terrain.CROSSWALK
                        && theNbs.get(getDirection().right()) != Terrain.GRASS
                        && theNbs.get(getDirection().right()) != Terrain.CROSSWALK; 
        
    }
    
    
    
    
}
