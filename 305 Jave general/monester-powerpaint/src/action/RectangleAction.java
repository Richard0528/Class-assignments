/*
 * TCSS 305 PowerPaint Rectangle Action
 */
package action;

import gui.PowerPaintPanel;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.net.URL;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.ImageIcon;
import tools.Rectangle;
import tools.Tool;

/**
 * The Action which occurs when Rectangle is selected.
 * 
 * @author richardyang
 * @version 11.9
 */
public class RectangleAction extends AbstractAction {
    
    /** A generated serialization ID. */
    private static final long serialVersionUID = -2253514047726849212L;
  
    /** The JPanel to associate with rectangle Action. */
    private final PowerPaintPanel myPanel;
    
    /** The selected tool. */
    private final Tool myTool;

    /**
     * Construct this Action.
     * 
     * @param thePanel a JPanel to associate with rectangle Action.
     */
    public RectangleAction(final PowerPaintPanel thePanel) {
        super("Rectangle");
        myPanel = thePanel;
        final URL url = getClass().getResource("/rectangle.gif");
        putValue(Action.MNEMONIC_KEY, KeyEvent.VK_R);
        putValue(Action.SELECTED_KEY, true);
        putValue(Action.SMALL_ICON, new ImageIcon(url));
        myTool = new Rectangle();
    }

    @Override
    public void actionPerformed(final ActionEvent theEvent) {
        myPanel.setCurrentTool(myTool);
    }

}
