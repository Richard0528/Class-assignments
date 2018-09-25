/**
 * 
 */
package model;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Random;

/**
 * Represents a Atv.
 * 
 * @author richardyang
 * @version 10.22
 */
public final class Atv extends AbstractVehicle {
    
    /** a death time for Atv. */
    private static final int ATV_DEATH_TIME = 10;
    
    /**
     * Initializes the instance fields.
     * 
     * @param theX the coordinate x of the Atv
     * @param theY the coordinate y of the Atv
     * @param theDir the direction of the Atv
     */
    public Atv(final int theX, final int theY, final Direction theDir) {
        super(theX, theY, theDir, ATV_DEATH_TIME);
    }

    @Override
    public boolean canPass(final Terrain theTerrain, final Light theLight) {
        
        return theTerrain != Terrain.WALL;
    }

    @Override
    public Direction chooseDirection(final Map<Direction, Terrain> theNeighbors) {
        
        final List<Direction> pickDirection = new ArrayList<>();
        pickDirection.add(getDirection().left());
        pickDirection.add(getDirection().right());
        pickDirection.add(getDirection());
        
        final Random rand = new Random();
        final Direction result;
        
        result = pickDirection.get(rand.nextInt(pickDirection.size()));
     
        return result;
        
        
    }

}
