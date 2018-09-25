/*
 * ToolBarFrame TCSS 305
 */

/*
 * This example shows the use of Actions directly added to a menu and toolbar.
 */

package toolbar;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.util.ArrayList;
import java.util.List;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.JToolBar;
import javax.swing.KeyStroke;

/**
 * A frame that uses a menu bar and Toolbar to change colors.
 * 
 * @author Daniel M. Zimmerman, based on an original program by Cay Horstmann
 * @author Alan Fowler
 * @version 1.2
 */
public class ToolBarFrame extends JFrame {

    /** The default width of the frame. */
    public static final int DEFAULT_WIDTH = 300;

    /** The default height of the frame. */
    public static final int DEFAULT_HEIGHT = 200;
    
    /** A generated serialization ID. */
    private static final long serialVersionUID = -4447570618384470786L;

    /** A constant for the string "Exit". */
    private static final String EXIT_STRING = "Exit";
    

    /** The panel used inside the frame. */
    private final JPanel myPanel;

    /** The exit action. */
    private Action myExitAction;

    /** A list of color actions. */
    private List<ColorAction> myColorActions;

    // Constructor

    /**
     * Constructs a new ToolBarFrame with all its controls.
     */
    public ToolBarFrame() {
        super("Actions");
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);

        setupActions(); // initializes my_actions

        final JToolBar toolBar1 = createToolBar();
        add(toolBar1, BorderLayout.SOUTH);

        myPanel = new JPanel(); // for color changes
        myPanel.setPreferredSize(new Dimension(DEFAULT_WIDTH, DEFAULT_HEIGHT));
        add(myPanel, BorderLayout.CENTER);

        setJMenuBar(createMenuBar());
    }

    /**
     * Sets up all the Actions.
     */
    private void setupActions() {
        myColorActions = new ArrayList<ColorAction>();

        myColorActions.add(new ColorAction("Yellow", new ImageIcon("./yellow-ball.gif"),
                                             Color.YELLOW));
        myColorActions.add(new ColorAction("Red", new ImageIcon("./red-ball.gif"), Color.RED));
        myColorActions.add(new ColorAction("Blue", new ImageIcon("./blue-ball.gif"),
                                             Color.BLUE));

        // anonymous inner class in use here
        myExitAction = new AbstractAction(EXIT_STRING, new ImageIcon("./exit.gif")) {
            
            /** A generated serialization ID. */
            private static final long serialVersionUID = -3641127125217134863L;

            @Override
            public void actionPerformed(final ActionEvent theEvent) {
                dispose(); // close this Window
            }
        };

        myExitAction.putValue(Action.SHORT_DESCRIPTION, EXIT_STRING);
        myExitAction.putValue(Action.ACCELERATOR_KEY,
                                KeyStroke.getKeyStroke('Q',
                                                       java.awt.event.InputEvent.CTRL_MASK));
    }

    /**
     * @return a fully-stocked tool bar.
     */
    private JToolBar createToolBar() {
        final JToolBar bar = new JToolBar();
        bar.add(myExitAction);
        bar.addSeparator();

        for (final ColorAction ca : myColorActions) {
            bar.add(ca);
        }

        return bar;
    }

    /**
     * @return a fully-stocked menu bar.
     */
    private JMenuBar createMenuBar() {
        final JMenuBar menuBar1 = new JMenuBar();

        // setup the file menu
        final JMenu fileMenu1 = new JMenu("File");
        fileMenu1.add(myExitAction);
        menuBar1.add(fileMenu1);

        // setup the color menu
        final JMenu colorMenu = new JMenu("Color");

        for (final ColorAction ca : myColorActions) {
            colorMenu.add(ca);
        }
        menuBar1.add(colorMenu);

        return menuBar1;
    }

    // main()

    /**
     * Creates and makes visible a ToolBarFrame.
     * 
     * @param theArgs Command line arguments, ignored.
     */
    public static void main(final String... theArgs) {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                final ToolBarFrame toolbarFrame = new ToolBarFrame();
                toolbarFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                toolbarFrame.setVisible(true);
            }
        });
    }
    
    
    
    

    // inner classes

    /**
     * Sets the background of the panel to the specified color.
     */
    private class ColorAction extends AbstractAction {
        
        /** A generated serialization ID. */
        private static final long serialVersionUID = 5378597116905801274L;
        
        /** The color to use. */
        private final Color myColor;

        /**
         * Constructs an action with the specified name and icon to set the
         * panel to the specified color.
         * 
         * @param theName The name.
         * @param theIcon The icon.
         * @param theColor The color.
         */
        ColorAction(final String theName, final Icon theIcon, final Color theColor) {
            super(theName, theIcon);
            putValue(Action.SHORT_DESCRIPTION, theName + " background");
            myColor = theColor;
        }

        /**
         * Sets the panel to the specified color.
         * 
         * {@inheritDoc}
         */
        @Override
        public void actionPerformed(final ActionEvent theEvent) {
            myPanel.setBackground(myColor);
        }
    }

}
