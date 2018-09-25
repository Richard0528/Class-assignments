package view;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import model.DoSomething;
import model.QuoteToErrObject;
import model.QuoteToOptionPaneObject;
import model.QuoteToOutObject;

/**
 * Demonstrating ActionListeners.
 * 
 * @author Charles Bryan
 * @version 1.1
 */
public class SimpleActionListenerExampleDyamiclyCreatedButtons extends JPanel {

    /**  A generated serial version UID for object Serialization. */
    private static final long serialVersionUID = -1155574959121887493L;
    
    /** Red Quote. */
    private static final String RED_QUOTE = "Paint the town Red";
    
    /** Blue Quote. */
    private static final String BLUE_QUOTE = "You're my boy Blue.";
    
    /** Green Quote. */
    private static final String GREEN_QUOTE = "It's not easy being Green";
    
    /** A list of buttons that are displayed in this GUI. */
    private final List<JButton> myButtons;

    /** A label to display the quote. */
    private final JLabel myQuoteLabel;

    /**
     * Initializes all of the fields.
     */
    public SimpleActionListenerExampleDyamiclyCreatedButtons() {
        super();
 
        //Create a list of the objects in Model as defined by their 
        //interface type. (Polymorphism)
        final List<DoSomething> doSomethingObjects = new ArrayList<>();
        doSomethingObjects.add(new QuoteToErrObject("Red", RED_QUOTE));
        doSomethingObjects.add(new QuoteToOutObject("Blue", BLUE_QUOTE));
        doSomethingObjects.add(new QuoteToOptionPaneObject("Green", GREEN_QUOTE));
        
        //Create a list of JButtons based on the list of Model Objects. 
        myButtons = new ArrayList<>();
        for (final DoSomething doSomething : doSomethingObjects) {
            myButtons.add(createButton(doSomething));
        }

        myQuoteLabel = new JLabel("Quote of the Month");
    }
    
    /**
     * Lay out the components and makes this frame visible.
     */
    public void setUpComponents() {

        setLayout(new BorderLayout());
        
        final JPanel labelPanel = new JPanel();
        labelPanel.add(myQuoteLabel);
        add(labelPanel, BorderLayout.SOUTH);
        
        final JPanel buttonPanel = new JPanel();
        //add all of the buttons to the panel
        for (final JButton b : myButtons) {
            buttonPanel.add(b);
        }

        add(buttonPanel, BorderLayout.NORTH);
    }
    
    /**
     * This method instantiates JButtons based of information
     * provided from classes in the Model Package. Each 
     * DoSomethingObject sent in as an argument defines
     * what is displayed on the button AND what the button
     * does when clicked. 
     * 
     * @param theObject the object from Model that sets up this button.
     * @return a button based on theObject. 
     */
    private JButton createButton(final DoSomething theObject) {
        final JButton button = new JButton(theObject.toString());
        
        //Add an anonymous inner class to this button. 
        button.addActionListener(new ActionListener() {
            
            @Override
            public void actionPerformed(final ActionEvent theEvent) {
                //when the button is clicked, do something. 
                theObject.doSomething();  
            }
        });
        
        return button;
    }
    
    /**
     * Creates a JFrame to demonstrate this panel.
     * It is OK, even typical to include a main method 
     * in the same class file as a GUI for testing purposes. 
     * 
     * @param theArgs Command line arguments, ignored.
     */
    public static void main(final String[] theArgs) {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                final SimpleActionListenerExampleDyamiclyCreatedButtons mainPanel = 
                                new SimpleActionListenerExampleDyamiclyCreatedButtons();
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

}