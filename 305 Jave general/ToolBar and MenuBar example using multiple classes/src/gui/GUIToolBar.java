/*
 * TCSS 305 example code
 */

package gui;

import javax.swing.Action;
import javax.swing.ButtonGroup;
import javax.swing.JToggleButton;
import javax.swing.JToolBar;

/**
 * The JToolBar for this GUI example.
 * 
 * @author Alan Fowler
 * @version 2.0
 */
public class GUIToolBar extends JToolBar {

    /** A generated serialization ID. */
    private static final long serialVersionUID = -6969282661802905468L;

    /** A button group for the mutually exclusive tool bar buttons. */ 
    private final ButtonGroup myGroup;

    /**
     * Construct the ToolBar.
     */
    public GUIToolBar() {
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
        myGroup.clearSelection();
        add(toggleButton);
    }

}
