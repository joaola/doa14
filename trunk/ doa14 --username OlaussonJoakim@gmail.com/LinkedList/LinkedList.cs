using System;
using System.CodeDom;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace LinkedList
{
    //Dubbellänkade list-klassen
    public class LinkedList
    {
        private Node head;

        public Object this[int i]
        {
            get
            {
                Node n = this.head;
                for (int j = 0; j < i; j++)
                {
                    n = n.next;
                }
                return n.data;
            }
            set
            {
                Node n = this.head;
                for (int j = 0; j< i; j++)
                {
                    n = n.next;
                }
                n.data = value;
            }
        }

        //Printar alla noder
        public void printAll()
        {
            Node current = head;
            while (current != null)
            {
                Console.WriteLine(current.data);
                current = current.next;
            }
        }

        //Lägger till ett objekt först i listan
        public void AddFirst(Object T)
        {
            Node n = new Node();
            n.data = T;
            n.next = head;
            head = n;
        }

        //Lägger till ett objekt sist i listan
        public void AddLast(Object T)
        {
            if (head == null)
            {
                head = new Node();
                head.data = T;
                head.next = null;
            }
            else
            {
                Node n = new Node();
                n.data = T;
                Node current = head;
                while (current.next != null)
                {
                    current = current.next;
                }
                current.next = n;
            }
        }

        //Kontrollerar om listan är tom
        public bool isEmpty()
        {
            return head == null;
        }

        //Rensar listan
        public void Clear()
        {
            while (!this.isEmpty())
            {
                this.RemoveFirst();
            }
            return;
        }

        //Kollar om objektet finns i listan
        public bool Contains(Object T)
        {
            Node n = this.head;
            while(n != null)
            {
                Object d = n.data;
                if (d.Equals(T) == true)
                {
                    return true;
                }
                n = n.next;
            }
            return false;
        }

        //Hittar ett element
        public Node Find(Object T)
        {
            Node n = head;
            while (n != null)
            {
                if (n.data.Equals(T))
                {
                    return n;
                }
                n = n.next;
            }
            return null;
        }

        //Tar bort ett element
        /*GÖRA KLART SENARE!!*/
        public void Remove(Object T)
        {
        }

        //Tar bort första elementet
        public void RemoveFirst()
        {
            Node n = head;
            if (head.next == null)
            {
                head = null;
            }
            else
            {
                n.next.prev = null;
                head = head.next;
            }
        }

        //Tar bort sista elementet
        /*GÖRA KLART SENARE!!*/
        public void RemoveLast() 
        {
            Node n = head;
            while (n.next != null)
            {
                n = n.next;
            }
            Remove(n);
        }
    }
}
