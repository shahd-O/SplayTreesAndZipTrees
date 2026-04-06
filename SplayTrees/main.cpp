#include "ZipTree.h"
#include "SplayTree.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

void SplayTests() {
    SplayTree tree;

    for (int i = 1; i <= 20; i++)
        tree.insert(i);

    if (tree.isValid(tree.getRoot(), INT_MIN, INT_MAX))
        cout << "PASS: Tree is valid after inserts." << endl;
    else
        cout << "FAIL: BST or parent pointers violated!" << endl;
    tree.access(15);
    tree.access(20);

    if (tree.isValid(tree.getRoot(), INT_MIN, INT_MAX))
        cout << "PASS: Tree valid after accesses." << std::endl;
}

void ZipTests()

{
    ZipTree tree;

    cout << "Testing sequential insertion..." << endl;
    for (int i = 1; i <= 20; i++) {
        tree.insert(i);
    }
    if (tree.isValid(tree.getRoot(), -1e9, 1e9))
        cout << "PASS: Sequential tree is valid." << endl;
    else
        cout << "FAIL: Rank/BST invariants violated!" << endl;
    tree.printPreOrder();
    cout << endl;
    tree.Printinorder();

    cout << "Testing deletion..." << endl;
    tree.remove(10);
    cout << endl;
    tree.Printinorder();
    tree.remove(15);
    cout << endl;
    tree.Printinorder();
    tree.remove(20);
    cout << endl;
    tree.Printinorder();
    if (tree.isValid(tree.getRoot(), -1e9, 1e9))
        cout << "PASS: Tree valid after deletions." << endl;
    else
        cout << "FAIL: Zip operation broke invariants!" << endl;
}




int main() {

   //runTests();

   //SplayTree st;
   // int keys[] = { 10, 20, 30, 40, 50 };
    //for (int k : keys) st.insert(k);


   /*
     for (int i = 0; i < 1000; i++) {
        int val = rand() % 5000;
        st.insert(val);
        if (i % 10 == 0) 
            st.deleteNode(val);
        if (i % 2 == 0)
            st.deleteNode(val);
        if (i % 7 == 0)
            st.deleteNode(val);
    }


    st.printInOrder();
   */

  //SplayTests();
  //testing access


    int N = 100000;

    //testing the running time on sequential inserts: initially bad for Splay Trees before rebalancing, zip trees are expected to maintain probabil balance
    /*
            SplayTree stree;
    auto splayStart1 = chrono::steady_clock::now();
    for (int i = 1; i <= 20; i++)
        stree.insert(i);
    auto splayEnd1 = chrono::steady_clock::now();

    auto splayElapsed1 = chrono::duration_cast<chrono::microseconds>(splayEnd1 - splayStart1).count();
    cout << "Time for sequential insertion of 20 elements on an empty splay tree = " << splayElapsed1 << " micro seconds" << endl;
    cout << "Tree Root: " << stree.getRoot()->key << endl;

    ZipTree ztree;


    auto zipStart1 = chrono::steady_clock::now();
    for (int i = 1; i <= 20; i++)
        ztree.insert(i);
    auto zipEnd1 = chrono::steady_clock::now();

    auto zipelapsed1 = chrono::duration_cast<chrono::microseconds>(zipEnd1 - zipStart1).count();
    cout << "Time for sequential insertion of 20 elements on an empty zip tree = " << zipelapsed1 << " micro seconds" << endl;
    cout << "Tree Root: " << ztree.getRoot()->key << endl;

    */


    //Random insertion   
    /*
       vector<int> keys;
    keys.reserve(N);
    for (int i = 1; i <= N; i++)
        keys.push_back(i);

    mt19937 rng(42);
    shuffle(keys.begin(), keys.end(), rng);

    SplayTree stree;

    //auto splaystart2 = chrono::steady_clock::now();
    for (int key : keys)
        stree.insert(key);
   // auto splayend2 = chrono::steady_clock::now();

   // auto splayelapsed2 = chrono::duration_cast<chrono::microseconds>(splayend2 - splaystart2).count();

   // cout << "Time for random insertion of 100000 elemnts on an empty splay tree = " << splayelapsed2 << " micro seconds\n";
   // cout << "Tree Root: " << stree2.getRoot()->key << endl;

    ZipTree ztree;

    //auto zipstart2 = chrono::steady_clock::now();
    for (int key : keys)
        ztree.insert(key);
   // auto zipend2 = chrono::steady_clock::now();

   // auto zipelapsed2 = chrono::duration_cast<chrono::microseconds>(zipend2 - zipstart2).count();

   // cout << "Time for random insertion of 100000 elemnts on an empty zip tree = " << zipelapsed2 << " microseconds\n";
   // cout << "Tree Root: " << ztree2.getRoot()->key << endl;
    
    */
 


    //high/low pattern
    
    SplayTree stree;
    int low = 1;
    int high = N;

  //  auto splaystart3 = chrono::steady_clock::now();

    while (low <= high) {
        stree.insert(low);
        low++;

        if (low <= high) {
            stree.insert(high);
            high--;
        }
    }

   // auto splayend3 = chrono::steady_clock::now();

  //  auto splayelapsed3 =
    //    chrono::duration_cast<chrono::microseconds>(splayend3 - splaystart3).count();

   // cout << "Time for high/low insertion of 100000 elements on an empty splay tree = "
     //   << splayelapsed3 << " micro seconds\n";

  //  cout << "Tree Root: " << stree.getRoot()->key << endl;


    low = 1;
    high = N;
    ZipTree ztree;
  //  auto zipstart3 = chrono::steady_clock::now();

    while (low <= high) {
        ztree.insert(low);
        low++;

        if (low <= high) {
            ztree.insert(high);
            high--;
        }
    }
   // auto zipend3 = chrono::steady_clock::now();

   // auto zipelapsed3 = chrono::duration_cast<chrono::microseconds>(zipend3 - zipstart3).count();

   // cout << "Time for high/low insertion of 100000 elements on an empty splay tree = " << zipelapsed3 << " micro seconds\n";

    


    //sequentially
  /*
     SplayTree stree;
   auto splayStart1 = chrono::steady_clock::now();
    for (int i = 1; i <= N; i++)
    stree.insert(i);
    auto splayEnd1 = chrono::steady_clock::now();

    auto splayElapsed1 = chrono::duration_cast<chrono::microseconds>(splayEnd1 - splayStart1).count();
   cout << "Time for sequential insertion of 100000 elements on an empty splay tree = " << splayElapsed1 << " micro seconds" << endl;
   cout << "Tree Root: " << stree.getRoot()->key << endl;

   ZipTree ztree;


    auto zipStart1 = chrono::steady_clock::now();
    for (int i = 1; i <= N; i++)
   ztree.insert(i);
    auto zipEnd1 = chrono::steady_clock::now();

    auto zipelapsed1 = chrono::duration_cast<chrono::microseconds>(zipEnd1 - zipStart1).count();
    cout << "Time for sequential insertion of 10000 elements on an empty zip tree = " << zipelapsed1 << " micro seconds" << endl;
  //  cout << "Tree Root: " << ztree.getRoot()->key << endl;
  */




//Testing access and search in both trees
 //accessing elements sequentially
    /*
           auto accessStart1 = chrono::steady_clock::now();
   for (int i = 1; i <= N; i++) {
      stree.access(i);
   }
   auto accessEnd1 = chrono::steady_clock::now();


  auto accessElapsed1 = chrono::duration_cast<chrono::microseconds>(accessEnd1 - accessStart1).count();
  cout << "Time for sequential search on " << N << "elements on a splay tree = " << accessElapsed1 << " micro seconds" << endl;
  //cout << "Tree Root: " << stree.getRoot()->key << endl;

  auto searchStart1 = chrono::steady_clock::now();
  for (int i = 1; i <= N; i++) {
      ztree.search(i);
  }
  auto searchEnd1 = chrono::steady_clock::now();

  auto accessElapsedZip = chrono::duration_cast<chrono::microseconds>(searchEnd1 - searchStart1).count();

  cout << "Time for sequential search of " << N << " elements on Zip Tree = " << accessElapsedZip << " micro seconds" << endl;
    
    */

    

//accessing and searching elements in reverse
    /*
                auto accessStart2 = chrono::steady_clock::now();
    for (int i = N; i >= 1; i--) {
        stree.access(i);
    }
    auto accessEnd2 = chrono::steady_clock::now();
    auto accessElapsed2 = chrono::duration_cast<chrono::microseconds>(accessEnd2 - accessStart2).count();

    cout << "Splay Tree Reverse Search Time: " << accessElapsed2 << " microseconds" << endl; 
    cout << "Root:" << stree.getRoot()->key << endl;

    auto zipStartRev = chrono::steady_clock::now();
    for (int i = N; i >= 1; i--) {
        ztree.search(i);
    }
    auto zipEndRev = chrono::steady_clock::now();
    auto zipElapsedRev = chrono::duration_cast<chrono::microseconds>(zipEndRev - zipStartRev).count();

    cout << "Zip Tree Reverse Search Time: " << zipElapsedRev << " microseocnds" << endl;

    
    */

    

//accessing the same element N times
    /*
                int element = N / 2;

    auto accessStart3 = chrono::steady_clock::now();
    for (int i = 1; i <= N; i++) {
        stree.access(element);
    }
    auto accessEnd3 = chrono::steady_clock::now();
    cout << "Splay Tree repeated access Time: " << chrono::duration_cast<chrono::microseconds>(accessEnd3 - accessStart3).count() << " microseocnds" << endl;
    cout << "Root: " << stree.getRoot()->key << endl;

    auto searchStart3 = chrono::steady_clock::now();
    for (int i = 1; i <= N; i++) {
        ztree.search(element);
    }
    auto searchEnd3 = chrono::steady_clock::now();
    cout << "Zip Tree repeated search Time: " << chrono::duration_cast<chrono::microseconds>(searchEnd3 - searchStart3).count() << " microseonds" << endl;
    
   
    */
 


// Uniform Random Search
/*         random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, N);

    auto accessStart5 = chrono::steady_clock::now();
    for (int i = 1; i <= N; i++) {
        stree.access(dis(gen));
    }
    auto accessEnd5 = chrono::steady_clock::now();
    cout << "Splay Tree random search Time: " << chrono::duration_cast<chrono::microseconds>(accessEnd5 - accessStart5).count() << " microseconds" << endl;
    cout << "Root: " << stree.getRoot()->key << endl;

    auto searchStart5 = chrono::steady_clock::now();
    for (int i = 1; i <= N; i++) {
        ztree.search(dis(gen));
    }
    auto searchEnd5 = chrono::steady_clock::now();
    cout << "Zip Tree random search Time: " << chrono::duration_cast<chrono::microseconds>(searchEnd5 - searchStart5).count() << " microseconds" << endl;

 

*/

    

//acessing a squence with repetitions
/*
int accesssequence[20] = { 4,5,8,18,9,4,5,8,18,9,4,5,8,18,9,4,5,5,5,5 };
    auto accessStart2 = chrono::steady_clock::now();
for (int i = 0; i < 20; i++) {
    stree.access(accesssequence[i]);
}
auto accessEnd2 = chrono::steady_clock::now();
auto accessElapsed2 = chrono::duration_cast<chrono::microseconds>(accessEnd2 - accessStart2).count();

cout << "Splay Tree repeated sequence Search Time: " << accessElapsed2 << " microseconds" << endl;
cout << "Root:" << stree.getRoot()->key << endl;

auto searchStart2 = chrono::steady_clock::now();
for (int i = 0; i < 20; i++) {
    ztree.search(accesssequence[i]);
}
auto searchEnd2 = chrono::steady_clock::now();
auto searchElapsed2 = chrono::duration_cast<chrono::microseconds>(searchEnd2 - searchStart2).count();

cout << "Zip Tree repeated sequence Search Time: " << searchElapsed2 << " microseocnds" << endl;



*/



//Testing deletion in both trees
//Sequential Deletion
/* auto deleteStart1 = chrono::steady_clock::now();
for (int i = 1; i <= N; i++) {
    stree.deleteNode(i); 
}
auto deleteEnd1 = chrono::steady_clock::now();
cout << "Splay Tree sequential deletion Time for " << N << " nodes: " << chrono::duration_cast<chrono::microseconds>(deleteEnd1 - deleteStart1).count() << " microseconds" << endl;

auto searchStart6 = chrono::steady_clock::now();
for (int i = 1; i <= N; i++) {
    ztree.remove(i);
}
auto searchEnd6 = chrono::steady_clock::now();
cout << "Zip Tree sequential deletion Time for " << N << " nodes: " << chrono::duration_cast<chrono::microseconds>(searchEnd6 - searchStart6).count() << " microseconds" << endl;


*/



//random deletion
//Random Deletion
/*
   vector<int> keys2;
   keys2.reserve(N);
     for (int i = 1; i <= N; i++)
       keys2.push_back(i);

      mt19937 rng2(42);
     shuffle(keys2.begin(), keys2.end(), rng2);


auto deleteStart11 = chrono::steady_clock::now();
for (int i = 0; i < N; i++) {
    stree.deleteNode(keys2[i]);
}
auto deleteEnd11 = chrono::steady_clock::now();
cout << "Splay Tree random deletion Time for " << N << " nodes: " << chrono::duration_cast<chrono::microseconds>(deleteEnd11 - deleteStart11).count() << " microseconds" << endl;

auto searchStart11 = chrono::steady_clock::now();
for (int i = 0; i < N; i++) {
    ztree.remove(keys2[i]);
}
auto searchEnd11 = chrono::steady_clock::now();
cout << "Zip Tree random deletion Time for " << N << " nodes: " << chrono::duration_cast<chrono::microseconds>(searchEnd11 - searchStart11).count() << " microseconds" << endl;

*/


//Reverese sequential deletion
/*
auto deleteStart12 = chrono::steady_clock::now();
for (int i = N; i >= 1; i--) {
    stree.deleteNode(i);
}
auto deleteEnd12 = chrono::steady_clock::now();
cout << "Splay Tree reverse deletion Time for " << N << " nodes: " << chrono::duration_cast<chrono::microseconds>(deleteEnd12 - deleteStart12).count() << " microseconds" << endl;

auto searchStart12 = chrono::steady_clock::now();
for (int i = N; i >= 1; i--) {
    ztree.remove(i);
}
auto searchEnd12 = chrono::steady_clock::now();
cout << "Zip Tree reverse deletion Time for " << N << " nodes: " << chrono::duration_cast<chrono::microseconds>(searchEnd12 - searchStart12).count() << " microseconds" << endl;


*/



//Interleaved Delete and Search
/*
auto deleteStart13 = chrono::steady_clock::now();
for (int i = 1; i <= N; i++) {
    stree.access(i); 
    stree.deleteNode(i); 
}
auto deleteEnd13 = chrono::steady_clock::now();
cout << "Splay Tree interleaved delete Time for " << N << " nodes: " << chrono::duration_cast<chrono::microseconds>(deleteEnd13 - deleteStart13).count() << " microseconds" << endl;

auto searchStart13 = chrono::steady_clock::now();
for (int i = 1; i <= N; i++) {
    ztree.search(i); 
    ztree.remove(i);
}
auto searchEnd13 = chrono::steady_clock::now();
cout << "Zip Tree interleaved delete Time for " << N << " nodes: " << chrono::duration_cast<chrono::microseconds>(searchEnd13 - searchStart13).count() << " microseconds" << endl;




*/


    return 0;
}
