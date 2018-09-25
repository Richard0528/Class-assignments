/*
 * TCSS 305 PowerPaint Rectangle 
 */
package tools;

import java.awt.Shape;
import java.awt.geom.Rectangle2D;

/**
 * The Rectangle tool.
 * 
 * @author richardyang
 * @version 11.13
 */
public class Rectangle extends AbstractTool {

    @Override
    public Shape getPath() {
        final Rectangle2D.Double rectangle = new Rectangle2D.Double();
        rectangle.setFrameFromDiagonal(getStartP(), getEndP());
        
        return rectangle;
    }

}
