/*
 * TCSS 305 PowerPaint Tool Bar
 */

package gui;

import javax.swing.Action;
import javax.swing.ButtonGroup;
import javax.swing.JToggleButton;
import javax.swing.JToolBar;

/**
 * The JToolBar for PowerPaint.
 * 
 * @author richardyang
 * @version 11.9
 */
public class PowerPaintToolBar extends JToolBar {

    /** A generated serialization ID. */
    private static final long serialVersionUID = 7697353648374164561L;
    
    /** A button group for the mutually exclusive tool bar buttons. */ 
    private final ButtonGroup myGroup;

    /**
     * Construct the ToolBar.
     */
    public PowerPaintToolBar() {
        super();
        myGroup = new ButtonGroup();
    }

    /**
     * Create a JToggleButton for the ToolBar.
     * 
     * @param theAction to associate with the created JToggleButton
     */
    public void createToolBarButton(final Action theAction) {
        final JToggleButton toggleButton = new JToggleButton(theAction);
        myGroup.add(toggleButton);
//        myGroup.clearSelection();
        add(toggleButton);
    }

}
