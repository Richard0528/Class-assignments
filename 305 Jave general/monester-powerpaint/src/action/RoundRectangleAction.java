/* 
 * TCSS 305 PowerPaint Round Rectangle Action
 */
package action;

import gui.PowerPaintPanel;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.net.URL;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.ImageIcon;
import tools.RoundRectangle;
import tools.Tool;

/**
 * The Action which occurs when RoundRectangle is selected.
 * 
 * @author richardyang
 * @version 11.9
 */
public class RoundRectangleAction extends AbstractAction {

    /** A generated serialization ID. */
    private static final long serialVersionUID = 3307256141504242050L;
   
    /** The JPanel to associate with rectangle Action. */
    private final PowerPaintPanel myPanel;
    
    /** The selected tool. */
    private final Tool myTool;

    /**
     * Construct this Action.
     * 
     * @param thePanel a JPanel to associate with rectangle Action.
     */
    public RoundRectangleAction(final PowerPaintPanel thePanel) {
        super("RoundRectangle");
        myPanel = thePanel;
        final URL url = getClass().getResource("/roundrectangle.gif");
        putValue(Action.MNEMONIC_KEY, KeyEvent.VK_U);
        putValue(Action.SELECTED_KEY, true);
        putValue(Action.SMALL_ICON, new ImageIcon(url));
        myTool = new RoundRectangle();
    }

    @Override
    public void actionPerformed(final ActionEvent theEvent) {
        myPanel.setCurrentTool(myTool);
    }

}
