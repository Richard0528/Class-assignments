/*
 * TCSS 305 PowerPaint Ellipse
 */
package tools;

import java.awt.Shape;
import java.awt.geom.Ellipse2D;

/**
 * The Ellipse tool.
 * 
 * @author richardyang
 * @version 11.15
 */
public class Ellipse extends AbstractTool {

    @Override
    public Shape getPath() {
        final Ellipse2D.Double ellipse = new Ellipse2D.Double();
        ellipse.setFrameFromDiagonal(getStartP(), getEndP());
        
        return ellipse;
    }

}
