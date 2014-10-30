struct Tfai{ 
    static const int file=60000000;  // 大小等于读入总大小
    char s[file],*p; 
    void build(){p=s;fread(s,1,file,stdin);} 
    template<class Tsqy> inline void operator()(Tsqy &x){ 
        bool ok=false;while(*p<48 && *p!='-')++p;if(*p=='-')++p,ok=true; 
        x=0;while(47<*p)x=x*10+*(p++)-48;if(ok)x=-x; 
    } 
}fai;
