/*
 * TCSS 305 PowerPaint Round Rectangle 
 */
package tools;

import java.awt.Shape;
import java.awt.geom.RoundRectangle2D;

/**
 * The RoundRectangle tool.
 * 
 * @author richardyang
 * @version 11.15
 */
public class RoundRectangle extends AbstractTool {

    @Override
    public Shape getPath() {

        final RoundRectangle2D.Double rrectangle = new RoundRectangle2D.Double();
        final int arcw = 20;
        rrectangle.setRoundRect(0, 0, 0, 0, arcw, arcw);
        rrectangle.setFrameFromDiagonal(getStartP(), getEndP());
        
        return rrectangle;
    }

}
