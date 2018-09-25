/**
 * TCSS 305 PowerPaint
 */

package gui;

import action.EllipseAction;
import action.LineAction;
import action.PencilAction;
import action.RectangleAction;
import action.RoundRectangleAction;
import java.awt.BorderLayout;
import java.awt.Toolkit;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.net.URL;
import javax.swing.Action;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import tools.Line;

/**
 * The GUI for PowerPaint.
 * 
 * @author richardyang
 * @version 11.9
 */
public final class PowerPaintGUI implements PropertyChangeListener {
    
    /** Default Line tool. */
    private final Line myLine;
    
    
   /**
    * Construct the GUI.
    */
    public PowerPaintGUI() {
        myLine = new Line();
        start();
    }
    
    /**
     * Sets up the PowerPaintGUI.
     */
    private void start() {
        
        final JFrame powerFrame = new JFrame("PowerPaint");
        final URL url = getClass().getResource("/w.gif");
        final ImageIcon icon = new ImageIcon(url);
        powerFrame.setIconImage(icon.getImage());
        
        final PowerPaintToolBar toolBar = new PowerPaintToolBar();
        final PowerPaintPanel panel = new PowerPaintPanel();
        final PowerPaintMenuBar menuBar = new PowerPaintMenuBar(panel);
        panel.setCurrentTool(myLine);
        panel.addPropertyChangeListener(menuBar);
        
        final Action[] actions = {new LineAction(panel), new PencilAction(panel) 
                        , new RectangleAction(panel), new RoundRectangleAction(panel) 
                        , new EllipseAction(panel)};

        for (final Action action : actions) {
            menuBar.createMenuButton(action);
            toolBar.createToolBarButton(action);
        }

        powerFrame.setJMenuBar(menuBar);
        powerFrame.add(toolBar, BorderLayout.SOUTH);
        powerFrame.add(panel, BorderLayout.CENTER);
        powerFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        powerFrame.pack();

        /** A ToolKit. */
        final Toolkit kit = Toolkit.getDefaultToolkit();

        powerFrame.setLocation(
            (int) (kit.getScreenSize().getWidth() / 2 - powerFrame.getWidth() / 2),
            (int) (kit.getScreenSize().getHeight() / 2 - powerFrame.getHeight() / 2));

        powerFrame.setVisible(true);

    }
    
    @Override
    public void propertyChange(final PropertyChangeEvent theEvent) {
        // Do nothing here
    }
    
    
    
}
