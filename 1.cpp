

//1033 未解决

//1067 ac

//1038 ac  		 用的string

//1085 24/25

//1010 

//1044

//1048 多种方法

//1089

//1029

//1101

//1051 ac		stack,注意判断栈空

//1056 

//1003B

//1039 ac 		vector,用hash把名字转换成int

//1047 ac       用string会超时,要用char[]

//1063 ac		set答案

//1060 ac   	string答案

//1100 ac    	map答案

//1054 ac		map

//1071 ac		map

//1022 ac		map<string,set<int>>

//1056 ac		queue

//1103 ac		DFS

//1074 19/25

//1032 24/25	一个测试点超时 //用bool标记结点

//1052 ac		link

//1097 ac		link
记住link的模板

--//1091 

//DFS
void DFS(int index,int nowK,int sum,int facsum)
{
	if(是否满足所需条件)
	{
		更新结果;
	}
	//选择此层
	DFS(index,nowK+1,sum+,facsum+)
	//不选择此层
	DFS(index+1,nowK,sum,facsum)
}