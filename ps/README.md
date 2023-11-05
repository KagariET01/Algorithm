# Codebook 補充資料

## stringstream
關於stringstream，說直白一點，你可以把它想像成cin和cout  

### 輸入
`code.cpp`
```c++
stringstream ss;
ss<<"Hello World";
ss<<"hihi"<<endl;
```
`ss.txt`
```txt
Hello Worldhihi

```

### 輸出
`code.cpp`
```c++
stringstream ss;
//...
string s;
while(ss>>s){
	cout<<s<<endl;
}
```
`.out`
```txt
Hello
Worldhihi
```

`code.cpp`
```c++
stringstream ss;
//...
string s;
while(getline(ss,s)){
	cout<<s<<endl;
}
```
`.out`
```txt
Hello Worldhihi
```


## getline
獲取一行字串
```c++
getline(cin,s);
```
逗號分隔
```c++
getline(cin,s,',');
```


## permutation
排列
`code.cpp`
```c++
do{
	/*do something*/
}while(next_permutation(v.begin(),v.end()));
do{
	/*do something*/
}while(prev_permutation(v.begin(),v.end()));
```
`.out`
```txt
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

...
```

