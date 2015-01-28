using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Remoting.Messaging;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace LinkedList
{
    //Nodklassen
    public class Node
    {
        public Node next;
        public Node prev;
        public Object data;
        
        //Konstruktor
        public Node()
        {
            next = prev = null;
        }

        //Konstruktor
        public Node(Object T)
        {
            this.data = T;
        }
        ~Node()
        {

        }
    }

}
