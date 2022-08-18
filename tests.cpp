#include <gtest/gtest.h>
#include "mymap.h"

TEST(mymap, defaultConstructor) {
    mymap<int, int> map;
    EXPECT_EQ(0, map.Size());

    mymap<string, string> map2;
    EXPECT_EQ(0, map2.Size());

    mymap<double, double> map3;
    EXPECT_EQ(0, map3.Size());

    mymap<float, float> map4;
    EXPECT_EQ(0, map4.Size());
}

TEST(mymap, put)
{
    mymap<string, string> map;
    map.put("Good", "Bad");
    map.put("This", "That");
    map.put("Little", "Bit");

    EXPECT_EQ(3, map.Size());

    mymap<int, string> map2;
    map2.put(1, "a");
    map2.put(2, "b");
    map2.put(3, "c");

    EXPECT_EQ(3, map2.Size());

    mymap<float, float> map3;
    map3.put(1.21, 12.1);
    map3.put(2.11, 21.1);
    map3.put(3.11, 31.1);

    EXPECT_EQ(3, map3.Size());

    mymap<string, double> map4;
    map4.put("one point one", 1.1);
    map4.put("one", 1);
    map4.put("one point zero", 1.0);

    EXPECT_EQ(3, map4.Size());
}

TEST(mymap, contains)
{
    mymap<string, string> map;
    map.put("Good", "Bad");
    map.put("This", "That");
    map.put("Little", "Bit");

    EXPECT_EQ(3, map.Size());
    EXPECT_EQ(true, map.contains("Good"));
    EXPECT_EQ(true, map.contains("This"));
    EXPECT_EQ(true, map.contains("Little"));
    EXPECT_EQ(false, map.contains("none"));

    mymap<int, string> map2;
    map2.put(1, "a");
    map2.put(2, "b");
    map2.put(3, "c");

    EXPECT_EQ(3, map2.Size());
    EXPECT_EQ(true, map2.contains(1));
    EXPECT_EQ(true, map2.contains(2));
    EXPECT_EQ(true, map2.contains(3));
    EXPECT_EQ(false, map2.contains(0));

    mymap<float, float> map3;
    map3.put(1.21, 12.1);
    map3.put(2.11, 21.1);
    map3.put(3.11, 31.1);

    EXPECT_EQ(3, map3.Size());
    EXPECT_EQ(true, map3.contains(1.21));
    EXPECT_EQ(true, map3.contains(2.11));
    EXPECT_EQ(true, map3.contains(3.11));
    EXPECT_EQ(false, map3.contains(0));

    mymap<string, double> map4;
    map4.put("one point one", 1.1);
    map4.put("one", 1);
    map4.put("one point zero", 1.0);

    EXPECT_EQ(3, map4.Size());
    EXPECT_EQ(true, map4.contains("one point one"));
    EXPECT_EQ(true, map4.contains("one"));
    EXPECT_EQ(true, map4.contains("one point zero"));
    EXPECT_EQ(false, map4.contains(""));
}

TEST(mymap, get)
{
    mymap<string, string> map;
    map.put("Good", "Bad");
    map.put("This", "That");
    map.put("Little", "Bit");

    EXPECT_EQ(3, map.Size());
    EXPECT_EQ("Bad", map.get("Good"));
    EXPECT_EQ("That", map.get("This"));
    EXPECT_EQ("Bit", map.get("Little"));
    EXPECT_EQ("", map.get("none"));


    mymap<int, string> map2;
    map2.put(1, "a");
    map2.put(2, "b");
    map2.put(3, "c");

    EXPECT_EQ(3, map2.Size());
    EXPECT_EQ("a", map2.get(1));
    EXPECT_EQ("b", map2.get(2));
    EXPECT_EQ("c", map2.get(3));
    EXPECT_EQ("", map2.get(4));

    mymap<float, float> map3;
    map3.put(1, 1/2);
    map3.put(2, 2/3);
    map3.put(3, 3/4);

    EXPECT_EQ(3, map3.Size());
    EXPECT_EQ(1/2, map3.get(1));
    EXPECT_EQ(2/3, map3.get(2));
    EXPECT_EQ(3/4, map3.get(3));
    EXPECT_EQ(0, map3.get(0));

    mymap<char, string> map4;
    map4.put('a', "first");
    map4.put('b', "second");
    map4.put('c', "third");

    EXPECT_EQ("first", map4.get('a'));
    EXPECT_EQ("second", map4.get('b'));
    EXPECT_EQ("third", map4.get('c'));
    EXPECT_EQ("", map4.get('n')); 
}

TEST(mymap, toString)
{
    mymap<string, string> map;
    map.put("Good", "Bad");
    map.put("This", "That");
    map.put("Little", "Bit");

    string correct = "key: Good value: Bad\nkey: Little value: Bit\nkey: This value: That\n";
    EXPECT_EQ(correct, map.toString());

    mymap<int, string> map2;
    map2.put(1, "a");
    map2.put(2, "b");
    map2.put(3, "c");

    correct = "key: 1 value: a\nkey: 2 value: b\nkey: 3 value: c\n";
    EXPECT_EQ(correct, map2.toString());
    
    mymap<float, float> map3;
    map3.put(2.21, 12.1);
    map3.put(1.11, 21.1);
    map3.put(3.11, 31.1);

    correct = "key: 1.11 value: 21.1\nkey: 2.21 value: 12.1\nkey: 3.11 value: 31.1\n";
    EXPECT_EQ(correct, map3.toString());

    mymap<int, string> map4;
    map4.put(3, "Third");
    map4.put(2, "Second");
    map4.put(1, "First");
    map4.put(5, "Fifth");

    correct = "key: 1 value: First\nkey: 2 value: Second\nkey: 3 value: Third\nkey: 5 value: Fifth\n";
    EXPECT_EQ(correct, map4.toString());
}

TEST(mymap, operator)
{
     mymap<string, string> map;
    map.put("Good", "Bad");
    map.put("This", "That");
    map.put("Little", "Bit");

    
    EXPECT_EQ(3, map.Size());
    EXPECT_EQ("Bad", map["Good"]);
    EXPECT_EQ("That", map["This"]);
    EXPECT_EQ("Bit", map["Little"]);
    EXPECT_EQ("", map["More"]);
    EXPECT_EQ(true, map.contains("More"));


    mymap<int, string> map2;
    map2.put(1, "a");
    map2.put(2, "b");
    map2.put(3, "c");

    EXPECT_EQ(3, map2.Size());
    EXPECT_EQ("a", map2[1]);
    EXPECT_EQ("b", map2[2]);
    EXPECT_EQ("c", map2[3]);
    EXPECT_EQ("", map2[4]);
    EXPECT_EQ(true, map2.contains(4));

    mymap<float, float> map3;
    map3.put(1, 1/2);
    map3.put(2, 2/3);
    map3.put(3, 3/4);

    EXPECT_EQ(3, map3.Size());
    EXPECT_EQ(1/2, map3[1]);
    EXPECT_EQ(2/3, map3[2]);
    EXPECT_EQ(3/4, map3[3]);
    EXPECT_EQ(0, map3[4]);
    EXPECT_EQ(true, map3.contains(4));

    mymap<char, string> map4;
    map4.put('a', "first");
    map4.put('b', "second");
    map4.put('c', "third");

    EXPECT_EQ("first", map4['a']);
    EXPECT_EQ("second", map4['b']);
    EXPECT_EQ("third", map4['c']);
    EXPECT_EQ("", map4['d']);
    EXPECT_EQ(true, map4.contains('d')); 
}

TEST(mymap, iterator)
{
    mymap<int, int> map;
    int arr[] = {2,1,3};
    int order[] = {1,2,3};
    for (int i = 0; i < 3; i++)
    {
        map.put(arr[i],arr[i]);
    }

    int i = 0;
    for (auto key : map)
    {
        EXPECT_EQ(order[i++], key);
    }

    mymap<string, string> map2;
    map2.put("One", "One");
    map2.put("Second", "Second");
    map2.put("Third", "Third");
    string order2[] = {"One", "Second", "Third"};
    i = 0;
    for (auto key : map2)
    {
        EXPECT_EQ(order2[i++], key);
    }

    mymap<double, double> map3;
    double arr3[] = {3.5, 3.1, 3.9, 9.1, 1.1};
    double order3[] = {1.1, 3.1, 3.5, 3.9, 9.1};
    for (i = 0; i < 5; i++)
    {
        map3.put(arr3[i],arr[i]);
    }

    i = 0;
    for(auto key : map3)
    {
        EXPECT_EQ(order3[i++], key);
    }

    mymap<float, float> map4;
    float arr4[] = {1.1, 3.5, 2.2, 9.2, 2.1, 2.8};
    float order4[] = {1.1, 2.1, 2.2, 2.8, 3.5, 9.2};

    for (i = 0; i < 6; i++)
    {
        map4.put(arr4[i],arr4[i]);
    }

    i = 0;
    for (auto key : map4)
    {
        EXPECT_EQ(order4[i++], key);
    }
}

TEST(mymap, clear)
{
    mymap<int, int> map;
    int arr[] = {2,1,3};
    for (int i = 0; i < 3; i++)
    {
        map.put(arr[i],arr[i]);
    }
    map.clear();
    EXPECT_EQ(map.Size(), 0);

    mymap<string, string> map2;
    map2.put("One", "One");
    map2.put("Second", "Second");
    map2.put("Third", "Third");
    
    map2.clear();
    EXPECT_EQ(map2.Size(), 0);

    mymap<double, double> map3;
    double arr3[] = {3.5, 3.1, 3.9, 9.1, 1.1};
    for (int i = 0; i < 5; i++)
    {
        map3.put(arr3[i],arr[i]);
    }

    map3.clear();
    EXPECT_EQ(map3.Size(), 0);

    mymap<float, float> map4;
    float arr4[] = {1.1, 3.5, 2.2, 9.2, 2.1, 2.8};

    for (int i = 0; i < 6; i++)
    {
        map4.put(arr4[i],arr4[i]);
    }

    map4.clear();
    EXPECT_EQ(map4.Size(), 0);
}

TEST(mymap, copyConstructorOperator)
{
    mymap<int, int> map;
    int arr[] = {2,1,3};
    int order[] = {1,2,3};
    for (int i = 0; i < 3; i++)
    {
        map.put(arr[i],arr[i]);
    }

    mymap<int,int> mapCopy;
    mapCopy = map;

    int i = 0;
    for (auto key : mapCopy)
    {
        EXPECT_EQ(order[i++], key);
    }

    mymap<string, string> map2;
    map2.put("One", "One");
    map2.put("Second", "Second");
    map2.put("Third", "Third");
    string order2[] = {"One", "Second", "Third"};

    mymap<string, string> mapCopy2;
    mapCopy2 = map2;
    i = 0;
    for (auto key : mapCopy2)
    {
        EXPECT_EQ(order2[i++], key);
    }

    mymap<double, double> map3;
    double arr3[] = {3.5, 3.1, 3.9, 9.1, 1.1};
    double order3[] = {1.1, 3.1, 3.5, 3.9, 9.1};
    for (i = 0; i < 5; i++)
    {
        map3.put(arr3[i],arr[i]);
    }

    mymap<double, double> mapCopy3;
    mapCopy3 = map3;
    i = 0;
    for(auto key : mapCopy3)
    {
        EXPECT_EQ(order3[i++], key);
    }

    mymap<float, float> map4;
    float arr4[] = {1.1, 3.5, 2.2, 9.2, 2.1, 2.8};
    float order4[] = {1.1, 2.1, 2.2, 2.8, 3.5, 9.2};

    for (i = 0; i < 6; i++)
    {
        map4.put(arr4[i],arr4[i]);
    }

    mymap<float, float> mapCopy4;
    mapCopy4 = map4;
    i = 0;
    for (auto key : mapCopy4)
    {
        EXPECT_EQ(order4[i++], key);
    }
}

TEST(mymap, copyConstructor)
{
    mymap<int, int> map;
    int arr[] = {2,1,3};
    int order[] = {1,2,3};
    for (int i = 0; i < 3; i++)
    {
        map.put(arr[i],arr[i]);
    }

    mymap<int,int> mapCopy = map;

    int i = 0;
    for (auto key : mapCopy)
    {
        EXPECT_EQ(order[i++], key);
    }

    mymap<string, string> map2;
    map2.put("One", "One");
    map2.put("Second", "Second");
    map2.put("Third", "Third");
    string order2[] = {"One", "Second", "Third"};

    mymap<string, string> mapCopy2 = map2;
    i = 0;
    for (auto key : mapCopy2)
    {
        EXPECT_EQ(order2[i++], key);
    }

    mymap<double, double> map3;
    double arr3[] = {3.5, 3.1, 3.9, 9.1, 1.1};
    double order3[] = {1.1, 3.1, 3.5, 3.9, 9.1};
    for (i = 0; i < 5; i++)
    {
        map3.put(arr3[i],arr[i]);
    }

    mymap<double, double> mapCopy3 = map3;
    i = 0;
    for(auto key : mapCopy3)
    {
        EXPECT_EQ(order3[i++], key);
    }

    mymap<float, float> map4;
    float arr4[] = {1.1, 3.5, 2.2, 9.2, 2.1, 2.8};
    float order4[] = {1.1, 2.1, 2.2, 2.8, 3.5, 9.2};

    for (i = 0; i < 6; i++)
    {
        map4.put(arr4[i],arr4[i]);
    }

    mymap<float, float> mapCopy4 = map4;
    i = 0;
    for (auto key : mapCopy4)
    {
        EXPECT_EQ(order4[i++], key);
    }
}

TEST(mymap, toVector)
{
    mymap<string, string> map;
    map.put("Good", "Bad");
    map.put("This", "That");
    map.put("Little", "Bit");

    vector<pair<string,string>> solution;
    solution.emplace_back("Good", "Bad");
    solution.emplace_back("Little", "Bit");
    solution.emplace_back("This", "That");

    EXPECT_EQ(solution, map.toVector());

    mymap<int, string> map2;
    map2.put(1, "a");
    map2.put(2, "b");
    map2.put(3, "c");

    vector<pair<int, string>> solution2;
    solution2.emplace_back(1, "a");
    solution2.emplace_back(2, "b");
    solution2.emplace_back(3, "c");

    EXPECT_EQ(solution2, map2.toVector());
    
    mymap<float, float> map3;
    map3.put(2.21, 12.1);
    map3.put(1.11, 21.1);
    map3.put(3.11, 31.1);

    vector<pair<float,float>> solution3;
    solution3.emplace_back(1.11, 21.1);
    solution3.emplace_back(2.21, 12.1);
    solution3.emplace_back(3.11, 31.1);

    EXPECT_EQ(solution3, map3.toVector());

    mymap<int, string> map4;
    map4.put(3, "Third");
    map4.put(2, "Second");
    map4.put(1, "First");
    map4.put(5, "Fifth");

    vector<pair<int, string>> solution4;
    solution4.emplace_back(1, "First");
    solution4.emplace_back(2, "Second");
    solution4.emplace_back(3, "Third");
    solution4.emplace_back(5, "Fifth");

    EXPECT_EQ(solution4, map4.toVector());
}

TEST(mymap, checkBalance)   
{
    mymap<int, int> map;
    int arr[] = {2,1,3};
    for (int i = 0; i < 3; i++)
    {
        map.put(arr[i], arr[i]);
    }

    string sol = "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
    EXPECT_EQ(map.checkBalance(), sol);

    mymap<string, string> map2;
    map2.put("Little", "Bit");
    map2.put("Good", "Bad");
    map2.put("This", "That");

    string correct = "key: Little, nL: 1, nR: 1\nkey: Good, nL: 0, nR: 0\nkey: This, nL: 0, nR: 0\n";
    EXPECT_EQ(correct, map2.checkBalance());

    mymap<int, string> map3;
    map3.put(2, "b");
    map3.put(1, "a");
    map3.put(3, "c");

    correct = "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
    EXPECT_EQ(correct, map3.checkBalance());
    
    mymap<float, float> map4;
    map4.put(2.21, 12.1);
    map4.put(1.11, 21.1);
    map4.put(3.11, 31.1);

    correct = "key: 2.21, nL: 1, nR: 1\nkey: 1.11 value: 21.1\nkey: 3.11 value: 31.1\n";

    mymap<int, string> map5;
    map5.put(3, "Third");
    map5.put(2, "Second");
    map5.put(1, "First");
    map5.put(5, "Fifth");

    correct = "key: 2, nL: 1, nR: 2\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 1\nkey: 5, nL: 0, nR: 0\n";
    EXPECT_EQ(correct, map5.checkBalance());
}

TEST(mymap, balancing)
{
    mymap<int, int> map;
    map.put(1,1);
    map.put(2,2);
    map.put(3,3);

    string correct = "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
    EXPECT_EQ(correct, map.checkBalance());    

    mymap<int, int> map2;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 9; i++)
    {
        map2.put(arr[i], arr[i]);
    }

    correct = "key: 5, nL: 4, nR: 4\nkey: 2, nL: 1, nR: 2\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 1\nkey: 4, nL: 0, nR: 0\nkey: 7, nL: 1, nR: 2\nkey: 6, nL: 0, nR: 0\nkey: 8, nL: 0, nR: 1\nkey: 9, nL: 0, nR: 0\n";
    EXPECT_EQ(correct, map2.checkBalance());

    mymap<string, string> map3;
    map3.put("a", "a");
    map3.put("b", "b");
    map3.put("c", "c");
    map3.put("d", "d");
    map3.put("e", "e");
    map3.put("f", "f");
    map3.put("g", "g");
    map3.put("h", "h");
    map3.put("i", "i");
    map3.put("j", "j");
    map3.put("k", "k");
    map3.put("l", "l");
    map3.put("m", "m");

    correct = "key: e, nL: 4, nR: 8\nkey: b, nL: 1, nR: 2\nkey: a, nL: 0, nR: 0\nkey: c, nL: 0, nR: 1\nkey: d, nL: 0, nR: 0\nkey: h, nL: 2, nR: 5\nkey: f, nL: 0, nR: 1\nkey: g, nL: 0, nR: 0\nkey: j, nL: 1, nR: 3\nkey: i, nL: 0, nR: 0\nkey: l, nL: 1, nR: 1\nkey: k, nL: 0, nR: 0\nkey: m, nL: 0, nR: 0\n";
    EXPECT_EQ(correct, map3.checkBalance());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}