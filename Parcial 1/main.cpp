#include<iostream>
#include<memory>
#include<algorithm>

class Individual {
public:
    std::string name;
    std::shared_ptr<Individual> father;
    std::shared_ptr<Individual> mother;

    // Individual's constructor
    Individual(std::string name) {
        this->name = name;
    }
};

// This function checks if two individuals are siblings
bool areSiblings(const std::shared_ptr<Individual>& person1, const std::shared_ptr<Individual>& person2);

// This function compares two family trees 
bool compareTrees(const std::shared_ptr<Individual>& person1, const std::shared_ptr<Individual>& person2) {
    if (person1 == nullptr && person2 == nullptr)
        return true;

    if (person1 == nullptr || person2 == nullptr)
        return false;

    return person1->name == person2->name 
        && compareTrees(person1->father, person2->father)
        && compareTrees(person1->mother, person2->mother);
}

// This function counts the number of known generations of an individual
int countGenerations(const std::shared_ptr<Individual>& person) {
    if (person == nullptr) {
        return 0;
    } else {
        return 1 + std::max(countGenerations(person->father), countGenerations(person->mother));
    }
}

// This function adds a new ancestor to an individual's family tree
void addAncestor(const std::shared_ptr<Individual>& person, const std::shared_ptr<Individual>& father, const std::shared_ptr<Individual>& mother) {
    if (person != nullptr) {
        person->father = father;
        person->mother = mother;
    }
}

// This function checks if two individuals are siblings
bool areSiblings(const std::shared_ptr<Individual>& person1, const std::shared_ptr<Individual>& person2) {
    return compareTrees(person1->father, person2->father) 
        && compareTrees(person1->mother, person2->mother);
}

int main() {
    // Create individuals
    auto john = std::make_shared<Individual>("John");
    auto peter = std::make_shared<Individual>("Peter");
    auto mary = std::make_shared<Individual>("Mary");
    auto joseph = std::make_shared<Individual>("Joseph");

    // Add ancestors
    addAncestor(john, joseph, mary);
    addAncestor(peter, joseph, mary);

    // Count generations
    std::cout << "John's generations: " << countGenerations(john) << std::endl;

    // Check if they are siblings
    std::cout << "Are John and Peter siblings? " << (areSiblings(john, peter) ? "Yes" : "No") << std::endl;

    return 0;
}
