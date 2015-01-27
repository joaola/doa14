using System;
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
    public class LinkedList
    {
        private Node head;

        //Printar alla noder
        public void printAllNodes()
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
            Node toAdd = new Node();

            toAdd.data = T;
            toAdd.next = head;

            head = toAdd;
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
                Node toAdd = new Node();
                toAdd.data = T;

                Node current = head;
                while (current.next != null)
                {
                    current = current.next;
                }

                current.next = toAdd;
            }
        }

        //Kontrollerar om listan är tom
        public bool isEmpty()
        {
            if (head == null)
            {
                return true;
            }
            return false;
        }

        //Rensar listan
        public void Clear()
        {
            while (this.isEmpty()==true)
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

        public void Find()
        {
            
        }

        public void Remove()
        {
            
        }

        public void RemoveFirst()
        {
            
        }

        public void RemoveLast()
        {
            
        }
    }
}
