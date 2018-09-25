/*
 * TCSS 305 PowerPaint Panel
 */

package gui;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.RenderingHints;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.geom.GeneralPath;
import java.awt.geom.Path2D;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JPanel;
import tools.DrawPath;
import tools.Tool;


/**
 * The drawing Panel for PowerPaint.
 * 
 * @author richardyang
 * @version 11.9
 */
public class PowerPaintPanel extends JPanel {
    
    /** A generated serialization ID. */
    private static final long serialVersionUID = 806283877397839752L;

    /** The default size for this JPanel. */
    private static final Dimension DEFAULT_SIZE = new Dimension(200, 200);

    /** The default background color of the panel. */
    private static final Color BACKGROUND_COLOR = Color.WHITE;
    
    /** The default color to paint with. */
    private static final Color UW_PURPLE = new Color(51, 0, 111);
    
    /** The color to fill. */
    private static final Color UW_GOLD = new Color(232, 211, 162);
    
    /** The default value for drawing width. */
    private static final int DEFAULT_WIDTH = 5;
    
    /** A boolean to terminate clear order. */
    protected boolean myClearOrder;
    
    /** The drawing color. */
    private Color myDrawColor = UW_PURPLE;
    
    /** The line width. */
    private int myLineWidth = DEFAULT_WIDTH;
    
    /** The filling color. */
    private Color myFillColor = UW_GOLD;
    
    /** The fill check box. */
    private boolean myFillable;

    /** The start point. */
    private Point myStartP;

    /** The end point. */
    private Point myEndP;

    /** The selected tool. */
    private Tool myTool;
    
    /** A collection of previously drawn shapes. */
    private List<DrawPath> myDrawPath;

    /**
     * Constructs a new general path panel.
     * 
     * @param theDrawColor
     * @param theFillColor
     * @param theLineWidth
     */
    public PowerPaintPanel() {
        super();
        final Path2D drawPath = new GeneralPath();
        myDrawPath = new ArrayList<>();
        
        drawPath.setWindingRule(GeneralPath.WIND_EVEN_ODD);

        setPreferredSize(DEFAULT_SIZE);
        setBackground(BACKGROUND_COLOR);
        setCursor(new Cursor(Cursor.CROSSHAIR_CURSOR));
        
        addMouseListener(new MyMouseListener());
        addMouseMotionListener(new MyMouseListener());
        
    }
    

    /**
     * Set selected tool.
     * 
     * @param theTool selected tool
     */
    public final void setCurrentTool(final Tool theTool) {
        myTool = theTool;
    }
    
    /**
     * Paints the current path.
     * 
     * @param theGraphics The graphics context to use for painting.
     */
    @Override
    public void paintComponent(final Graphics theGraphics) {
        super.paintComponent(theGraphics);
        final Graphics2D g2d = (Graphics2D) theGraphics;
        final boolean toolCheck = !myTool.getClass().getName().equals("tools.Pencil");
        
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                             RenderingHints.VALUE_ANTIALIAS_ON);

        // Draw previous shapes
        for (final DrawPath s : getMyDrawPath()) {
            g2d.setPaint(s.getFillColor());
            g2d.setStroke(new BasicStroke(s.getLineWidth()));
            if (s.isFillable() && toolCheck) {
                g2d.fill(s.getPath());
            }
            g2d.setPaint(s.getColor());
            g2d.draw(s.getPath());
        }
        
        g2d.setStroke(new BasicStroke(myLineWidth));
        
        if (!myClearOrder) {
            if (isMyFillable() && toolCheck) {
                g2d.setPaint(getMyFillColor());
                g2d.fill(myTool.getPath());
            }

            g2d.setPaint(myDrawColor);
            if (getMyLineWidth() != 0) {
                g2d.draw(myTool.getPath());
            }
        }

        if (getMyDrawPath().isEmpty()) {
            myClearOrder = false;
        }

    }

    /**
     * A clear method for clear button.
     */
    public void clear() {
        myClearOrder = true;
        repaint();
    }
    
    /**
     * getter for drawing color.
     * 
     * @return draw color
     */
    public Color getMyDrawColor() {
        return myDrawColor;
    }

    /**
     * setter for drawing color.
     * 
     * @param theDrawColor draw color
     */
    public void setMyDrawColor(final Color theDrawColor) {
        myDrawColor = theDrawColor;
    }
    
    /**
     * setter for fill color.
     * 
     * @return fill color
     */
    public Color getMyFillColor() {
        return myFillColor;
    }

    /**
     * getter for fill color.
     * 
     * @param theFillColor fill color
     */
    public void setMyFillColor(final Color theFillColor) {
        myFillColor = theFillColor;
    }
    
    /**
     * getter for line width.
     * 
     * @return line width
     */
    public int getMyLineWidth() {
        return myLineWidth;
    }

    /**
     * setter for line width.
     * 
     * @param theLineWidth line width
     */
    public void setMyLineWidth(final int theLineWidth) {
        myLineWidth = theLineWidth;
    }
    
    /**
     * The getter for fillable.
     * 
     * @return fill check box boolean
     */
    public boolean isMyFillable() {
        return myFillable;
    }

    /**
     * The setter for fillable.
     * 
     * @param theFillable fill check box boolean
     */
    public void setMyFillable(final boolean theFillable) {
        myFillable = theFillable;
    }

    /**
     * getter for draw path list.
     * 
     * @return draw path list
     */
    public List<DrawPath> getMyDrawPath() {
        return myDrawPath;
    }
    
    /**
     * setter for draw path list.
     * 
     * @param theDrawPath draw path list
     */
    public void setMyDrawPath(final List<DrawPath> theDrawPath) {
        myDrawPath = theDrawPath;
    }

    
    // Inner Class
    
    /**
     * Listens for mouse clicks, to draw on our panel.
     */
    private class MyMouseListener extends MouseAdapter {
     
        /**
         * Handles a click event.
         * 
         * @param theEvent The event.
         */
        @Override
        public void mousePressed(final MouseEvent theEvent) {
            
            myStartP = theEvent.getPoint();
            myEndP = theEvent.getPoint();
            myTool.setStartP(myStartP);
            myTool.setEndP(myEndP);
            myTool.setLineWidth(getMyLineWidth());
        }
        
        /**
         * Handles a release event.
         * 
         * @param theEvent The event.
         */
        @Override
        public void mouseReleased(final MouseEvent theEvent) {
            myEndP = theEvent.getPoint();
            myTool.setEndP(myEndP);
            
            final DrawPath path = new DrawPath(myTool.getPath(), myDrawColor, myFillColor,
                                               myTool.getLineWidth(), myFillable);
            getMyDrawPath().add(path);
            firePropertyChange("clearorder", false, !getMyDrawPath().isEmpty());
            
        }
 
        /**
         * Handles a drag event.
         * 
         * @param theEvent The event.
         */
        @Override
        public void mouseDragged(final MouseEvent theEvent) {
            
            myEndP = theEvent.getPoint();
            myTool.setEndP(myEndP);           
            repaint();
        }
        
    }



}
