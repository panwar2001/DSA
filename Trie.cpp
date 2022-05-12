class Trie {
    struct trie{
       trie *node[26]={};
       bool formWord;
        trie(){
            formWord=0;
        }
        trie *setchar(char c,trie *r){
            if(r->node[c-'a'])return r->node[c-'a'];
            r->node[c-'a']=new trie();
            r=r->node[c-'a'];
            return r;
        }
        bool containsKey(char c,trie *r){
            if(r->node[c-'a'])return 1;
            return 0;
        }
    };
public:
    trie *root;
    Trie() {
        root=new trie();
        for(int i=0;i<26;i++)root->node[i]=0;
    }
    
    void insert(string word) {
        trie *r=root;
        for(int i=0;i<word.size();i++){
            r=r->setchar(word[i],r);
        }
        r->formWord=1;
    }
    
        
    bool search(string word) {
     trie *r=root;
    for(int i=0;i<word.size();i++)
     {
         if(r->containsKey(word[i],r)==0)return 0;
        r=r->node[word[i]-'a'];
     }
        return r->formWord;
    }
    
    bool startsWith(string prefix) {
          trie *r=root;
    for(int i=0;i<prefix.size();i++)
     {
         if(r->containsKey(prefix[i],r)==0)return 0;
        r=r->node[prefix[i]-'a'];
     }
        return 1;
    }
};