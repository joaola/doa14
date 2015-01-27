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
            myList1.printAllNodes();

            Console.WriteLine();
            Console.WriteLine("Add Last:");
            LinkedList myList2 = new LinkedList();

            //AddLast & printAllNodes
            myList2.AddLast("Tjabba");
            myList2.AddLast("Tjena");
            myList2.AddLast("Hallå");
            myList2.printAllNodes();

            //Contains
            Console.WriteLine();
            Console.WriteLine("myList2.Contains(\"Yo\"): ");
            Console.WriteLine(myList2.Contains("Yo"));

            //isEmpty
            Console.WriteLine();
            Console.WriteLine("myList.isEmpty(): ");
            Console.WriteLine(myList2.isEmpty());

            Console.ReadLine();
        }
    }
}
