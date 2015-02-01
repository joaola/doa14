using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;
using NUnit.Framework.Constraints;

namespace LinkedList
{
    [TestFixture]
    class Test
    {
        [Test]
        public void ListTest()
        {
            LinkedList myList1 = new LinkedList();
            myList1.AddLast(1);
            myList1.AddLast(2);
            myList1.AddLast(3);
            myList1.AddLast(4);
            myList1.AddLast(5);
            myList1.AddLast(6);
            Assert.AreEqual(true, myList1.Contains(3));
            Assert.AreEqual(1, myList1.First().data);
            Assert.AreEqual(6, myList1.Last().data);
            myList1.Remove(2);
            Assert.AreEqual(false, myList1.Contains(2));
            myList1.RemoveLast();
            Assert.AreEqual(5,myList1.Last().data);
            myList1.RemoveFirst();
            Assert.AreEqual(3,myList1.First().data);
            Assert.AreEqual(3, myList1.Find(3).data);
            myList1.Clear();
            Assert.AreEqual(true, myList1.isEmpty());
        }
    }
}
