int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while(!todo.empty())
        {
            int n = todo.size();
            for(int i=0; i<n; ++i)
            {
                string init = todo.front();
                todo.pop();
                if(init==endWord)
                    return ladder;
                words.erase(init);
                for(int i = 0; i < init.size(); ++i)
                {
                    char ch = init[i];
                    for(int j=0; j<26; ++j)
                    {
                        char s = j + 'a';
                        init[i] = s;
                        if(words.find(init)!=words.end())
                        {
                            todo.push(init);
                        }
                    }
                    init[i]=ch;
                }
            }
            ++ladder;
        }
        return 0;
    }
