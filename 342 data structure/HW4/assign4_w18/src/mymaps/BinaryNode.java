package mymaps;


//Basic node stored in unbalanced binary search trees
//Note that this class is not accessible outside
//of this package.

class BinaryNode<AnyKey, AnyValue>
{
     // Constructor
 BinaryNode( AnyKey theKey, AnyValue theElement )
 {
	 key = theKey;
     element = theElement;
     left = right = null;
 }

   // Data; accessible by other package routines
 AnyKey             key;  // The key in the node
 AnyValue           element;  // The data in the node
 BinaryNode<AnyKey, AnyValue> left;     // Left child
 BinaryNode<AnyKey, AnyValue> right;    // Right child
}
