/*
 * Java2D Text Demo - TCSS 305
 */

package view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Rectangle2D;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * A panel that demonstrates Java2D text rendering.
 * 
 * @author Alan Fowler
 * @version 1.1
 */
public class TextPanel extends JPanel {

    /** The panel width. */
    public static final int WIDTH = 600;

    /** The panel height. */
    public static final int HEIGHT = 400;
    
    /** The amount of space around some components. */
    public static final int PADDING = 50;

    /** Hello, world string. */
    public static final String HELLO_STRING = "Hello, World!";
    
    /** The size of the font in pixels. */
    public static final int FONT_SIZE = 60;
    
    /**
     * Serialization version ID.
     */
    private static final long serialVersionUID = -8569838884447050122L;

    /** The start coordinate for the gradient. */
    private static final int GRADIENT_START = 30;

    /** The end coordinate for the gradient. */
//    private static final int GRADIENT_END = 40;

    /**
     * Constructs a new text panel.
     */
    public TextPanel() {
        super();
 //       setBackground(Color.WHITE.darker());
        setPreferredSize(new Dimension(WIDTH, HEIGHT));
    }

    /**
     * Paints text in the panel.
     * 
     * @param theGraphics The graphics object to use for painting.
     */
    @Override
    public void paintComponent(final Graphics theGraphics) {
        super.paintComponent(theGraphics);
        final Graphics2D g2d = (Graphics2D) theGraphics;

        g2d.setPaint(new GradientPaint(GRADIENT_START, GRADIENT_START, Color.YELLOW,
                                       200, 200, Color.BLUE, true));
//                                       600, 400, Color.BLUE, false));
                                       
                                       
//         g2d.setPaint(new GradientPaint(GRADIENT_START, GRADIENT_START,
//         Color.YELLOW,
//         getWidth(), getHeight(), Color.BLUE, true));

        g2d.fill(new Rectangle2D.Double(20, 20, getWidth() - PADDING, getHeight() - PADDING));

        g2d.setFont(new Font(Font.MONOSPACED, Font.BOLD, FONT_SIZE));

        g2d.setPaint(Color.RED.darker().darker().darker());
        
        Color test = Color.RED;
        System.out.println(test);
        test = test.darker();
        System.out.println(test);
        test = test.brighter();
        System.out.println(test);
        
        
        g2d.drawString(HELLO_STRING, PADDING, getHeight() / 2);

        Color rectangleColor = new Color(255, 0, 0, 125);
        rectangleColor = rectangleColor.brighter().brighter().brighter();
        g2d.setPaint(rectangleColor);
        g2d.fill(new Rectangle2D.Double(PADDING, PADDING, 100, 200));
    }

    /**
     * Creates and displays a TextPanel.
     * 
     * @param theArgs Command line arguments (ignored).
     */
    public static void main(final String[] theArgs) {
        final TextPanel panel = new TextPanel();
        final JFrame frame = new JFrame("TextPanel Demo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
