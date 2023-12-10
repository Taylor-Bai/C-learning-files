

for循环更合适<font color=orange>事先知道循环总次数</font>的场景，一般与计数器或数组结合一起使用。

while循环更合适事先不知道循环总次数的场景，以<font color=orange>达到某个目标为目</font>，例如超女选秀，报名有多少人没关系，已选够10位或没人可选是循环的结束。

**for性能和while等价，可以互相转换**

各种循环的执行顺序：

    for (语句1;表达式2;语句4)
    {
        语句块3
    }
    先初始化1，再234循环



int,long,long long大小问题

short 2字节  -2^15 ~ 2^15-1      (-32768~32767)             约等于 3 * 10^4

int   4字节  -2^31 ~ 2^31-1      (-2,147,483,648~2,147,483,647) 约等于 2 * 10^9
                
long  8字节  -2^63 ~ 2^63-1                                 约等于 9 * 10^18



// 数组的用法 //
数组相比与容器的储存方式，是固定长度的

    // 初始化
    int array[1000] = {0};              // 初始化全为零的数组


// vector的通常用法 //

    vector<int> nums;

    遍历：
    for(int num : nums){num = ...}
    for(int i=0;i < nums.size();i++>){nums[i] = ...}

哈希表：

// map 常用函数 //

    unordered_map <int, int> cnt;
    cnt.size();                     // 得到键值对数量
    cnt[key] = value;               // 赋值
    unordered_map<int, int>::iterator iter = cnt.begin();   // 得到指向哈希表头位置的指针
    unordered_map<int, int>::iterator iter = cnt.end();    // 得到指向哈希表尾位置的指针
    cnt.erase(iter_begin);          // 删除键值
    cnt.at(3);                      // 通过key查询value
    iter = cnt.find(2);             // 通过key查询位置,存在，则返回指针；不存在，则返回map.end()
    iter->first;                    // 通过索引查询key
    iter->second;                   // 通过索引查询value

    // 插入
    cnt[key] = value;                           // 一种插入，没有则生成一个
    map.insert(pair<int, int>(key, value))      // 另一种插入





// set 常用函数  //

    // 初始化
    unordered_set<int> set1(nums1.begin(),nums1.end());     // 用vector对set进行初始化

    set.insert(3);                  // 如果已经在set中存在，则3不会被插入
    set.insert(3).second            // 插入，并返回是否成功插入



// pair类型常用函数 //

    pair<string,int> p1("baitian",15);           // 定义(本质是一个结构体)
    p1.first;
    p1.second


// string类型常用函数 // 
string是按照数组形式存储的，具有数组相同的访问；
s.resize(s.zie() + cnt*5)           // 扩张数组

reverse(s.begin(),s.end());         // 反转字符串(左闭右开);

s.find（str，pos）                  // 在字符串s里面从pos位置开始找str，找到返回索引，找不到返回string::npos
    