//Iterate through a vector using for loop
std::vector<int> v;

for(std::size_t i = 0; i < v.size(); ++i)
    std::cout << v[i] << '\n';

//iterator based range - emulated C pointer shift
for(auto t = v.begin(); t != v.end(); ++t)
    std::cout << *t << '\n';

    
