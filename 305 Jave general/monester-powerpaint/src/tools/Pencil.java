/*
 * TCSS 305 PowerPaoint Pencil
 */
package tools;

import java.awt.Shape;
import java.awt.geom.GeneralPath;
import java.awt.geom.Point2D;

/**
 * The Pencil tool.
 * 
 * @author richardyang
 * @version 11.13
 */
public class Pencil extends AbstractTool {

    /** create a path. */
    private GeneralPath myPath;
    
    /**
     * constructor for the pencil tool.
     */
    public Pencil() {
        super();
        myPath = new GeneralPath();
    }
    
    @Override
    public void setStartP(final Point2D theStartP) {
        myPath = new GeneralPath();
        myPath.moveTo(theStartP.getX(), theStartP.getY());
    }
    
    @Override
    public Shape getPath() {
        myPath.lineTo(getEndP().getX(), getEndP().getY());
        return myPath;
    }

}
