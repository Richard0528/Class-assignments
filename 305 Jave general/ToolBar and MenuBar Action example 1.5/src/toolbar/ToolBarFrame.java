/*
 * ToolBarFrame TCSS 305
 */

/*
 * This example shows the combined use of Buttons, Actions, and ButtonGroups.
 */

package toolbar;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.List;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.ButtonGroup;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JToggleButton;
import javax.swing.JToolBar;
import javax.swing.KeyStroke;

/**
 * A frame that uses a menu bar and Toolbar to change colors.
 * 
 * @author Alan Fowler based on an original program by Cay Horstmann
 * @version 1.4
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
        super("Buttons with Actions");
        
        setupActions(); // initializes myActions

        final JToolBar toolBar1 = createToolBar();
        add(toolBar1, BorderLayout.SOUTH);
        
        setJMenuBar(createMenuBar());

        myPanel = new JPanel();
        add(myPanel, BorderLayout.CENTER);
        
        // There are several ways to set the size of the GUI
        
        // you can set the size of the frame
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        
        // or you can set the size of the panel and then pack() the frame around it
//        myPanel.setPreferredSize(new Dimension(DEFAULT_WIDTH, DEFAULT_HEIGHT));
//        pack();

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
                // do NOT call System.exit()
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
        
        
        final ButtonGroup btngrp = new ButtonGroup();
        for (final ColorAction ca : myColorActions) {
            final JToggleButton tb = new JToggleButton(ca);
            btngrp.add(tb);
            bar.add(tb);
        }
        
        btngrp.clearSelection();

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
        final ButtonGroup btngrp = new ButtonGroup();

        for (final ColorAction ca : myColorActions) {
            final JRadioButtonMenuItem btn = new JRadioButtonMenuItem(ca);
            btngrp.add(btn);
            colorMenu.add(btn);
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
//            super(theName, theIcon);
            super(theName);
            
            // small icons are usually assigned to the menu
            putValue(Action.SMALL_ICON, theIcon);
            
            // Here is how to assign a larger icon to the tool bar.
            final ImageIcon icon = (ImageIcon) theIcon;
            final Image largeImage =
                icon.getImage().getScaledInstance(15, -1, java.awt.Image.SCALE_SMOOTH);
            final ImageIcon largeIcon = new ImageIcon(largeImage);
            putValue(Action.LARGE_ICON_KEY, largeIcon);
            
            // set a mnemonic on the first character of the name
            putValue(Action.MNEMONIC_KEY,
                     KeyEvent.getExtendedKeyCodeForChar(theName.charAt(0)));
            
            // tool tips
            putValue(Action.SHORT_DESCRIPTION, theName + " background");
            
            // coordinate button selection
            putValue(Action.SELECTED_KEY, true);
            
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
