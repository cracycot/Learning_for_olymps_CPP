#include <iostream>
#include <cmath>
#include <vector>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

using namespace std;
//    определите только функцию power, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
struct test{
    int x;
    char y;
};
int power(int x, unsigned p) {
    int answer = 1;
    if(p == 0){
        return 1;
    }
    for(int i = 0; i < p ; i++){
        answer = answer*x;
    }
    /* считаем answer */
    return answer;
}
void kv_urav(int a, int b, int c){
    int dis = pow(b,2) - (4*a*c);
    if(dis < 0){
        cout<<"No real roots"<<endl;
    }
    else if(dis == 0){
        cout<<(-b)/2*a<<" "<<(-b)/2*a<<endl;
    }
    else{
        cout<<((-b) + pow(dis, 0.5) )/ (2 *a)<<" "<<((-b) - pow(dis, 0.5) )/ (2 *a)<<endl;
    }
}

void sum_(int f, int z){
    int y = f+z;
    cout<<y<<endl;
}
void log_2(int x){
    int s = 1;
    int log = 0;
    if (x > 2){
        while(s*2 <= x){
            s *= 2;
            log += 1;
        }
        cout<<log;
    }
    else if(1<=x<=2){
        cout<<"1";
    }
}
int gcd(unsigned x, unsigned y){
    if((x != 0) && (y != 0)){
        if (x > y){
            return gcd(x % y, y);
        }
        else{
            return gcd(x, y % x);
        }
    }
       else{
        return (x + y);
    }
       
}
void pr_posl(){
    int y = 0;
    cin>>y;
    if(y == 0){
        return;
    }
    pr_posl();
    cout<<y<<" ";
}
void sd(int x[], unsigned size, int shift){
    int sdv = shift % size;
    for(int i = 0; i < sdv; i ++ ){
        for(int j = 0; j < (size - 1); j ++){
            int *el1 = &x[j];
            int *el2 = &x[j + 1];
            int *vs = el1;
            *el1 = *el2;
            *el2 = *vs;
        }
    }
    int b[size];
    for(int g = 0; g < size; g ++ ){
        b[g] = x[g];
    }
}
unsigned strlen1(const char *s)
{
    int i = 0;
    while(s[i] != '\0'){
        i++;
    };
    return i;
}

int strstr1(const char *text, const char *pattern){
    int l_1 = strlen1(pattern);
    int s_l = strlen1(text);
    if(l_1 == 0){
        return 0;
    }
    if(s_l == 0){
        return -1;
    }
    for(int i = 0; i < s_l; i ++){
        bool flag = true;
        for(int j = i; j < (l_1 + i); j ++){
            if(text[j] != pattern[j - i]){
                flag = false;
                break;
            }
        }
        if(flag){
            return i;
            }
    }
    return -1;
}

char *resize(const char *str, unsigned size, unsigned new_size){
    char *z = new char[new_size];
    for(unsigned i = 0;  i < new_size && i < size; i ++){
        *(z + i) = *(str + i);
    }
    delete [] str;
    return z;
}
char *getline1(){
    char symbol;
    int i = 0;
    int size = i + 1;
    char * pam = new char [size];
    while(cin.get(symbol) && (symbol != '\n') && (symbol != cin.eof())){
        if(size > i){
            pam = (char *)realloc(pam, size * 2 * sizeof(char));
            size = size * 2;
        
        }
        pam[i] = symbol;
        //pam = resize(pam, i, i + 1);
        //cout<<pam[i];
        i ++ ;
    }
    pam[i + 1] = '\0';
    return pam;
}
int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** m1 = new int * [cols];
    m1[0] = new int[rows * cols];
    for(int i = 1; i < cols; ++i){
        m1[i] = m1[i - 1] + rows;
    }
    for(int i = 0; i < cols; i ++ ){
        for(int j = 0; j <  rows; j ++){
            m1[i][j] = m[j][i];
        }
    }
    return m1;
}
void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int m_index = 0;
    int min = m[0][0];
    for(int i = 0;  i  < rows; i ++ ){
        for(int j = 0; j < cols; j ++){
            if (m[i][j] < min){
                min = m[i][j];
                m_index = i;
            }
        }
    }
    int *f = m[m_index];
    m[m_index] = m[0];
    m[0] = f;
    
}
struct hash_str{
    hash_str(){
        this -> key = 0;
        this -> f = 0;
    }
    int number;
    hash_str *f = 0;
    char * key = 0;
};
int hash1(char x[], int size_cash){
    int l = strlen1(x);
    int s = 0;
    for(int i = 0 ; i < l; i ++){
        s += x[i];
    }
    return s % size_cash;
}
void hash_table_write(hash_str *m[],int index, int numb, char  *k){
    hash_str *structura = m[index];
    while(structura ->f != 0){
        structura = structura -> f;
    }
    if(structura->f == 0){
        hash_str x;
        structura-> number = numb;
        //cout<<structura-> number;
        structura -> key = k;
        structura -> f = &x;
    }
}
hash_str * hash_table_read(hash_str *m[], int index , char *k){
    hash_str *structura = m[index];
    if(structura ->f == 0){
        return  structura;
    }
    while(!(*(structura -> key) == *k)){
        structura = structura -> f;
        cout<<1;
    }
    return structura;
}


struct String {
    String(size_t n, char c){
            this -> size = n;
            char * g = 0;
            g = new char[n + 1];
            for(int i = 0 ; i < n; i ++){
                g[i] = c;
            }
            g[n] = '\0';
            this -> str = g;
            
        }
    String(const String & a){
        this-> size = a.size;
        char * f = new char[size + 1];
        *f = *a.str;
        for(int i = 0; i < size; i ++){
            f[i] = a.str[i];
        }
        f[size] = '\0';
        this->str = f;
        
    }
    String & operator = (String const &a){
        if(this != &a){
            delete [] this->str;
            this -> size = a.size;
            char * f = new char[size + 1];
            *f = *a.str;
            for(int i = 0; i < size; i ++){
                f[i] = a.str[i];
            }
            f[size] = '\0';
            this->str = f;
        }
        return *this;
        
    }
        /* и деструктор */
    ~String(){
        delete [] str;
    }

    /* Реализуйте этот метод. */
    void append(String &other){
            int n = ((this->size) + (other.size) + 1);
            char * f = 0;
            f = new char [n];
            for(int i = 0; i < (this -> size); i ++){
                f[i] = this->str[i];
            }
            for(int i = 0; i < other.size; i ++){
                f[i + this->size] = other.str[i];
            }
            f[this->size + other.size] = '\0';
            this -> size = (n-1);
            this -> str = f;
            delete [] f;
        
        }



    size_t size;
    char *str;
};
void strcat1(char * to, const char *from){
    int l1 = strlen1(to);
    int l2 =  strlen1(from);
    char is[l1 + l2 + 1];
    for(int i  = 0; i < l1; i ++){
        is[i] = to[i];
        
    }
    for(int i  = 0; i < l2; i ++){
        is[i + l1] = from[i];
        
    }
    is[l1 + l2] = '\0';
    to = is;
    cout<<is;
}

struct Cls {
public:
    Cls(char c, double d, int i): c(c), d(d), i(i)
    {}
    void ct(){
        cout<<c;
        cout<<d;
        cout<<i;
    }
private:
    char c;
    double d;
    int i;
};

struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const char *msg) : msg(msg) { }
private:
    const char *msg;
};


void foo_says(const Foo& foo) { foo.say(); }
Foo get_foo(const char *msg) {
    struct Foo1 : Foo{
        Foo1(const char* msg): Foo(msg){
        }
    };
    
    Foo1 f(msg);
    return f;
}


int sum_m(){
    int size = 0;
    int sum = 0;
    cin>> size;
    int x[size];
    for(int i  = 0 ; i < size ; i ++){
        int f = 0;
        cin>>f;
        sum += f;
    }
    return sum;
    
}

int mx_p(){
    int size = 0;
    cin>>size;
    int mx_el = -1000000;
    int ind = 0;
    for(int i = 0; i < size; i ++){
        int f = 0;
        cin>>f;
        if(f > mx_el){
            ind = i;
            mx_el = f;
        }
    }
    
    return ind;
}

long NextRand(long cur, int a, int b) {
    int mod = 1791791791;
    cur = ((cur * a) + b) % mod;
    return cur;
}
void mx_indexes(){
    int n = 0;
    int a = 0, b = 0;
    int mx_in = 0, mx_in_1 = 0;
    long cur = 0, mx_el = 0, mx_el1 = 0;
    cin>>n;
    cin>>cur>>a>>b;
    for(int i = 0; i < n ; i ++){
        long f = NextRand(cur, a, b);
        cur = f;
        bool flag = 1;
        if(f > mx_el1){
            if(f > mx_el){
                mx_el1 = mx_el;
                mx_el = f;
                mx_in_1 = mx_in;
                mx_in = i;
                flag = 0;
            }
            if(flag){
                mx_el1 = f;
                mx_in_1 = i;
            }
        }
        
    }
    cout<<mx_in + 1<<' '<<mx_in_1 + 1;
}
void  pref(){
    int n = 0 , q = 0;
    cin>>n>>q;
    long x[n];
    long sum = 0;
    for(int i = 0; i < n; i ++){
        long f = 0;
        cin>>f;
        sum += f;
        x[i] = sum;
    }
    for(int i = 0; i < q; i ++){
        int f =0, f1 =0;
        cin>>f>>f1;
        if(f == 1){
            cout<<x[f1 - 1]<<'\n';
        }
        else{
            cout<<x[f1 - 1] - x[f - 2]<<'\n';
        }
    }
}
void mx_pref(){
    int n = 0;
    cin>>n;
    long a[n];
    long sum = 0;
    for(int i =0 ; i < n; i ++ ){
        long f = 0;
        cin>>f;
        sum += f;
        if(sum >= 0){
            a[i] = sum;
        }
        else{
            a[i] = f;
            sum = 0;
        }
    }
    long mx = -10000000;
    for(int i = 0; i < n; i ++){
        if(a[i] > mx){
            mx = a[i];
        }
    }
    cout<<mx;
}
void pref_1(){
    char a[10];
    cin>>a;
    int l = 0;
    for(int i = 0; a[i] != '\0'; i ++){
        l+=1;
    }
    char copy[l + 1];
    for(int i = 0; i < l;i ++){
        if(a[i] == '2' || a[i] == '0'){
            copy[i] = char(int(a[i]) + 1);
            if(i != (l - 1)){
                for(int j = (i + 1); j < l; j ++){
                    copy[j] = '0';
                }
                
            }
            break;
        }
        else{
            copy[i] = a[i];
        }
    }
    copy[l] = '\0';
    cout<<copy;
}
void perebor(){
    int i = 0;
    cin>>i;
}

void bin_search(){
    int size = 0, k = 0;
    cin>>size>>k;
    for(int i = 0 ;i != k; i ++){
        int f = 0;
        int count = 0;
        cin>>f;
        int r = 0, r1 = (size - 1);
        while( r +1 != r1){
            if((r + r1) / 2 < f){
                r = (r + r1) / 2;
                
            }
            else{
                r1 = (r+ r1)/2;
                
            }
            count+=1;
        }
        cout<<count;
        
    }
}
void obr_bin_search(){
    int size = 0, i = 0, g = 0;
    cin>>size>>g;
    int r = -1, r1 = size;
    //int a[size];
    while(i != g){
        int f = 0;
        cin>>f;
        //a[i] = f;
        if(f == 1){
            r1 = (r1 + r) / 2;
        }
        else{
            r = (r1 + r) / 2;
        }
        i ++;
    }
    cout<<r1;
}
void check_answer(){
    int n = 0 , m = 0;
    cin>>n>>m;
    long a[n];
    for(int i = 0 ; i < n ; i ++ ){
        long x = 0;
        cin>>x;
        a[i] = x;
        
    }
    for(int i = 0 ; i < m; i ++){
        long x = 0;
        cin>>x;
        int u = -1, u1 = n;
        while(u + 1 < u1){
            int sr = (u + u1) / 2;
            if(a[sr] < x){
                u = sr;
            }
            else{
                u1 = sr;
            }
        }
        if(a[u1] == x){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
}
void min_poh(){
    int n = 0 , m = 0;
    cin>>n>>m;
    long a[n];
    for(int i = 0 ; i < n ; i++ ){
        long x = 0;
        cin>>x;
        a[i] = x;
        
    }
    for(int i = 0 ; i < m; i ++){
        long x = 0;
        cin>>x;
        int u = -1, u1 = n;
        while(u + 1 < u1){
            int sr = (u + u1) / 2;
            if(a[sr] < x){
                u = sr;
            }
            else{
                u1 = sr;
            }
        }
        if(a[u1] >= x){
                cout<<a[u1]<<'\n';
        }
        else{
            cout << "NO SOLUTION\n" ;
        }
        
    }
    
}
void max_min(){
    int size = 0, k = 0;
    cin>>size>>k;
    long a[size];
    for(int i = 0; i < size ; i ++){
        long x = 0;
        cin>>x;
        a[i] = x;
    }

    for(int i = 0; i< k; i ++ ){
        int r = - 1, r1 = size;
        long x = 0;
        cin>>x;
        while(r + 1< r1){
            int sr = (r + r1 ) / 2;
            if(a[sr ] < x ){
                r = sr;
            }
            else{
                r1 = sr;
            }
            
        }
        if(x < a[0]){
            cout<<"NO SOLUTION\n"<<r<<" "<<r1<<" ";
        }
        else if(a[r] == x){
            while(a[r] < x && r > 0){
                r -= 1;
            }
            if(r1 > 1){
                cout<<r;
            }
            else{
                cout<<"NO SOLUTION\n";
            }
        }
        else{
            cout<<r;
        }

        
    }
    
}

void max_min_rev(){
    int size = 0, k = 0;
    cin>>size>>k;
    long a[size];
    for(int i = 0; i < size ; i ++){
        long x = 0;
        cin>>x;
        a[i] = x;
    }
    for(int i = 0; i< k; i ++ ){
        int r = - 1, r1 = size;
        long x = 0;
        cin>>x;
        while(r + 1< r1){
            int sr = (r + r1 ) / 2;
            if(a[sr ] < x ){
                r1 = sr;
            }
            else{
                r = sr;
            }
            
        }
        if(x < a[size - 1]){
            cout<<"NO SOLUTION\n";
        }
        else if(a[r] == x){
            while(a[r] == x && a[r - 1] == x && r > 0){
                r -= 1;
            }
            if(r1 > 0){
                cout<<r + 1<<"\n"<<"1";
            }
            else{
                cout<<"NO SOLUTION\n"<<"2";
            }
        }
        else{
            cout<<r1 + 1<<"\n"<<"3";
        }

        
    }
    
}

long double resh_mn(int a[], int size, long double x){
    long double answ = 0;
    for(int i = size; i != -1; i --){
        answ += pow(x, (size - i))*a[i];
    }
    return answ;
}
void resh_mng(){
    int size = 0;
    cin>>size;
    int a[size + 1];
    for(int i = 0; i < (size + 1); i ++){
        int x = 0;
        cin>>x;
        a[i] = x;
    }
    long double l = 0.0;
    long double r = 2.0;
    for(int i = 0 ; i< 100 ; i ++ ){
        if(r - l > 1e-9){
            long double mid = (l + r) / 2;
            if(resh_mn(a, size, mid) < 0.0){
                l = mid;
            }
            else{
                r = mid;
            }
            
        }
        else{
            break;
        }
    }
    cout.precision(16);
    cout<<(r + l) / 2;
}
long double distance1(long double x, long double y, long double x1, long double y1){
    return sqrtl(pow((x1 - x), 2) + pow((y1 - y) ,2));
}
void bin_circle(){
    int x = 0 , y = 0, d = 0;
    cin>>x>>y>>d;
    int size = 0;
    cin>>size;
    int a[size + 1];
    for(int i = 0 ; i <= size; i++ ){
        int z = 0;
        cin>>z;
        a[i] = z;
    }
    long double l = 0;
    cin>>l;
    long double r =  x + d;
    for(int i = 0; i < 1000 ; i ++){
        if(r - l > 1e-13){
            long double sr = (r + l) / 2;
            long double y1 = resh_mn(a, size, sr);
            long double rst = distance1(x , y, sr, y1);
            //cout<<' '<<r<<' '<<l<<' '<<sr<<' '<<y1<<'\n';
            if(rst > d){
                r = sr;
            }
            else{
                l = sr;
            }}
        else{
            break;
        }

    }
    cout.precision(16);
    cout<<(r + l) / 2;
}
int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}
int mn_l(int l, int h, int w){
    return (l / h) *(l / w);
}
void diplom(){
    int w =0 , h = 0, n = 0;
    cin>>w>>h>>n;
    int l = 0;
    int r = n * max(w, h);
    while(l + 1 !=  r){
        int sr = (l + r) /2;
        if(mn_l(sr, h, w) > n){
            r = sr;
        }
        else{
            l = sr;
        }
    }
    cout<<r;
}
long min(long x ,long y){
    if(x < y){
        return x;
    }
    else{
        return y;
    }
}
void easy(){
    long long n, x, y;
        cin >> n >> x >> y;
        n--;
        long long l = 0, r = n*max(x, y), m;
        while (l < r){
            m = (r + l) / 2;
            if ((m / x + m / y) < n)l = m+1;
            else r = m;
        }
        cout << r + min(x,y);
}
void col_kor(){
    int  n = 0 , k  = 0;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i ++){
        int j =0 ;
        cin>>j;
        a[i] = j;
    }
    int l = 0;
    int r = a[n - 1] - a[0] + 1;
    while(l + 1 < r){
        int sr = (l + r) / 2;
        //cout<<sr<<'\n';
        int count = 0, sch = 0;
        for(int i = 0; i < n; i += 1){
            //cout<<a[i]<<' '<<sch<<' ';
            if( a[i] >= sch){
                count += 1;
                sch = a[i] + sr;
            }
        }
        if(count < k){
            r = sr;
        }
        else{
            l = sr;
        }
        
    }
    cout<<l;
    
}
void len_verev(){
    int n = 0, k = 0;
    cin>>n>>k;
    int a[n];
    for(int i = 0 ; i < n; i ++){
        int j = 0;
        cin>>j;
        a[i] = j;
    }
    int l = 0;
    int r = 100* 100*1000 + 1;
    while(l + 1 < r){
        int sr = (l  + r ) /2;
        int count = 0;
        for(int i = 0; i < n; i ++){
            if(a[i] / sr == 0){
                break;
            }
            else{
                count += a[i] / sr;
            }
        }
        if(count < k){
            r = sr;
        }
        else{
            l = sr;
        }
    }
    cout<<l;
    
}
void sch(){
    unsigned long long a = 0, b = 0, c = 0;
    cin>>a>>b>>c;
    unsigned long long ab = a*b, bc = b*c, ac = a*c;
    unsigned long long s = ab+ bc+ ac;
    cout<<(a*b*c)/s;
    
}
void preff(){
    int n = 0;
    cin>>n;
    int a[n];
    int s = 0;
    for(int i = 0 ; i < n; i ++ ){
        int j =0 ;
        cin>>j;
        a[i] = j;
        s += j;
        cout<<s<<' ';
    }
}
void prost(){
    int a = 0;
    cin>>a;
    bool flag = true;
    for(int i = 2; i <= pow(a, 0.5); i ++){
        if(a % i == 0){
            flag = false;
            break;
        }
    }
    if(flag) cout<<1;
    else cout<<0;
}
unsigned long long pow2(unsigned long long x, int n){
    unsigned long long s = 1;
    for(int i = 0; i < n; i ++){
        s*=x;
    }
    return s;
}
void calc(){
    unsigned long long x;
    cin>>x;
    if(x % 3 ==0){
        cout<<x/3;
    }
    else if(x % 3 == 2){
        cout<<((pow2(2,64) - 1 )/ 3) + (x/3) + 1;
    }
    else{
        cout<<((pow2(2, 64) - 1) / 3)*2 + (x / 3)  + 1;
    }
}
void resheto_eratnoswera(int a[] , int n){
    for(int i = 2; i <= pow(n , 0.5); i ++){
        if(a[i] == 0){
            for(int j = 2*i ; j < n; j += i){
                a[j] = 1;
                //cout<<j<<' ';
            }
        }
    }
    //return a;
}
int del(int a[], int n){
    for(int i = 2; i <= pow(n, 0.5); i ++){
        if(n % i == 0 && a[i] == 0){
            return i;
        }
    }
    return 0;
}
void sum_naim(){
    int n = 0;
    cin>>n;
    int a[n + 1];
    for(int i = 0; i< n + 1; i ++){
        a[i] = 0;
    }
    resheto_eratnoswera(a, n + 1);
    int sum = 0;
    for(int i = 3; i < n + 1; i ++){
        if(a[i] == 1){
            sum += del(a, i);
        }
    }
    cout<<sum;
}
unsigned long long fib(int n){
    unsigned long long x1 = 1;
    unsigned long long x2 = 1;
    unsigned long long x3 = 1;
    unsigned long long d = pow2(10,6) + 3;
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        for(int i = 2; i <= n; i ++){
            x3 = ((x1) %d + x2%d )  % d;
            x1 = x2;
            x2 = x3;
        }
    }
    return x3;
}
void fib1(){
    int n = 0;
    cin>>n;
    cout<<fib(n);
}
void ost(){
    unsigned long long a = 0, b = 0;
    cin>>a>>b;
    unsigned long long d = pow(10, 6)+ 7;
    a = (a%d*a%d)%d;
    b = (b%d*b%d)%d;
    cout<<(a%d - b%d)%d;
}
void fact(){
    unsigned long long d = pow(10, 6) + 3, n = 0,x3 = 1, x1 = 1, x2 = 1;
    cin>>n;
    if(n >= d){
        
    }
    for(int i =  2; i <= n; i ++){
        x3 = (x3*i) % d;
    }
    cout<<x3;
}
long long resh_mn1(int a[], int size, long long x, int m){
    long long answ = 1;
    for(int i = size; i != -1; i --){
        long long z = pow(x, (size - i));
        answ += (z%m * a[i]%m)%m;
    }
    return answ;
}
void fact1(){
    int size = 0 , m =0;
    cin>>size>>m;
    int a[size + 1];
    for(int i = 0; i < size+ 1; i ++){
        int f;
        cin>>f;
        a[i] = f;
    }
    bool flag = true;
    for(int i = 1; i < 2025;i ++){
        if(resh_mn1(a, size, i, m) == 0){
            cout<<i;
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<-1;
    }
}
long long mod1(long long n, int MOD) {
    return ((n % MOD) + MOD) % MOD;
}
long long comp_mod1(long long a, long long b, int MOD) {
    return mod1(mod1(a, MOD) * mod1(b, MOD), MOD);
}
long long sum_mod1(long long a, long long b, int MOD) {
    return mod1((mod1(a, MOD) + mod1(b, MOD)),MOD);
}
long long sh_mn(long long * a, long long size, long long x, long long m){ //развернутый массив
    long long res = a[0] % m;
    long long st = 1;
    for(int i = 1; i <= size; i++){
        st= comp_mod1(st, x, m);
        res = sum_mod1(res, comp_mod1(st, a[i], m), m);
    }
    return res;
}

void resh(){
    long long n = 0, m =0;
    cin>>n>>m;
    long long a[n + 1];
    for(int i = 0; i < n+ 1; i ++ ){
        long long f;
        cin>>f;
        a[n+ 1 - i - 1] = f;
    }
    bool flag = true;
    for(int i = 0; i <= m; i ++){
        if(sh_mn(a,n,i, m)  == 0){
            cout<<i;
            flag = false;
            break;
        }
    }
    if(flag) cout<<-1;
}
long long naim_del(long long a, long long b){
    if(a < 0) a *= -1;
    if(b < 0) b *= -1;
    while(a != 0 and b != 0){
        if(a > b){
            a = (a%b + b) % b;
        }
        else{
            b = (b%a + a) % a;
        }
    }
    return a+b;
}
void r(){
    long long n = 0, x1 = 0;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i ++){
        long long f = 0;
        cin>>f;
        a[i] = f;
    }
    for(int i = 1; i < n; i ++){
        long long n_d = naim_del(a[i - 1], a[i]);
        a[i] = n_d;
    }
    cout<<a[n - 1];
}


void resh_ev(){
    int a = 0, b = 0,c = 0;
    cin>>a>>b>>c;
    if(c % naim_del(a, b) == 0){
        cout<<1;
    }
    else cout<<0;
}
void sh_alg_evk(){
    int x = 0, y = 0;
    int count = 0;
    cin>>x>>y;
    while(x != 0 && y != 0){
        if(x > y){
            x = x%y;
        }
        else{
            y = y%x;
        }
        count ++;
    }
    cout<<count;
}

void check(){
    long long a = 0, b = 0;
    long long d = pow(10, 18);
    cin>>a>>b;
    if(a > d || b >d){
        cout<<-1;
    }
    else{
        long long gcd = naim_del(a, b);
        if(b / gcd < d/a){
            cout<<a/gcd*b;
        }
        else{
            cout<<-1;
        }
    }
}
long long mod_stp2(long long x, long long n, long long mod){
    if(n == 0) return 1;
    if(n % 2 == 1) return ((mod_stp2(x, n-1, mod)*x) % mod);
    else{
        long long s = (mod_stp2(x, n / 2, mod) % mod);
        return s*s;
    }
}
long long fast_pow(long long x, long long n){
    if(n == 0) return 1;
    if(n % 2 == 1) return ((fast_pow(x, n-1)*x));
    else{
        long long s = fast_pow(x, n / 2);
        return s*s;
    }
}
void mod(){
    long long n, m;
    cin>>n>>m;
    cout<<mod_stp2(n,n , m);
}
void s_c_h(){
    long double dz = 10e9 + 7;
    long double a = 0, b = 0, c = 0, d = 0;
    cin>>a>>b>>c>>d;
    long double ab = comp_mod1(a, mod_stp2(a,dz - 2 ,dz), dz);
    long double cd = mod1((c / d), dz);
    cout<<mod1(sum_mod1(ab, cd, dz), dz);
    
}

int gcd (int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long  max1(long long x ,long  long y){
    if(x > y){
        return x;
    }
    else{
        return y;
    }
}
void kuz(){
    long long n = 0;
    long long sum = 0, x0 = 0;
    cin>>n;
    long long a[n + 1];
    cin>>x0;
    a[0] = 0;
    a[1] = x0;
    for(int i = 2; i <= n; i ++){
        long long x = 0;
        cin>>x;
        a[i] = max1(a[i - 1], a[i - 2]) + x;
    }
    cout<<a[n - 1];
}

void kuz_4(){
    long long n = 0;
    long long sum = 0, x0 = 0;
    cin>>n;
    cout<<x0;
    long long a[n + 1];
    a[0] = x0;
    for(int i = 1; i < n + 1; i ++){
        long long x = 0, tmp1 = a[i - 1];
        long long tmp3 = tmp1, tmp5 = tmp1;
        cin>>x;
        if(i >= 3){
            if(i >= 5){
                tmp5 = a[i - 5];
            }
            tmp3 = a[i -3];
        }
        a[i] = max(max(tmp5, tmp3), tmp1) + x;
    }
    cout<<a[n];
}

void kuz_s_prep(){
    int n = 0;
    long long modd = 1000000000  + 7;
    cin>>n;
    long long a[n + 1];
    for(int i = 1; i <= n ; i ++){
        char f = 0;
        cin>>f;
        if(f  == '1'){
            a[i] = 0;
        }
        else a[i] = 1;
    }
    a[0] = 0;
    if (a[1] != 0) a[0] = 1;
    for(int i = 1; i <= n; i ++){
        long long tr1 = 0, tr2 = 0, tr3 = 0;
        if(a[i - 1] != 0) tr1 = a[i - 1];
        if(i >= 2 && a[i - 2] != 0){
            tr2 = a[i - 2];
        }
        if(i >= 3 && a[i - 3] != 0){
            tr3 = a[i - 3];
        }
        if(a[i] != 0){
            a[i] = (tr1 + tr2 + tr3) % modd;

        }
        cout<<a[i]<<' ';
    }
    //cout<<a[n];
    
}

void calc1(){
    int n = 0, s = 1, c_oper = 0;
    cin>>n;
    while(n != s){
        if(n % 3 == 0){
            n /= 3;
        }
        else if(n % 2 == 0){
            n /= 2;
        }
        else{
            n -= 1;
        }
        c_oper += 1;
    }
    cout<<c_oper;
}


void fast_kuz_s_prep(){
    int n = 0, k = 0;
    cin>>n>>k;
    long long mod = 1000000000  + 7;
    long long a[n + 1];
    long long q[n + 1];
    for(int i = 0 ; i < n ;i ++){
        char x;
        cin>>x;
        if(i < 2){
            q[i] = 1;
        }
        else if(i >= 2 && i <= k){
            if(x == '1'){
                q[i]  = 0;
            }
            else q[i] = 2*q[i - 1];
        }
        else{
            if(x == '1'){
                q[i] = 0;
            }
            else q[i] = 2*q[i - 1] - q[i - k - 1];
        }
        cout<<q[i]<< ' ';
    }
    /*cout<<'\n';
    a[0] = 0;
    for(int i = 1; i <= n; i ++){
        long long sr = 0;
        if(i - k - 1 >= 0){
            sr = q[i - k - 1];
        }
        a[i] = (q[i] - sr) % mod;
        //cout<<a[i]<<' ';
    }
    cout<<a[n];*/
}
void fast_calc1(){
    int n = 0 ;
    cin>>n;
    int a[n + 1];
    a[1] = 0;
        for(int i = 2; i <= n; i ++){
            int t3 = 10000000, t2 = 1000000;
            if(i % 3 == 0){
                t3 = a[i / 3];
            }
            if(i % 2 == 0){
                t2 = a[i / 2];
            }
            a[i] = min(min(t3, t2), a[i - 1]) + 1;
        }
    cout<<a[n];
}
void fast_fib(){
    int n = 0;
    cin>>n;
    if(n == 0){
        cout<<1;
        return;
    }
    else{
        long long a0 = 1;
        long long a1 = 1;
        long long a2 = a1 + a0;
        for(int i = 3; i <= n + 4; i ++){
            a0 = a1;
            a1 = a2;
            a2 = a0 + a1;
        }
        cout<<a2;
    }
}
void cher(){
    int n = 0 , m = 0;
    cin>>n>>m;
    //vector <vector <int>> a(n + 1, vector <int> (m + 1));
    //vector <vector <int>> dp(n + 1, vector <int> (m + 1));
    int a[n+ 1][m + 1];
    int dp[n + 1][m + 1];
    for(int i = 1; i<= n; i ++){
        for(int j = 1; j <= m; j ++){
            //for(int j = 1; j <= n; j ++){
            int x = 0;
            cin>>x;
            a[i][j] = x;
        }
    }
    //cout<<a[n][m];
    dp[1][1] = a[1][1];
    for(int i = 2; i <= m; i ++){
        dp[1][i] = dp[1][i - 1] + a[1][i];
    }
    for(int i = 2; i <= n; i ++){
        dp[i][1] = dp[i -1][1] + a[i][1];
    }
    for(int i = 2; i <= n; i ++){
        for(int j = 2; j <= m ; j ++){
            dp[i][j] = min(min(dp[i- 1][j - 1], dp[i-1][j] ), dp[i][j - 1] ) + a[i][j];
        }
    }
    cout<<dp[n][m];
}
void tur(){
    int m = 0, n = 0;
    cin>>m>>n;
    vector<vector <int>> a(n + 1, vector <int> (m + 1));
    vector<vector <int>> dp(n + 1, vector <int> (m + 1));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j<= m; j ++){
            int x = 0;
            cin>>x;
            a[i][j] = x;
        }
    }
    dp[1][1] = 0;
    for(int i = 2; i <= n; i ++){
        dp[i][1] = dp[i - 1][1]  + abs(a[i - 1][1] - a[i][1]);
    }
    for(int j = 2; j <=m ; j ++){
        dp[1][j] = dp[1][j - 1]  + abs(a[1][j - 1] - a[1][j]);
    }
    for(int i = 2; i <= n; i ++){
        for(int j  = 2; j <= m; j ++){
            dp[i][j] =min(abs(a[i][j] - a[i - 1][j]) + dp[i - 1][j], abs(a[i][j] - a[i][j - 1]) + dp[i][j- 1]);
            //cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
        }
    }
    cout<<dp[n][m];
}
void sor(){
    int n = 0, x = 0;
    cin>>n;
    vector<vector <int>> a(n + 1, vector <int> (n + 1));
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= n ; j ++){
            a[i][j] = 0;
        }
    }
    cin>>x;
    a[0][0]=x;
    cout<<'\n';
    for(int i = 1; i<n; i ++){
        int f = 1;
        for(int j = 0; j <= f; j ++){
            int x = 0;
            cin>>x;
            a[i][j] = x;
            cout<<i<<' '<<j<<' '<<a[i][j]<<'\n';
            }
        }
    
    cout<<a[n-1][n-1];
}
void ot(){
    int n =0;
    cin>>n;
    int x1 = -10000;
    int x2 = x1;
    int x3 = x2;
    for(int i =0; i < n; i++){
        int f = 0;
        cin>>f;
        if(f > x3){
            if(f > x2){
                if(f > x1){
                    x3 = x2;
                    x2 = x1;
                    x1 = f;
                }
                else{
                    x3 = x2;
                    x2 = f;
                }
            }
            else{
                x3 = f;
            }
        }
    }
    cout<<x1*x2*x3;
}
class bin_tree{
    struct node{
        node * l = 0;
        node * r = 0;
        int key;
        node(int(key)){this -> key = key;}
    };
    node * roots = 0;
    bool containts(node * n, int x) const{
        if(!n){
            return 0;
        }
        else if(x == n -> key){
            return 1;
        }
        else{
            if(n -> key > x){
                return containts((n ->l), x);
            }
            else return containts((n ->r), x);
        }
    }
    void add(node * n , int x) {
        if(!roots){
            roots = new node(x);
            return;
        }
        if(x == n -> key){
            return;
        }
        if(n -> key > x){
            if(n -> l == 0){
                n -> l = new node(x);
            }
            else{
                return add((n -> l), x);
            }
        }
        else{
            if(n -> r == 0){
                n -> r = new node(x);
            }
            else{
                return add((n -> r), x);
            }
        }
    }
    void print(node *n) const{
        if(!n){
            return;
        }

        print(n ->l);
        if(n-> l!= 0 && n -> r != 0){
            cout<<n -> key<<'\n';
        }
        print(n -> r);
    }
    void destroy(node *n) const{
        if(!n){
            return;
        }
        destroy(n -> l);
        destroy(n -> r);
        delete n;
    }
public:
    bool contains(int key){
        return containts(roots, key);
    }
    void print(){
        print(roots);
    }
    void add(int key){
        return add(roots, key);
    }
    ~bin_tree(){
        destroy(roots);
    }
};

class AVL_Tree{
    struct node{
        node * l = 0;
        node * r = 0;
        int balance = 0;
        int znach;
        node(int x){
            this -> znach = x;
        }
    };
    int height(node * a){
        return a?a->balance:0;
    }
    int b_factor(node * a){
        return height(a -> r) - height(a -> l);
    }
    void get_height(node *a){
        int hl = height(a->l);
        int hr = height(a->r);
        a -> balance = (hl > hr ?hl: hr) + 1;
    }
    node * right_rotation(node * a){
        node * l_uz = a -> l;
        a -> l = l_uz -> r;
        a = l_uz;
        l_uz ->  r = a;
        get_height(a);
        get_height(l_uz);
        return l_uz;
    }
    node * big_right_rotation(node * a){
        return a;
    }
    node * left_rotation(node * a){
        node * r_uz = a -> r;
        a -> r  = r_uz -> l;
        a ->l = r_uz;
        get_height(a);
        get_height(r_uz);
        return r_uz;
    }
    node * big_left_rotation(node * a){
        node * r = a -> r;
        node * zentr = r -> l;
        a -> r = zentr -> l;
        r -> l = zentr -> r;
        zentr -> l = a;
        zentr -> r = r;
        return zentr;
        
    }
};


void left_sd(int a[], int l){
    int t = a[0];
    int b[l];
    for(int i = 0; i < l; i ++){
        b[i] = a[i];
    }
    for(int i = 0; i < l; i ++){
        a[i] = b[i + 1];
    }
    a[l - 1] = t;
}
void  right_sd(int a[], int l){
    int t = a[l - 1];
    int b[l];
    for(int i = 0; i < l; i ++){
        b[i] = a[i];
    }
    for(int i = 1; i < l ; i ++){
         a[i] =  b[i-  1];
    }
    a[0] = t;
    
}
 
void sd(){
    int l = 0, sd;
    cin>>l>>sd;
    int a[l];
    int * c;
    for(int j = 0; j < l; j ++){
        int f = 0;
        cin>>f;
        a[j] = f;
    }
    c = a;
    if(sd < 0){
        for(int i = 0; i < (-1*sd) % l; i ++){
            left_sd(a, l);
        }
    }
    else{
        for(int i = 0; i < sd % l; i ++){
            right_sd(a,l);
        }
    }
    for(int i = 0; i < l -1; i ++){
        cout<<a[i]<<' ';
    }
    cout<<a[l -1];
    
    
}

int min_(int x, int y){
    if(x < y){
        return x;
    }
    else return  y;
}

int max_(int x, int y){
    if(x > y){
        return x;
    }
    else return y;
}
void game_of_trones(){
    long long n = 0, m = 0, q = 0;
    cin>>n>>m>>q;
    long long a[n + 1][m + 1];
    long long kol_ser = 0;
    for(int i =1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            a[i][j] = 0;
        }
    }
    for(int i = 0; i < q; i ++){
        long long y =0 , x = 0;
        cin>>x>>y;
        if(a[y][x] != 1){
            kol_ser += 1;
            a[y][x] = 1;
        }
    }
    cout<<(n *m) - kol_ser<<'\n';
    for(int j =1; j <= m; j ++){
        for(int i = 1; i <= n; i ++){
            if(a[i][j] == 0){
                cout<<j<<' '<<i<<'\n';
            }
        }
    }
}

void sleep(){
    int n =0;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i ++){
        int tv = 0;
        cin>>tv;
        a[i] = tv;
    }
    int pref[n];
    int s = 0;
    for(int i = 0; i <n ; i ++){
        pref[i] = s + a[i];
        s += a[i];
    }
    bool flag = true;
    for(int i = 0; i < n; i ++){
        int sl = 0;
        if(i != 0){
            sl = pref[i - 1];
        }
        int rl = pref[n - 1] - pref[i];
        if (sl == rl){
            cout<<i;
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<-1;
    }
}
void ege(){
    int n = 0;
    cin>>n;
    for(int i = 0 ; i < n; i ++){
        int x = 0, l = 15, r =30;
        cin>>x;
        for(int j = 0; j < n; j ++){
            string f;
            cout<<f<<'\n';
            int ch = 0;
            cin>>f>>ch;
            if(f == "≥"){
                cout<<"dnk sclas;dx";
                if (l < ch){
                    l = ch;
                }
            }
            else{
                if(r > ch){
                    r = ch;
                }
            }
        }
        cout<<'\n';
        if(r == l){
            cout<<r<<'\n';
        }
        else if(r > l){
            cout<<l<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
    }
}

void viasma(){
    int n = 0;
    cin>>n;
    int a[n];
    for(int i = 0; i < n ; i++){
        int x;
        cin>>x;
        a[i] = x;
    }
    int count = 0;
    int tarakn = a[n - 1];
    for(int i = 0; i < n; i ++){
        if((tarakn  | a[i]) !=  tarakn + a[i]){
            count += 1;
            tarakn = a[i];
        }
        else{
            tarakn = tarakn | a[i];
        }
        //rcout<<i<<' '<<tarakn<<'\n';
    }
    if(count == 0){
        count += 1;
    }
    cout<<count;
}


void merge(a, n, )
void merge_sort(int * a, int l, int r ){
    if(l + 1 >= r){
        return;
    }
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid, r);
    
}
int main() {
    /*while(cin.get(c))
     if(c != ' '){
     cout << c;
     is_ok = true;
     }else if(is_ok) {
     cout << c;
     is_ok = false;
     }
     int i = 0;
     cin>>i;
     for(int j = 0; j < i; j++){
     int f = 0;
     cin>>f;
     log_2(f);
     }
     int x,y = 0;
     cin>>x;
     cin>>y;
     int f = gcd(x, y);
     cout<<f;
     int x[] = {1,2,3,4,5,6,7};
     char * x =  new char [10];
     for(int i = 0; i < 10; i ++){
     x[i] = i + 65;
     }
     8
     01100010
     1 0 0 1 1 2 0 3
     cout<<*x<<*(x + 3);
     char * y  = resize(x,10,5);
     cout<<*(y + 5);*/
    //cout<<getline1();
    //char z[] = {'0','1','2','3', '4'};
    //hash_str * a[10];
    //for(int i = 0; i < 10; i ++){
    //  hash_str f;
    //a[i] = &f;
    //}
    //hash_table_write(a,2, 89818293, "K");
    //hash_table_write(a,2, 8, "K");
    //hash_table_write(a,3, 8, "KIR");
    //cout<<1;
    //hash_str * hash_t = hash_table_read(a,2,"I");
    //cout<<(*hash_t).number;
    /*Cls a('a', 100, 5);
     Cls * b = &a;
     char * U = (char *)(b);
     double * F = (double *)((char *)(b) + 8);
     int * Z = (int *)((char *)(b) + 16 );
     cout<<*F;
     cout<<*Z;
     cout<<*U;
     //cout<<*(F + 1);
     //cout<<*Z;
     *F = 'B';
     //a.ct();р
     //cout<<*(int *)(b + 4);*/
    //char msg []  = {'a','b','c','d'};
    //max_min_rev();
    //resh_mng();
    //int a[17] = {0};
    //resheto_eratnoswera(a, 17);
    //for(int i = 0; i < 17; i ++){
    //  cout<<a[i]<<' ';  // от 0 до 9 включительно
    //}
    //cout<<(101 + 200) % 3;
    //cout<< (101% 3 + 200 % 3) %3;
    //long long a= 3, b = 1;
    //long long r = naim_del(a, b);
    //bool l = r == naim_del(a + b, b), l1 = r == naim_del(a - b,b), l2 = r == naim_del(a% b,b), l3 = r == naim_del(a + b,a - b), l4 = r == naim_del(a % b,a);
    //cout<<l<<' '<<l1<<' '<<l2<<' '<<l3<<' '<<l4<<' '
    viasma();

    return 0;

}


