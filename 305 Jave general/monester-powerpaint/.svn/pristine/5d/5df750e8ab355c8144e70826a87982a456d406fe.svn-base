/**
 * 
 */
package tools;

import java.awt.Point;
import java.awt.geom.Point2D;

/**
 * The abstract class for tools.
 * 
 * @author richardyang
 * @version 11.11
 */
public abstract class AbstractTool implements Tool {
    
    /** A point outside the drawing area. */
    public static final Point NO_POINT = new Point(-50, -50);

    /** the start point. */
    private Point2D myStartP;
    
    /** the end point. */
    private Point2D myEndP;

    /** the line width. */
    private int myLineWidth;
    
    /** the fillable. */
    private boolean myFillable;

    /**
     * Initialize those point.
     */
    public AbstractTool() {
        myStartP = NO_POINT;
        myEndP = NO_POINT;
    }
    
    @Override
    public Point2D getStartP() {
        return myStartP;
    }
    
    @Override
    public void setStartP(final Point2D theStartP) {
        myStartP = theStartP;
    }

    @Override
    public Point2D getEndP() {
        return myEndP;
    }

    @Override
    public void setEndP(final Point2D theEndP) {
        myEndP = theEndP;
    }
    
    @Override
    public int getLineWidth() {
        return myLineWidth;
    }
    
    @Override
    public void setLineWidth(final int theLineWidth) {
        myLineWidth = theLineWidth;
    }
    
    @Override
    public boolean isFillable() {
        return myFillable;
    }
    
    @Override
    public void setFillable(final boolean theFillable) {
        myFillable = theFillable;
    }
    
    
}
