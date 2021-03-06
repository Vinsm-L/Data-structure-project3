# 家谱管理

## 架构
![架构](http://p1.bpimg.com/567571/90ad3a640f169b8b.png)

数据层为tree类，包含二叉树及其对应的成员方法；逻辑层为service类，可以对家谱进行一系列操作；交互层为菜单，建议封装成类。

## 树节点
### 用结构体实现：
1. 姓名
2. 性别
3. 是否在世
4. 指针

```
struct Tnode {
	string name;
	bool gender;  // 0 represents male while 1 represents female
	bool alive;  // 0 represents dead while 1 represents alive
	Tnode* left, right, forward; // forward points to its parent node
};
```

### 用二叉树储存家庭关系的基本结构
![二叉树](http://i1.piimg.com/567571/1939ef019a9616d1.png)

## 输入
### 一次输入包括：
1. 姓名、性别、是否在世
2. 妻子姓名、性别、是否在世
3. 子女姓名、性别、是否在世
4. 兄弟姐妹姓名、性别、是否在世(仅在建立根节点时需要输入)

### 输入的要求:
* 所有输入均是以家谱中的男性为出发点
* 不输入女性节点的丈夫、子女
* 人名不重复

