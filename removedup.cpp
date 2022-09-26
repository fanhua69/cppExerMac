
/*

public static void deleteDups2(LinkedListNode head)
{
  2 if ( head == null ) return;
  3 LinkedListNode previous = head;
  4 LinkedListNode current = previous.next;
  5 while ( current != null )
  {
    6 LinkedListNode runner = head;
    7 while ( runner != current )
    { // Check for earlier dups
      8 if ( runner.data == current.data )
      {
        9 LinkedListNode tmp = current.next; // remove current
        10 previous.next = tmp;
        11 current = tmp; // update current to next node
        12 break; // all other dups have already been removed
        13
      }
      14 runner = runner.next;
      15
    }
    16 if ( runner == current )
    { // current not updated - update now
      17 previous = current;
      18 current = current.next;
      19
    }
    20
  }
  21
}*/