using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedList
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Add First:");
            LinkedList myList1 = new LinkedList();

            //AddFirst & printAllNodes
            myList1.AddFirst("Tjabba");
            myList1.AddFirst("Tjena");
            myList1.AddFirst("Hallå");
            myList1.printAll();

            Console.WriteLine();
            Console.WriteLine("Add Last:");
            LinkedList myList2 = new LinkedList();

            //AddLast & printAllNodes
            myList2.AddLast("Tjabba");
            myList2.AddLast("Tjena");
            myList2.AddLast("Hallå");
            myList2.printAll();

            //Contains
            Console.WriteLine();
            Console.WriteLine("myList2.Contains(\"Yo\"): ");
            Console.WriteLine(myList2.Contains("Yo"));

            //isEmpty
            Console.WriteLine();
            Console.WriteLine("myList2.isEmpty(): ");
            Console.WriteLine(myList2.isEmpty());

            //Clear & isEmpty
            Console.WriteLine();
            Console.WriteLine("myList2.clear() == empty?: ");
            myList2.Clear();
            Console.WriteLine(myList2.isEmpty());
            
            //RemoveFirst
            Console.WriteLine();
            Console.WriteLine("myList1.RemoveFirst");
            myList1.RemoveFirst();
            myList1.printAll();

            //RemoveLast 
            Console.WriteLine();
            Console.WriteLine("myList1.RemoveLast");
            myList1.RemoveLast();
            myList1.printAll();

            //Remove
            Console.WriteLine();
            Console.WriteLine("myList1.Remove()");
            myList1.Remove("Tjena");
            myList1.printAll();

            Console.ReadLine();
        }
    }
}
