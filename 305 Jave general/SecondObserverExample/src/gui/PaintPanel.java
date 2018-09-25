/*
 * TCSS 305 example code
 */

package gui;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.font.FontRenderContext;
import java.awt.font.GlyphVector;
import java.awt.geom.Rectangle2D;
import java.util.Observable;
import java.util.Observer;

import javax.swing.JPanel;

/**
 * The JPanel upon which the text will be painted.
 * 
 * @author Alan Fowler
 * @version 1.2
 */
public class PaintPanel extends JPanel implements Observer {

    /** A generated version Id for serialization. */
    private static final long serialVersionUID = -8251549606513241007L;

    /** The default size for this JPanel. */
    private static final Dimension DEFUALT_SIZE = new Dimension(400, 300);

    /** The font size in points. */
    private static final int FONT_SIZE = 80;

    /** The String to display on the panel. */
    private String myText;
    /**
     * Construct this JPanel.
     */
    public PaintPanel() {
        super();
        setPreferredSize(DEFUALT_SIZE);
        setBackground(Color.WHITE);
        myText = "Welcome";
    }

    @Override
    public void paintComponent(final Graphics theGraphics) {
        super.paintComponent(theGraphics);
        final Graphics2D g2d = (Graphics2D) theGraphics;

        final Font font = new Font(Font.SERIF, Font.BOLD + Font.ITALIC, FONT_SIZE);
        g2d.setFont(font);

        // get the visual bounds of the text using a GlyphVector.
        final FontRenderContext renderContext = g2d.getFontRenderContext();
        final GlyphVector glyphVector = font.createGlyphVector(renderContext, myText);
        final Rectangle2D visualBounds = glyphVector.getVisualBounds().getBounds();

        final int x =
            (int) ((getWidth() - visualBounds.getWidth()) / 2 - visualBounds.getX());
        final int y =
            (int) ((getHeight() - visualBounds.getHeight()) / 2 - visualBounds.getY());

        // display the text visually centered in the JPanel
        g2d.drawString(myText, x, y);
    }

    @Override
    public void update(final Observable theObservable, final Object theArg) {
        if (theObservable instanceof ObservableString) {
            myText = theArg.toString();
            repaint();
        }
    }

}
