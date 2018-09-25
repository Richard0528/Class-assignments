/**
 * TCSS 305 - easystreet
 */

package model;


/**
 * Represents default behavior for Vehicle subclasses.
 * 
 * @author richardyang
 * @version 10.21
 */
public abstract class AbstractVehicle implements Vehicle {
    
    
    // intance fields
    
    /** X coordinate of this vehicle. */
    private int myX;
    
    /** Initial X coordinate of this vehicle. */
    private int myInitialX;
    
    /** Y coordinate of this vehicle. */
    private int myY;
    
    /** Initial Y coordinate of this vehicle. */
    private int myInitialY;
    
    /** The direction for the vehicle. */
    private Direction myDir;
    
    /** The initial direction for the vehicle. */
    private Direction myInitialDir;
    
    /** The poke time count for the vehicle. */
    private int myPoke;
    
    /** The living condition for the vehicle. */
    private boolean myIsAlive = true;

    /** The death time for the vehicle. */
    private int myDeathTime;

    /**
     * Initialize the instance fields.
     * 
     * @param theX X coordinate of this vehicle
     * @param theY Y coordinate of this vehicle
     * @param theDir The direction for the vehicle
     * @param theDeathTime The death time for the vehicle
     */
    protected AbstractVehicle(final int theX, final int theY, final Direction theDir, 
                              final int theDeathTime) {

        myX = theX;
        myInitialX = theX;
        myY = theY;
        myInitialY = theY;
        myDir = theDir;
        myInitialDir = theDir;
        myDeathTime = theDeathTime;
    }

    @Override
    public void collide(final Vehicle theOther) {
        // TODO when they are equal
        if ((this.isAlive() && theOther.isAlive())
                        && (this.getDeathTime() < theOther.getDeathTime())) {
            this.myIsAlive = true;
        } else if ((this.isAlive() && theOther.isAlive())
                        && (this.getDeathTime() > theOther.getDeathTime())) {
            this.myIsAlive = false;
        }
        
    }

    @Override
    public int getDeathTime() {
        // TODO Auto-generated method stub
        return myDeathTime;
    }

    // Idea from Circle.java toString
    @Override
    public String getImageFileName() {
        final StringBuilder builder = new StringBuilder();
        builder.append(getClass().getSimpleName().toLowerCase());
        if (myIsAlive) {
            builder.append(".gif");
        } else {
            builder.append("_dead.gif");
        }
    
        return builder.toString();
    }

    @Override
    public Direction getDirection() {
       
        return myDir;
    }

    @Override
    public int getX() {
        
        return myX;
    }

    @Override
    public int getY() {
        
        return myY;
    }

    @Override
    public boolean isAlive() {
        
        return myIsAlive;
    }

    @Override
    public void poke() {
        
        if (isAlive()) {
            
            myIsAlive = true;
        } else {
            
            if (myPoke < getDeathTime()) {
                myPoke++;
            } else {
                myIsAlive = true;
                myPoke = 0;
                setDirection(Direction.random());
            }
        }
        
    }

    @Override
    public void reset() {
        myIsAlive = true;
        myPoke = 0;
        setX(myInitialX);
        setY(myInitialY);
        setDirection(myInitialDir);
    }

    @Override
    public void setDirection(final Direction theDir) {
        
        myDir = theDir;
    }

    @Override
    public void setX(final int theX) {
        
        myX = theX;
    }

    @Override
    public void setY(final int theY) {
        
        myY = theY;
    }
    
    /**
     * {@inheritDoc}
     * 
     * The String representation of this Circle will be formatted as follows:
     * <br>Vehicle [x value, y value, Direction, Poketime].
     */
    @Override
    public String toString() {
        final StringBuilder builder = new StringBuilder(100);
        builder.append(getClass().getSimpleName());
        builder.append(" [x=");
        builder.append(getX());
        builder.append(", y=");
        builder.append(getY());
        builder.append(", Direction=");
        builder.append(getDirection());
        builder.append(", Poketime=");
        builder.append(myPoke);
        builder.append(']');
        return builder.toString();
    }

}
