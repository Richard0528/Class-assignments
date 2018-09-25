/*
 * TCSS 305 PowerPaint Ellipse Action 
 */
package action;

import gui.PowerPaintPanel;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.net.URL;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.ImageIcon;
import tools.Ellipse;
import tools.Tool;

/**
 * The Action which occurs when Ellipse is selected.
 * 
 * @author richardyang
 * @version 11.9
 */
public class EllipseAction extends AbstractAction {

    /** A generated serialization ID. */
    private static final long serialVersionUID = -459892809110264928L;
       
    /** The JPanel to associate with rectangle Action. */
    private final PowerPaintPanel myPanel;
    
    /** The selected tool. */
    private final Tool myTool;

    /**
     * Construct this Action.
     * 
     * @param thePanel a JPanel to associate with rectangle Action.
     */
    public EllipseAction(final PowerPaintPanel thePanel) {
        super("Ellipse");
        myPanel = thePanel;
        final URL url = getClass().getResource("/ellipse.gif");
        putValue(Action.MNEMONIC_KEY, KeyEvent.VK_E);
        putValue(Action.SELECTED_KEY, true);
        putValue(Action.SMALL_ICON, new ImageIcon(url));
        myTool = new Ellipse();
    }

    @Override
    public void actionPerformed(final ActionEvent theEvent) {
        myPanel.setCurrentTool(myTool);
    }

}
