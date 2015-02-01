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
        //Första objektet i listan
        public Node First()
        {
            if (head == null)
            {
                throw new Exception("Listan är tom");
            }
            else
                return this.head;
        }

        //Sista objektet i listan
        public Node Last()
        {
            Node n = this.head;
            while (n.next != null)
            {
                n = n.next;
            }
            return n;
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
            if (head.next != null)
            {
                head.next.prev = head; 
            }

        }

        //Lägger till ett objekt sist i listan
        public void AddLast(Object T)
        {
            if (head == null)
            {
                head = new Node();
                head.data = T;
                head.next = null;
                head.prev = null;
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
                n.prev = current;
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
            while (n != null)
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
            Node n = Find(T);
            if (n != null)
            {
                object data = n.data;
                if (n == First())
                {
                    this.RemoveFirst();
                }
                else if (n == Last())
                {
                    this.RemoveLast();
                }
                else
                {
                    n.next.prev = n.prev;
                    n.prev.next = n.next;
                }
            }
            else
            {
                return;
            }
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
        public void RemoveLast()
        {
            Node toRemove = Last();
            if (head == null)
            {
                throw new Exception("Listan är tom");
            }
            if (toRemove == head)
            {
                head = null;
            }
            else
            {
                toRemove.prev.next = null;
                toRemove.prev = null;
            }
        }
    }
}
