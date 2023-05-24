class Set:
    def _init_(self):
        self.hashSet = set()

    def add(self, newElement):
        self.hashSet.add(newElement)

    def remove(self, element):
        self.hashSet.discard(element)

    def contains(self, element):
        return element in self.hashSet

    def size(self):
        return len(self.hashSet)

    def iterator(self):
        return iter(self.hashSet)

    def intersection(self, otherSet):
        result = Set()
        for element in self.hashSet:
            if otherSet.contains(element):
                result.add(element)
        return result

    def union(self, otherSet):
        result = Set()
        result.hashSet = self.hashSet.union(otherSet.hashSet)
        return result

    def difference(self, otherSet):
        result = Set()
        for element in self.hashSet:
            if not otherSet.contains(element):
                result.add(element)
        return result

    def subset(self, otherSet):
        return self.hashSet.issubset(otherSet.hashSet)


# Test the Set implementation
set1 = Set()
set1.add(1)
set1.add(2)
set1.add(3)

set2 = Set()
set2.add(2)
set2.add(3)
set2.add(4)

# Test operations
print("Set 1 Size:", set1.size())
print("Set 2 Size:", set2.size())

print("Intersection:", end=" ")
intersection = set1.intersection(set2)
for element in intersection.iterator():
    print(element, end=" ")
print()

print("Union:", end=" ")
union_set = set1.union(set2)
for element in union_set.iterator():
    print(element, end=" ")
print()

print("Difference:", end=" ")
difference = set1.difference(set2)
for element in difference.iterator():
    print(element, end=" ")
print()


print("Subset:", set1.subset(set2))