/**
 * TCSS 305 - Assignment 5: PowerPaint
 */
package gui;

import java.awt.Color;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.net.URL;
import javax.swing.Action;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JCheckBox;
import javax.swing.JColorChooser;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JSlider;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

/**
 * The JMenuBar for PowerPaint.
 * 
 * @author richardyang
 * @version 11.9
 */
public class PowerPaintMenuBar extends JMenuBar implements PropertyChangeListener {

    /** A generated serialization ID. */
    private static final long serialVersionUID = -4869607631836293106L;
    
    /** The minor thickness spacing for thickness slider. */
    private static final int MINOR_THICKNESS_SPACING = 1;

    /** The maximum thickness spacing for thickness slider. */
    private static final int MAX_THICKNESS = 25;

    /** The initial thickness spacing for thickness slider. */
    private static final int INITIAL_THICKNESS = 5;

    /** The thickness spacing for thickness slider. */
    private static final int THICKNESS_SPACING = 5;
    
    /** The color to fill. */
    private static final Color UW_GOLD = new Color(232, 211, 162);
    
    /** The default color to paint with. */
    private static final Color UW_PURPLE = new Color(51, 0, 111);

    /** the Options menu. */
    private final JMenu myOptionMenu;
    
    /** the Tools menu. */
    private final JMenu myToolMenu;
    
    /** the Help menu. */
    private final JMenu myHelpMenu;
    
    /** the Clear Button. */
    private final JMenuItem myClearButton;
    
    /** A button group for radio buttons. */
    private final ButtonGroup myGroup;
    
    /** A slider to change the thickness. */
    private final JSlider myThickness;

    /** A power paint panel. */
    private final PowerPaintPanel myPanel;

    /**
     * Construct the menu bar.
     * 
     * @param thePanel paint panel
     */
    public PowerPaintMenuBar(final PowerPaintPanel thePanel) {
        super();
        myPanel = thePanel;
        myOptionMenu = new JMenu("Options");
        myToolMenu = new JMenu("Tools");
        myHelpMenu = new JMenu("Help");
        myClearButton = new JMenuItem("Clear");
        myClearButton.setEnabled(false);
        myGroup = new ButtonGroup();
        
        myThickness = new JSlider(SwingConstants.HORIZONTAL, 0, MAX_THICKNESS,
                                                       INITIAL_THICKNESS);
        start();
    }



    /**
     * Sets up the components of the menu.
     */
    private void start() {
        
        final JMenu thickButton = new JMenu("Thickness");
        final JMenuItem drawColorButton = new JMenuItem("Draw Color...");
        final JMenuItem fillColorButton = new JMenuItem("Fill Color...");
        final JCheckBox fillButton = new JCheckBox("Fill");
        
        myOptionMenu.setMnemonic(KeyEvent.VK_O);
        myToolMenu.setMnemonic(KeyEvent.VK_T);
        myHelpMenu.setMnemonic(KeyEvent.VK_H);  
        
        myThickness.setMajorTickSpacing(THICKNESS_SPACING);
        myThickness.setMinorTickSpacing(MINOR_THICKNESS_SPACING);
        myThickness.setPaintLabels(true);
        myThickness.setPaintTicks(true);
        myThickness.addChangeListener(new ChangeListener() {
            /** Called in response to slider events in this window. */
            @Override
            public void stateChanged(final ChangeEvent theEvent) {
                final int width = myThickness.getValue();
                myPanel.setMyLineWidth(width);
            }
        });

        drawColorButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(final ActionEvent theEvent) {
                final Color result = JColorChooser.showDialog(null, 
                                                   "Select a draw color", UW_PURPLE);
                myPanel.setMyDrawColor(result);
            }
        });

        fillColorButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(final ActionEvent theEvent) {
                final Color result = JColorChooser.showDialog(null, 
                                                     "Select a fill color", UW_GOLD);
                myPanel.setMyFillColor(result);
            }
        });

        fillButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(final ActionEvent theEvent) {
                final boolean fillable = fillButton.isSelected();
                myPanel.setMyFillable(fillable);
            }
        });

        myClearButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(final ActionEvent theEvent) {
                myPanel.getMyDrawPath().clear();
                myPanel.clear();
                myClearButton.setEnabled(false);
            }
        });
        
        setUpHelp();
        
        myOptionMenu.add(thickButton);
        thickButton.add(myThickness);
        myOptionMenu.addSeparator();
        myOptionMenu.add(drawColorButton);
        myOptionMenu.add(fillColorButton);
        myOptionMenu.addSeparator();
        myOptionMenu.add(fillButton);
        myOptionMenu.addSeparator();
        myOptionMenu.add(myClearButton);
        
        add(myOptionMenu);
        add(myToolMenu);
        add(myHelpMenu);
        
    }

    /**
     * Creates a radio button menu item, associates an action with the button.
     * 
     * @param theAction the Action to associate with the new button being created
     */
    public void createMenuButton(final Action theAction) {
        final JRadioButtonMenuItem createdButton = new JRadioButtonMenuItem(theAction);

        myGroup.add(createdButton);
        myToolMenu.add(createdButton);
    }

    /**
     * Set up the help menu.
     */
    private void setUpHelp() {
        final JMenuItem about = new JMenuItem("About...");
        about.setMnemonic(KeyEvent.VK_A);
        myHelpMenu.add(about);
        
        about.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(final ActionEvent theEvent) {
                final URL url = getClass().getResource("/w.gif");
                final ImageIcon img = new ImageIcon(url);
                final Image newImg = img.getImage().getScaledInstance(80, 50, 
                                                         java.awt.Image.SCALE_SMOOTH);
                final ImageIcon wImg = new ImageIcon(newImg);
                
                JOptionPane.showMessageDialog(null, "TCSS 305 PowerPaint \nAutumn 2017 "
                                              + "\nZhihao Yang", 
                                              "About", JOptionPane.INFORMATION_MESSAGE, wImg);
            }
        });    
        
    }
    
    @Override
    public void propertyChange(final PropertyChangeEvent theEvent) {
        if ("clearorder".equals(theEvent.getPropertyName())) {
            myClearButton.setEnabled((boolean) theEvent.getNewValue());
            
        }  
    }
    

}
    
