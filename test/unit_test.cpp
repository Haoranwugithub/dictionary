#include "ArrayDictionary.h"
#include "gtest/gtest.h"

#define PRINT

TEST(dict, array_dict_basic) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(1, 2));
    ASSERT_EQ(hashTable.size(), 1);
    ASSERT_FALSE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(8, 4));
    ASSERT_EQ(hashTable.size(), 2);

    ASSERT_TRUE(hashTable.add(11, 4));
    ASSERT_EQ(hashTable.size(), 2);
#ifdef PRINT
    hashTable.print();
#endif
}

TEST(dict, array_dict_add_overwrite) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 2));
    ASSERT_TRUE(hashTable.add(2, 4));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.size(), 1);
}

TEST(dict, array_dict_value_set_size) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.valueSetSize(5), 0);
    ASSERT_EQ(hashTable.valueSetSize(2), 2);
    ASSERT_EQ(hashTable.valueSetSize(3), 1);
}

TEST(dict, array_dict_add_get) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    int val = 0;
    ASSERT_TRUE(hashTable.get(2, val));
    ASSERT_EQ(val, 9);
    ASSERT_TRUE(hashTable.get(12, val));
    ASSERT_EQ(val, 8);
    ASSERT_TRUE(hashTable.get(3, val));
    ASSERT_EQ(val, 4);
    ASSERT_FALSE(hashTable.get(7, val));
    ASSERT_EQ(val, 4);
}

TEST(dict, contains) {
    // homework
    ArrayDictionary<int, int> set1;
    ASSERT_FALSE(set1.contain(-1));
    ASSERT_FALSE(set1.contain(0));
    ASSERT_FALSE(set1.contain(1));
    ArrayDictionary<int, int> set2;
    set2.add(0,103);
    ASSERT_FALSE(set2.contain(2));
    ASSERT_TRUE(set2.contain(0));
    ArrayDictionary<int, int> set3;
    set3.add(0,103);
    set3.add(1,105);
    ASSERT_TRUE(set3.contain(0));
    ASSERT_TRUE(set3.contain(1));
    ASSERT_FALSE(set3.contain(2));
    ASSERT_FALSE(set3.contain(3));
    ArrayDictionary<int, int> set4;
    set4.add(0,103);
    set4.add(1,105);
    ASSERT_FALSE(set4.contain(3));
    set4.add(2,206);
    ASSERT_TRUE(set4.contain(1));
    ArrayDictionary<int, int> set5;
    set5.add(0,103);
    set5.add(1,105);
    set5.add(2,206);
    set5.add(4,407);
    ASSERT_TRUE(set5.contain(1));
    ASSERT_TRUE(set5.contain(4));
    ASSERT_FALSE(set5.contain(7));
    ASSERT_FALSE(set5.contain(8));

}

TEST(dict, remove) {
    ArrayDictionary<int, int> set1;
    ASSERT_FALSE(set1.remove(-1));
    ASSERT_FALSE(set1.remove(0));
    ASSERT_FALSE(set1.remove(1));
    ArrayDictionary<int, int> set2;
    set2.add(0, 2);
    ASSERT_TRUE(set2.remove(0));
    ASSERT_TRUE(set2.isEmpty());
    ArrayDictionary<int, int> set3;
    set3.add(0, 2);
    ASSERT_FALSE(set3.remove(1));
    ASSERT_FALSE(set3.isEmpty());
    ArrayDictionary<int, int> set4;
    set4.add(0, 2);
    set4.add(0, 3);
    ASSERT_TRUE(set4.remove(0));
    ASSERT_TRUE(set4.isEmpty());
    ArrayDictionary<int, int> set5;
    set5.add(0, 2);
    set5.add(0, 3);
    ASSERT_FALSE(set5.remove(1));
    ASSERT_FALSE(set5.isEmpty());
    ASSERT_TRUE(false); // placeholder
}
