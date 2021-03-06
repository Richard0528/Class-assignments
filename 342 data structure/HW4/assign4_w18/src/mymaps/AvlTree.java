package mymaps;

// AvlTree class
//
// CONSTRUCTION: with no initializer
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// boolean contains( x )  --> Return true if x is present
// boolean remove( x )    --> Return true if x was present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as appropriate

/**
 * Implements an AVL tree.
 * Note that all "matching" is based on the compareTo method.
 * @author Mark Allen Weiss
 * @auther Richard Yang
 */
public class AvlTree<AnyKey extends Comparable<? super AnyKey>, AnyValue> implements MyMap<AnyKey, AnyValue>
{
    
    /** The tree root. */
    private AvlNode<AnyKey, AnyValue> root;
    
    /**
     * Construct the tree.
     */
    public AvlTree( )
    {
        root = null;
    }

    /**
     * Insert into the tree; duplicates are ignored.
     * @param x the item to insert.
     */
//    public void insert( AnyKey x )
//    {
//        root = insert( x, root );
//    }
    
    
    @Override
	public void put(AnyKey x, AnyValue y) {
		if (contains(x)) {
			find(x, root).element = y;
		} else {
			root = insert(x, y, root);
		}
	}

	@Override
	public AnyValue get(AnyKey x) {
		if (contains(x))
			return find(x, root).element;
		else
			return null;
	}
	
	@Override
	public String toString() {
		
		String result = "{";
		result += toString(root);
		result += "}";
		
		return result;
	}
	
	private String toString(AvlNode temp)
	{
	    String result = "";
	    if (temp == null)
	        return "";
	    result += toString(temp.left);
	    result += toString(temp.right);
	    if (temp == root) {
	    		result += temp.key.toString() + "=" + temp.element.toString() ;
	    } else {
	    		result += temp.key.toString() + "=" + temp.element.toString() + ", ";
	    }
	    
	    return result;
	}

    /**
     * Remove from the tree. Nothing is done if x is not found.
     * @param x the item to remove.
     */
    public void remove( AnyKey x )
    {
        root = remove( x, root );
    }

       
    /**
     * Internal method to remove from a subtree.
     * @param x the item to remove.
     * @param t the node that roots the subtree.
     * @return the new root of the subtree.
     */
    private AvlNode<AnyKey, AnyValue> remove( AnyKey x, AvlNode<AnyKey, AnyValue> t )
    {
        if( t == null )
            return t;   // Item not found; do nothing
            
        int compareResult = x.compareTo( t.key );
            
        if( compareResult < 0 )
            t.left = remove( x, t.left );
        else if( compareResult > 0 )
            t.right = remove( x, t.right );
        else if( t.left != null && t.right != null ) // Two children
        {
            t = findMin( t.right );
            t.right = remove( t.key, t.right );
        }
        else
            t = ( t.left != null ) ? t.left : t.right;
        return balance( t );
    }
    
    /**
     * Find the smallest item in the tree.
     * @return smallest item or null if empty.
     */
    public AnyKey findMin( )
    {
        if( isEmpty( ) )
            throw new IllegalStateException( );
        return findMin( root ).key;
    }

    /**
     * Find the largest item in the tree.
     * @return the largest item of null if empty.
     */
    public AnyKey findMax( )
    {
        if( isEmpty( ) )
            throw new IllegalStateException( );
        return findMax( root ).key;
    }

    /**
     * Find an item in the tree.
     * @param x the item to search for.
     * @return true if x is found.
     */
    public boolean contains( AnyKey x )
    {
        return contains( x, root );
    }

    /**
     * Make the tree logically empty.
     */
    public void makeEmpty( )
    {
        root = null;
    }

    /**
     * Test if the tree is logically empty.
     * @return true if empty, false otherwise.
     */
    public boolean isEmpty( )
    {
        return root == null;
    }

    /**
     * Print the tree contents in sorted order.
     */
    public void printTree( )
    {
        if( isEmpty( ) )
            System.out.println( "Empty tree" );
        else
            printTree( root );
    }

    private static final int ALLOWED_IMBALANCE = 1;
    
    // Assume t is either balanced or within one of being balanced
    private AvlNode<AnyKey, AnyValue> balance( AvlNode<AnyKey, AnyValue> t )
    {
        if( t == null )
            return t;
        
        if( height( t.left ) - height( t.right ) > ALLOWED_IMBALANCE )
            if( height( t.left.left ) >= height( t.left.right ) )
                t = rotateWithLeftChild( t );
            else
                t = doubleWithLeftChild( t );
        else
        if( height( t.right ) - height( t.left ) > ALLOWED_IMBALANCE )
            if( height( t.right.right ) >= height( t.right.left ) )
                t = rotateWithRightChild( t );
            else
                t = doubleWithRightChild( t );

        t.height = Math.max( height( t.left ), height( t.right ) ) + 1;
        return t;
    }
    
    public void checkBalance( )
    {
        checkBalance( root );
    }
    
    private int checkBalance( AvlNode<AnyKey, AnyValue> t )
    {
        if( t == null )
            return -1;
        
        if( t != null )
        {
            int hl = checkBalance( t.left );
            int hr = checkBalance( t.right );
            if( Math.abs( height( t.left ) - height( t.right ) ) > 1 ||
                    height( t.left ) != hl || height( t.right ) != hr )
                System.out.println( "OOPS!!" );
        }
        
        return height( t );
    }
    
    
    /**
     * Internal method to insert into a subtree.
     * @param x the item to insert.
     * @param t the node that roots the subtree.
     * @return the new root of the subtree.
     */
    private AvlNode<AnyKey, AnyValue> insert( AnyKey x, AnyValue y, AvlNode<AnyKey, AnyValue> t )
    {
        if( t == null )
            return new AvlNode<AnyKey, AnyValue>( x, y, null, null );
        
        int compareResult = x.compareTo( t.key );
        
        if( compareResult < 0 )
            t.left = insert( x, y, t.left );
        else if( compareResult > 0 )
            t.right = insert( x, y, t.right );
        else
            ;  // Duplicate; do nothing
        return balance( t );
    }

    /**
     * Internal method to find the smallest item in a subtree.
     * @param t the node that roots the tree.
     * @return node containing the smallest item.
     */
    private AvlNode<AnyKey, AnyValue> findMin( AvlNode<AnyKey, AnyValue> t )
    {
        if( t == null )
            return t;

        while( t.left != null )
            t = t.left;
        return t;
    }

    /**
     * Internal method to find the largest item in a subtree.
     * @param t the node that roots the tree.
     * @return node containing the largest item.
     */
    private AvlNode<AnyKey, AnyValue> findMax( AvlNode<AnyKey, AnyValue> t )
    {
        if( t == null )
            return t;

        while( t.right != null )
            t = t.right;
        return t;
    }
    
    /**
     * Internal method to find an item in a subtree.
     * @param x is item to search for.
     * @param t the node that roots the tree.
     * @return node containing the matched item.
     */
    private AvlNode<AnyKey, AnyValue> find( AnyKey x, AvlNode<AnyKey, AnyValue> t )
    {
        while( t != null )
        {
            if( x.compareTo( t.key ) < 0 )
                t = t.left;
            else if( x.compareTo( t.key ) > 0 )
                t = t.right;
            else
                return t;    // Match
        }

        return null;         // Not found
    }

    /**
     * Internal method to find an item in a subtree.
     * @param x is item to search for.
     * @param t the node that roots the tree.
     * @return true if x is found in subtree.
     */
    private boolean contains( AnyKey x, AvlNode<AnyKey, AnyValue> t )
    {
        while( t != null )
        {
            int compareResult = x.compareTo( t.key );
            
            if( compareResult < 0 )
                t = t.left;
            else if( compareResult > 0 )
                t = t.right;
            else
                return true;    // Match
        }

        return false;   // No match
    }

    /**
     * Internal method to print a subtree in sorted order.
     * @param t the node that roots the tree.
     */
    private void printTree( AvlNode<AnyKey, AnyValue> t )
    {
        if( t != null )
        {
            printTree( t.left );
            System.out.println( t.element );
            printTree( t.right );
        }
    }

    /**
     * Return the height of node t, or -1, if null.
     */
    private int height( AvlNode<AnyKey, AnyValue> t )
    {
        return t == null ? -1 : t.height;
    }

    /**
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then return new root.
     */
    private AvlNode<AnyKey, AnyValue> rotateWithLeftChild( AvlNode<AnyKey, AnyValue> k2 )
    {
        AvlNode<AnyKey, AnyValue> k1 = k2.left;
        k2.left = k1.right;
        k1.right = k2;
        k2.height = Math.max( height( k2.left ), height( k2.right ) ) + 1;
        k1.height = Math.max( height( k1.left ), k2.height ) + 1;
        return k1;
    }

    /**
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then return new root.
     */
    private AvlNode<AnyKey, AnyValue> rotateWithRightChild( AvlNode<AnyKey, AnyValue> k1 )
    {
        AvlNode<AnyKey, AnyValue> k2 = k1.right;
        k1.right = k2.left;
        k2.left = k1;
        k1.height = Math.max( height( k1.left ), height( k1.right ) ) + 1;
        k2.height = Math.max( height( k2.right ), k1.height ) + 1;
        return k2;
    }

    /**
     * Double rotate binary tree node: first left child
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then return new root.
     */
    private AvlNode<AnyKey, AnyValue> doubleWithLeftChild( AvlNode<AnyKey, AnyValue> k3 )
    {
        k3.left = rotateWithRightChild( k3.left );
        return rotateWithLeftChild( k3 );
    }

    /**
     * Double rotate binary tree node: first right child
     * with its left child; then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, then return new root.
     */
    private AvlNode<AnyKey, AnyValue> doubleWithRightChild( AvlNode<AnyKey, AnyValue> k1 )
    {
        k1.right = rotateWithLeftChild( k1.right );
        return rotateWithRightChild( k1 );
    }

    private static class AvlNode<AnyKey, AnyValue>
    {
            // Constructors
        AvlNode( AnyKey theKey, AnyValue theElement )
        {
            this( theKey, theElement, null, null );
        }

        AvlNode( AnyKey theKey, AnyValue theElement, AvlNode<AnyKey, AnyValue> lt, AvlNode<AnyKey, AnyValue> rt )
        {
            key = theKey;
        		element  = theElement;
            left     = lt;
            right    = rt;
            height   = 0;
        }
        
        AnyKey             key;
        AnyValue           element;      // The data in the node
        AvlNode<AnyKey, AnyValue>  left;         // Left child
        AvlNode<AnyKey, AnyValue>  right;        // Right child
        int               height;       // Height
    }

        // Test program
//    public static void main( String [ ] args )
//    {
//        AvlTree<Integer> t = new AvlTree<>( );
//        final int SMALL = 40;
//        final int NUMS = 1000000;  // must be even
//        final int GAP  =   37;
//
//        System.out.println( "Checking... (no more output means success)" );
//
//        for( int i = GAP; i != 0; i = ( i + GAP ) % NUMS )
//        {
//        //    System.out.println( "INSERT: " + i );
//            t.insert( i );
//            if( NUMS < SMALL )
//                t.checkBalance( );
//        }
//        
//        for( int i = 1; i < NUMS; i+= 2 )
//        {
//         //   System.out.println( "REMOVE: " + i );
//            t.remove( i );
//            if( NUMS < SMALL )
//                t.checkBalance( );
//        }
//        if( NUMS < SMALL )
//            t.printTree( );
//        if( t.findMin( ) != 2 || t.findMax( ) != NUMS - 2 )
//            System.out.println( "FindMin or FindMax error!" );
//
//        for( int i = 2; i < NUMS; i+=2 )
//             if( !t.contains( i ) )
//                 System.out.println( "Find error1!" );
//
//        for( int i = 1; i < NUMS; i+=2 )
//        {
//            if( t.contains( i ) )
//                System.out.println( "Find error2!" );
//        }
//    }
	
}
