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

            myList1.AddFirst("Tjabba");
            myList1.AddFirst("Tjena");
            myList1.AddFirst("Hallå");
            myList1.printAllNodes();

            Console.WriteLine();

            Console.WriteLine("Add Last:");
            LinkedList myList2 = new LinkedList();

            myList2.AddLast("Yo");
            myList2.AddLast("Walla");
            myList2.AddLast("'sup");
            myList2.printAllNodes();

            Console.WriteLine();
            Console.WriteLine("myList1.Contains('Tjena')?: ");
            Console.WriteLine(myList2.Contains("Tjena"));

            LinkedList myList3 = new LinkedList();



            Console.ReadLine();
        }
    }
}
