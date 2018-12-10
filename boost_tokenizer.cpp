//boost::tokenizer. Here's documentation explaining how to make an appropriate tokenizer function: http://www.boost.org/doc/libs/1_52_0/libs/tokenizer/tokenizerfunction.htm

struct my_tokenizer_func
{
    template<typename It>
    bool operator()(It& next, It end, std::string & tok)
    {
        if (next == end)
            return false;
        char const * del = ">=";
        auto pos = std::search(next, end, del, del + 2);
        tok.assign(next, pos);
        next = pos;
        if (next != end)
            std::advance(next, 2);
        return true;
    }

    void reset() {}
};

int main()
{
    std::string to_be_parsed = "1) one>=2) two>=3) three>=4) four";
    for (auto i : boost::tokenizer<my_tokenizer_func>(to_be_parsed))
        std::cout << i << '\n';
}
