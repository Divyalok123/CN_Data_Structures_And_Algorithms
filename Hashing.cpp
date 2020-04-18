#include <bits/stdc++.h>
using namespace std;

template <typename v>
class MapNode
{
public:
    string key;
    v value;
    MapNode *next;

    MapNode(string key, int value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename v>
class ourmap
{
    MapNode<v> **buckets;
    int count;
    int numBuckets;

public:
    ourmap()
    {
        count = 0;
        numBuckets = 10;
        buckets = new MapNode<v> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

private:
    int getBucketIndex(string key)
    {
        int hashcode = 0;
        int currCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashcode += key[i] * currCoeff;
            hashcode = hashcode % numBuckets;
            currCoeff *= 29;
            currCoeff %= numBuckets;
        }
        return hashcode % numBuckets;
    }

    void rehash()
    {
        MapNode<v> **temp = buckets;
        buckets = new MapNode<v> *[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }

        int oldBucketsCount = numBuckets;
        numBuckets *= 2;
        count = 0;

        for (int i = 0; i < oldBucketsCount; i++)
        {
            MapNode<v> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                v value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketsCount; i++)
        {
            MapNode<v> *head = temp[i];
            delete head;
        }

        delete[] temp;
    }

public:
    v getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<v> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    void insert(string key, v value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<v> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];
        MapNode<v> *node = new MapNode<v>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;

        double loadFactor = (1.0 * count) / numBuckets;
        if (loadFactor > 0.7)
            rehash();
    }

    v remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<v> *head = buckets[bucketIndex];
        MapNode<v> *prev = NULL;

        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                    prev->next = head->next;
                v value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }

            prev = head;
            head = head->next;
        }
        return 0;
    }

    double getLoadFactor()
    {
        return (1.0 * count) / numBuckets;
    }
};

int main()
{
    ourmap<int> map;
    for (int i = 0; i < 20; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.getLoadFactor() << endl;
    }

    cout << map.size() << endl;

    map.remove("abc2");
    map.remove("abc4");

    for (int i = 0; i < 20; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout << key << " " << map.getValue(key) << endl;
    }

    return 0;
}