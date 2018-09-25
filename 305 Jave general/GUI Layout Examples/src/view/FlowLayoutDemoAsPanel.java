package view;

import javax.swing.JButton;
import javax.swing.JPanel;

/**
 * Demonstrating FlowLayout.
 * 
 * @author Charles Bryan
 * @version 1.1
 */
public class FlowLayoutDemoAsPanel extends JPanel {

    /**  A generated serial version UID for object Serialization. */
    private static final long serialVersionUID = 5105689607757907009L;
    
    /** The default amount of JButtons this window will have, 7. */
    private static final int NUMBER_OF_BUTTONS = 7;
    
    /** The default text to appear on the JButtons. */
    private static final String BUTTON_TEXT = "Button ";

    /** The amount of JButtons this window will have. */
    private final int myNumberOfButtons;
    
    /** The labels on the button in this panel. */
    private final String[] myButtonLabels;
    
    /**
     * Initializes all of the fields.
     * @param theButtonLabels the labels to be used on buttons this panel should have.
     */
    public FlowLayoutDemoAsPanel(final String[] theButtonLabels) {
        super();
        myNumberOfButtons = theButtonLabels.length;
        myButtonLabels = theButtonLabels.clone();
    }
    
    /**
     * Initializes all of the fields.
     */
    public FlowLayoutDemoAsPanel() {
        super();
        myNumberOfButtons = NUMBER_OF_BUTTONS;
        myButtonLabels = new String[NUMBER_OF_BUTTONS];
        for (int i = 0; i < myButtonLabels.length; i++) {
            myButtonLabels[i] = BUTTON_TEXT + i;
        }
    }
    
    /**
     * Lay out the components and makes this frame visible.
     */
    public void setUpComponents() {
        
        final JButton[] buttons = new JButton[myNumberOfButtons];
        
        //Create and add a button for each index in the array.
        for (int i = 0; i < buttons.length; i++) {
            buttons[i] = new JButton(myButtonLabels[i]);
            add(buttons[i]);
        }
    }

}
