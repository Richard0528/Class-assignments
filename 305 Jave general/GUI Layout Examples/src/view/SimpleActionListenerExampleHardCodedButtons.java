package view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * Demonstrating ActionListeners.
 * 
 * @author Charles Bryan
 * @version 1.1
 */
public class SimpleActionListenerExampleHardCodedButtons extends JPanel {

    /**  A generated serial version UID for object Serialization. */
    private static final long serialVersionUID = -1155574959121887493L;
    
    /** Red Quote. */
    private static final String RED_QUOTE = "Paint the town Red";
    
    /** Blue Quote. */
    private static final String BLUE_QUOTE = "You're my boy Blue.";
    
    /** Green Quote. */
    private static final String GREEN_QUOTE = "It's not easy being Green";
    
    /** A button to change the paint the town Red. */
    private final JButton myRedButton;
    
    /** A button to sing the Blues. */
    private final JButton myBlueButton;
    
    /** A button to be Kermits friend. */
    private final JButton myGreenButton;
    
    /** A label to display the quote. */
    private final JLabel myQuoteLabel;

    /**
     * Initializes all of the fields.
     */
    public SimpleActionListenerExampleHardCodedButtons() {
        super();

        myRedButton = new JButton("Red");
        myBlueButton = new JButton("Blue");
        myGreenButton = new JButton("Green");
        myQuoteLabel = new JLabel("Quote of the Month");
    }
    
    /**
     * Lay out the components and makes this frame visible.
     */
    public void setUpComponents() {
        
        /**
         * This is an example of a Local Inner class. This class
         * is created HERE in THIS method. Think about what/where
         * has access to it. Where are the viable locations that one
         * can instantiate a BlueButtonListener?
         * @author Charles Bryan
         * @version 1.1
         */
        class BlueButtonListener implements ActionListener {

            @Override
            public void actionPerformed(final ActionEvent theEvent) {
                myQuoteLabel.setText(BLUE_QUOTE);
                myQuoteLabel.setForeground(Color.BLUE); 
            } 
        }
        //Add a BlueButtonListener to myBlueButton to listen for clicks
        myBlueButton.addActionListener(new BlueButtonListener());
        
        
        //Create and anonymous Inner Class directly as an argument
        //to the parameter of addActionListener(). This takes all
        //of the steps from the other processes and puts them all 
        //into one location. 
        myGreenButton.addActionListener(new ActionListener() {
            
            @Override
            public void actionPerformed(final ActionEvent theEvent) {
                myQuoteLabel.setText(GREEN_QUOTE);
                myQuoteLabel.setForeground(Color.GREEN); 
                
            }
        });
        
        //Add a RedButtonListnener (An Inner Class defined below)
        //to myRedButton.
        myRedButton.addActionListener(new RedButtonListnener());
        
        setLayout(new BorderLayout());
        
        final JPanel labelPanel = new JPanel();
        labelPanel.add(myQuoteLabel);
        add(labelPanel, BorderLayout.SOUTH);
        
        final JPanel buttonPanel = new JPanel();
        buttonPanel.add(myRedButton);
        buttonPanel.add(myBlueButton);
        buttonPanel.add(myGreenButton);
        add(buttonPanel, BorderLayout.NORTH);
    }
    
    /**
     * Creates a JFrame to demonstrate this Panel.
     * It is OK, even typical to include a main method 
     * in the same class file as a GUI for testing purposes. 
     * 
     * @param theArgs Command line arguments, ignored.
     */
    public static void main(final String[] theArgs) {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                final SimpleActionListenerExampleHardCodedButtons mainPanel = 
                                new SimpleActionListenerExampleHardCodedButtons();
                mainPanel.setUpComponents();
                
                // A size for the JFrame.
                //final Dimension frameSize = new Dimension(400, 400);
                
                final JFrame window = new JFrame("Demo ActionListener");
                window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                window.setContentPane(mainPanel);
                //window.setSize(frameSize);
                window.pack();
                window.setVisible(true);
            }
        });
    }
    
    /**
     * An Inner class that is an ActionListener for Button clicks. 
     * 
     * @author Charles Bryan
     * @version 1.1
     */
    class RedButtonListnener implements ActionListener {

        @Override
        public void actionPerformed(final ActionEvent theEvent) {
            myQuoteLabel.setText(RED_QUOTE);
            myQuoteLabel.setForeground(Color.RED); 
        }
        
    }

}