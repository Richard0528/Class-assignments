/*
 * TCSS 305 PowerPaint Line Action  
 */
package action;

import gui.PowerPaintPanel;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.net.URL;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.ImageIcon;
import tools.Line;
import tools.Tool;

/**
 * The Action which occurs when Line is selected.
 * 
 * @author richardyang
 * @version 11.9
 */
public class LineAction extends AbstractAction {

    /** A generated serialization ID. */
    private static final long serialVersionUID = -7354988018765754824L;
   
    /** The JPanel to associate with line Action. */
    private final PowerPaintPanel myPanel;
    
    /** The selected tool. */
    private final Tool myTool;

    /**
     * Construct this Action.
     * 
     * @param thePanel a JPanel to associate with line Action.
     */
    public LineAction(final PowerPaintPanel thePanel) {
        super("Line");
        myPanel = thePanel;
        final URL url = getClass().getResource("/line.gif");
        putValue(Action.MNEMONIC_KEY, KeyEvent.VK_L);
        putValue(Action.SELECTED_KEY, true);
        putValue(Action.SMALL_ICON, new ImageIcon(url));
        myTool = new Line();
    }

    @Override
    public void actionPerformed(final ActionEvent theEvent) {
        myPanel.setCurrentTool(myTool);
//        myPanel.repaint();
    }
}
