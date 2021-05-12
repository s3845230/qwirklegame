# APT Team Five Group Report
Authors: Yonas Sisay, Lachlan Stavrevski, David Morrin, and Roman O'Brien.

## LinkedList
*reasons for where the linkedList is used*

Our implementation of a Linked List is used in two locations:
1. List of tiles in the player's hand
2. List of tiles in the tile bag

The linked list provides a way for our program to store more than one object, in a data structure that we can easily modify and search. 

### Player's Hand
We've used it to store the `Tile` objects contained in the player's hand. Our implementation of the `LinkedList` includes a function for searching, called `getIndex()`. This is used to validate whether the player actually has the tile in their hand that they've requested to place on the board. Additionally, the advantage of the use of a linked list over a more primitive data structure is that it's resizable. This is especially important when we need to take tiles in and out of players' hands, such as when they place a tile on the board, or replace a tile, both of which remove a tile from their hand, and then add one from the tile bag.


### Tile Bag
The linked list data structure is also used to store `Tile` objects for the tile bag. The ability to remove an element from the list is critical to our implementation of the tile bag. In an analogue to a physical bag of tiles, new tiles are chosen from the top, and then removed from the bag. As a component of the `TileBag::popTile()` method, the `LinkedList::remove_front()` method allows us to delete the front node (tile) after accessing its value, ensuring that the tile cannot be chosen again, and thus there are not unwanted duplicates of tiles being distributed. This function also allows us to run certain logical arguments against the number of tiles left in the tile bag - such as to determine whether it's the first turn of the game or not - by using `LinkedList::size()`.


## Abstract Data Types
*and how these lead to a "well designed" program*

## Efficiency of Implementation
*such as efficiency of data structures*

## Explanation of Tests

## Coordination and Management
