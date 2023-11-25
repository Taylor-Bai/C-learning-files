

for循环更合适<font color=orange>事先知道循环总次数</font>的场景，一般与计数器或数组结合一起使用。

while循环更合适事先不知道循环总次数的场景，以<font color=orange>达到某个目标为目</font>，例如超女选秀，报名有多少人没关系，已选够10位或没人可选是循环的结束。

**for性能和while等价，可以互相转换**

各种循环的执行顺序：

    for (语句1;表达式2;语句4)
    {
        语句块3
    }
    先初始化1，再234循环



哈希表的滑动窗口
哈希表：

    // 常用函数
    unordered_map <int, int> cnt;
    cnt.size();                     // 得到键值对数量
    cnt[key] = value;               // 赋值
    unordered_map<int, int>::iterator iter = cnt.begin();   // 得到指向哈希表头位置的指针
    unordered_map<int, int>::iterator iter = cnt.end();    // 得到指向哈希表尾位置的指针
    cnt.erase(iter_begin);          // 删除键值
    cnt.at(3);                      // 通过key查询value
    iter = cnt.find(2);             // 通过key查询位置
    iter->first;                    // 通过索引查询key
    iter->second;                   // 通过索引查询value
