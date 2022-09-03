Change Major.

乐谱转调
例如将G调转成C大调。

分为三个模块:
输入模块Input
转换模块Transfer
输出模块Output


导入的乐谱格式：
1. ()表示低音
2. []表示高音
3. b表示降半音阶
4. #表示升半音阶

例如：
(#2) 或者 #(2)表示低音升2
[b3] 或者 b[3] 表示高音降3

会过滤掉无关的字符，
仅保留 数字 1-9 (  ) [ ] # b

目前仅支持 .txt文件



设计思路：
0 定义enum 值
enum scale{
	scale_1,
	scale_b2,	//#1  = b2
	scale_2,
	scale_b3,	//#2 = b3
	scale_3,
	scale_4,
	scale_b5,	//#4 = b5
	scale_5,
	scale_b6,	//#5 = b6
	scale_6,
	scale_b7,	//#6 = b7
	scale_7
};

1 输入文件路径，读取文件
2 输入当前乐调的乐调和想要转换的乐谱乐调
3 遍历一次文件，保留数字(即音符)，根据上述的enum 转成int

如：
  	(1)        #1         (2) 	   (#2)       3		  (4)
==>
enum：scale_1   scale_1     scale_2    scale_2    scale_3	scale_4
int：    0 	     0		 2	     2	      4		   5

4 用flag 表示高低音。
若是有()，表示低音，flag -1； 若是有[],表示高音，flag+1
-1 0 -1 -1 0 0
 0 0  2	 2 4 5

5 对于 # 和 b，表示升降半音。#表示对当前音符+1 ；b表示对当前音符-1
音符: (1) #1 (2) (#2) 3 (4)
flag: -1  0  -1  -1   0  0
int:   0  1   2   3   4  5

6 重新转换回char

flag = -1，int = 0；表示低音 1 ==>   (1)
flag = 0， int = 1；表示中音 1 ==>    1
flag = -1，int = 3；表示低音 升2 ==> (#2)