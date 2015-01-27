using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace LinkedList
{
    public class Node
    {
        public Node next;
        public Object data;

        public Node()
        {
            
        }

        public Node(Object T)
        {
            this.data = T;
        }
    }
}
