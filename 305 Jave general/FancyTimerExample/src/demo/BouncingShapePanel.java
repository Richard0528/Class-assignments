/*
 * Alan Fowler
 * 
 * TCSS 305
 */

package demo;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.geom.RoundRectangle2D;
import java.util.Random;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;

/*
 * NOTE: This example is all in a single class which is NOT ideal. This class
 * should be broken into multiple smaller classes to improve the structure and
 * maintainability of the code.
 * 
 * The only reason so much is packed into this single class is for convenience
 * during demonstrations.
 */

/*
 * NOTE: THe Eclipse plugin tools show warnings in this code until all parts of
 * the code which are currently commented out are commented back in. After that
 * there should be no warnings generated from this code by the Eclipse plugin tools.
 */

/**
 * A program to demonstrate the use of Swing timers.
 * 
 * @author TCSS 305 Instructors
 * @version 1.3
 */
public class BouncingShapePanel extends JPanel {

    // Constants

    /** The initial Shape bounding box side length (in pixels). */
    public static final int BOUNDING_BOX_SIDE = 30;

    /** The maximum bounding box side length (in pixels). */
    public static final int MAX_SIZE = 100;

    /** The number of milliseconds the move timer delay changes when "+" or "-" is pressed. */
    public static final int DELAY_CHANGE = 1;

    /** The preferred window size. */
    public static final Dimension PREFERRED_SIZE = new Dimension(800, 450);

    /** The delay (in milliseconds) for the move timer. */
    public static final int MOVE_DELAY = 20;

    /** The delay (in milliseconds) for the color timer. */
    public static final int COLOR_DELAY = 5;

    /** The animation step (in pixels). */
    public static final int ANIMATION_STEP = 1;
    
    /** A generated version ID for Serialization. */
    private static final long serialVersionUID = -1822629220627954216L;

    // Instance fields

    /** A reference to my JFrame (to change its title). */
    private final JFrame myFrame;
    
    /** The current bounding box size. */
    private int myShapeSize;

    /** The corner size; used for changing the roundness of rounded rectangle corners. */
    private double myCorners;
    
    /** The "bouncing Shape" color. */
    private Color myColor;

    /** The "bouncing Shape" shape. */
    private final RoundRectangle2D myShape;

    /** The timer that controls the movement of the Shape. */
    private final Timer myMoveTimer;

    /** The timer that controls the color of the Shape. */
    private final Timer myColorTimer;

    /** An integer that determines the horizontal movement at each animation step. */
    private int myHorizontalMove;

    /** An integer that determines the vertical movement at each animation step. */
    private int myVerticalMove;

    /** A random number generator. */
    private final Random myRandom = new Random();

    // Constructor

    /**
     * Constructs a new BouncingShapePanel.
     * 
     * @param theFrame The JFrame in which the panel should be constructed.
     */
    public BouncingShapePanel(final JFrame theFrame) {
        super();
        myFrame = theFrame;
        
        // initialize some timers - the listeners are setup separately
        myMoveTimer = new Timer(MOVE_DELAY, null);
        myColorTimer = new Timer(COLOR_DELAY, null);
        
        /*
         * The initial location of the Shape is the upper-left corner,
         * initially it is moving diagonally downward and to
         * the right, and its color is blue.
         */
        
        myShapeSize = BOUNDING_BOX_SIDE;
        myCorners = BOUNDING_BOX_SIDE;
        myColor = Color.BLUE;
        //myColor = new Color(128, 128, 128);
        
        // make the bouncing Shape a perfectly round RoundRectangle2D initially
        myShape = new RoundRectangle2D.Double(0, 0,
                                                      BOUNDING_BOX_SIDE, BOUNDING_BOX_SIDE,
                                                      myCorners, myCorners);
       
        setupAppearance();
        setupListeners();
    }

    /** Sets up event listeners. */
    private void setupListeners() {
        
        myHorizontalMove = ANIMATION_STEP;
        myVerticalMove = ANIMATION_STEP;

        /*
         * Comment in the line below to listen for "+" and "-" keys to control
         * animation speed. Also comment in the "updateFrameTitle();" line in
         * setupAppearance() and in SpeedControlKeyListener.
         */
        myFrame.addKeyListener(new SpeedControlKeyListener());

        /*
         * Comment in the line below to use myMoveTimer for color changes OR
         * comment in the other line below to use a separate timer for color
         * changes.
         */
        myMoveTimer.addActionListener(new MoveListener());
        //myMoveTimer.addActionListener(new ColorListener());
        //myColorTimer.addActionListener(new ColorListener());
        
    }

    /** Sets up the appearance of the panel and frame. */
    private void setupAppearance() {
        setBackground(Color.WHITE);
        setPreferredSize(PREFERRED_SIZE);
        updateFrameTitle();
    }

    /** Updates the title of our frame with the correct timer delay. */
    public final void updateFrameTitle() {
        myFrame.setTitle("BouncingShape - Delay = " + myMoveTimer.getDelay() + "ms");
    }

    /** Starts the timer. */
    public void start() {
        myMoveTimer.start();
        myColorTimer.start();
    }

    /**
     * Repaints the component with the specified graphics context.
     * 
     * @param theGraphics The graphics context.
     */
    @Override
    public void paintComponent(final Graphics theGraphics) {
        super.paintComponent(theGraphics);
        final Graphics2D g2d = (Graphics2D) theGraphics;
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                             RenderingHints.VALUE_ANTIALIAS_ON);
        g2d.setPaint(myColor);
        g2d.fill(myShape);
    }

    /** Marks a rectangular region to be repainted. */
    private void repaintShapeLocation() {
        repaint(new Rectangle((int) myShape.getX(),
                              (int) myShape.getY(),
                              myShapeSize, myShapeSize));
    }

    // *********** Inner Classes *******************************

    /**
     * A class that listens for timer events and moves the Shape, checking for
     * the window boundaries and changing direction as appropriate.
     */
    private class MoveListener implements ActionListener {
        /**
         * Moves the Shape appropriately.
         * 
         * @param theEvent The event triggering the action.
         */
        public void actionPerformed(final ActionEvent theEvent) {
            // we don't really care what the event is; we know this will only be
            // called by the timer

            // if the Shape bounds touch the window bounds, we need to change
            // direction
            updateHorizontalMove();
            updateVerticalMove();

            /*
             * Marks the old location of the Shape as dirty. Without this the
             * animation will leave "trails" or other debris on the panel as the
             * animation progresses.
             */
            //repaintShapeLocation();

            // adjust the Shape position
            myShape.setRoundRect(myShape.getX() + myHorizontalMove,
                                         myShape.getY() + myVerticalMove,
                                         myShapeSize, myShapeSize,
                                         myCorners, myCorners);
            
            repaint();

            // marks new location of the Shape as dirty so that the location
            // will be repainted
            //repaintShapeLocation();
            
            /*
             * Each call to repaintShapeLocation() in the code above marks a
             * rectangular region of the panel to be repainted, but the actual
             * repaint does not occur until later (after this actionPerformed()
             * method of the MoveListener returns). To learn more about this
             * check out
             * http://www.oracle.com/technetwork/java/painting-140037.html
             * #paint_process
             */
        }

        /** Updates the horizontal move to keep the Shape on screen. */
        private void updateHorizontalMove() {
            if (myShape.getFrame().getMinX() < 0) {
                // change direction
                myHorizontalMove = ANIMATION_STEP;

                // change roundedness of corners of the Shape
                //myCorners = myRandom.nextInt(Math.max(myShapeSize, 1));
            } else if (myShape.getFrame().getMaxX()
                    > BouncingShapePanel.this.getWidth()) {
                // change direction
                myHorizontalMove = -ANIMATION_STEP;

                // change roundedness of corners of the Shape
                //myCorners = myRandom.nextInt(Math.max(myShapeSize, 1));
            }
        }

        /** Updates the vertical move to keep the Shape on screen. */
        private void updateVerticalMove() {
            if (myShape.getFrame().getMinY() < 0) {
                // change direction
                myVerticalMove = ANIMATION_STEP;

                // change size of the Shape
                //myShapeSize = myRandom.nextInt(MAX_SIZE);
            } else if (myShape.getFrame().getMaxY()
                    > BouncingShapePanel.this.getHeight()) {
                // change direction
                myVerticalMove = -ANIMATION_STEP;

                // change size of the Shape
                //myShapeSize = myRandom.nextInt(MAX_SIZE);
            }
        }
    } // end of MoveListener

    /**
     * Listens for keystrokes - on a up arrow, increases the speed of the animation
     * by decrementing the timer delay by a fixed amount; on a down arrow, decreases
     * the speed of the animation by incrementing the timer delay by a fixed
     * amount.
     */
    private class SpeedControlKeyListener extends KeyAdapter {

        /**
         * Handles a key being typed.
         * 
         * @param theEvent The KeyEvent generated by the key.
         */
        public void keyPressed(final KeyEvent theEvent) {
            if (theEvent.getKeyCode() == KeyEvent.VK_UP) {
                // increase the animation speed
                speedUp();
            } else if (theEvent.getKeyCode() == KeyEvent.VK_DOWN) {
                // decrease the animation speed
                slowDown();
            }

            /*
             * comment in the line below to update the frame title also comment
             * in this same line in setupAppearance()
             */
            updateFrameTitle();
        }

        /** Speeds up the timer. */
        private void speedUp() {
            // decrease the timer delay, but do not set a negative delay
            myMoveTimer.setDelay(Math.max(myMoveTimer.getDelay() - DELAY_CHANGE, 0));
        }

        /** Slows down the timer. */
        private void slowDown() {
            myMoveTimer.setDelay(myMoveTimer.getDelay() + DELAY_CHANGE);
        }

    } // end of SpeedControlKeyListener

    /**
     * A listener that changes the color of the Shape.
     */
    private class ColorListener implements ActionListener {
        /** The maximum color change per event. */
        private static final int MAX_CHANGE = 2;

        /** The maximum color value. */
        private static final int MAX_COLOR = 255;

        /** The random number generator to use for colors. */
        private final Random myRandom = new Random();

        /** The direction in which we are changing the red value. */
        private int myRedDir = 1;

        /** The direction in which we are changing the blue value. */
        private int myBlueDir = 1;

        /** The direction in which we are changing the green value. */
        private int myGreenDir = 1;

        /**
         * Changes the color of the Shape by a little bit for each color value.
         * 
         * @param theEvent The event, ignored.
         */
        public void actionPerformed(final ActionEvent theEvent) {
            final int newRed = getNewColor(myColor.getRed(), myRedDir);
            if (newRed <= 0) {
                myRedDir = 1;
            } else if (newRed >= MAX_COLOR) {
                myRedDir = -1;
            }
            
            final int newGreen = getNewColor(myColor.getGreen(), myGreenDir);
            if (newGreen <= 0) {
                myGreenDir = 1;
            } else if (newGreen >= MAX_COLOR) {
                myGreenDir = -1;
            }
            
            final int newBlue = getNewColor(myColor.getBlue(), myBlueDir);
            if (newBlue <= 0) {
                myBlueDir = 1;
            } else if (newBlue >= MAX_COLOR) {
                myBlueDir = -1;
            }
            
            myColor = new Color(newRed, newGreen, newBlue);
//            System.out.println(myColor);
        }

        /**
         * Calculates a new color value.
         * 
         * @param theOld The old color value.
         * @param theDir The direction to change it in.
         * @return the new color value.
         */
        private int getNewColor(final int theOld, final int theDir) {
            int result = theOld + theDir * myRandom.nextInt(MAX_CHANGE);
            if (result > MAX_COLOR) {
                result = MAX_COLOR;
            } else if (result < 0) {
                result = 0;
            }
            return result;
        }
    } // end of ColorListener

} // end of BouncingShapePanel
