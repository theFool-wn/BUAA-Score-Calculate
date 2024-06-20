# 介绍
用于计算BUAA的GPA、加权平均分、算数平均分

# 计算方法

$$ 平均学分绩点(GPA)=\dfrac{\sum每门课程GPA \times 对应学分}{总学分} $$
$$ 加权平均分=\dfrac{\sum每门课程的成绩 \times 对应学分}{总学分} $$

对于每门课程的GPA
1. 百分制课程，成绩为$X$
$$ GPA= 
\left\{
	\begin{aligned}
		&4-\dfrac{3\times(100-X)^2}{1600} &, X \ge 60 \\
		&0 &, X<60
	\end{aligned}
\right. $$
2. 五级制课程
绩点对应：4(优秀)，3.5(良好)，2.8(中等)，1.7(及格)，0(不及格)；
成绩对应：90(优秀)，80(良好)，70(中等)，60(及格)，0(不及格)；
3. 两级制：
通过/不通过，不计入成绩，即计算时不考虑

# __注意！！！__

1. 真实成绩计算时，五级制课程GPA按照对应绩点转换计算，而本程序按照成绩转换后再计算对应GPA用于总成绩计算，因此计算结果偏__保守__
2. 本程序计算结果只用来作为参考，__不应该将其直接作为真实成绩以及各种评分依据__，对计算结果不做任何担保

# 使用方法
1. 下载源代码自行编译或者已编译好的[可执行文件]()
2. 在可执行文件所在目录下，创建两个文本文档`in1.txt`和`in2.txt`，__名字不能改变__，三个文件必须在__同一目录下__
3. `in1.txt`和`in2.txt`分别存放两套成绩，在本程序中分别用于计算全部课程的成绩以及必修课程（自己定义哪些是必修课）的成绩，_但实际上程序只是同时计算出两套成绩，因此可以直接在这两个文本文档中存放自己想要计算的成绩，只是输出结果的名称并不对应而已_
4. 在每个文本文档中的数据格式为`成绩 对应学分 成绩 对应学分...`，每两个数据之间必须有空格，允许换行，__但每行最后不应有空格__，建议每学期成绩一行，便于管理
5. 将`in1.txt`和`in2.txt`保存，双击可执行文件BUAA Score Calculate.exe

# 报错
当程序发出错误警告，应检查数据的正确性，主要错误原因包括：
+ 某行结尾有多余空格
+ 成绩超出0~100
+ 学分为负数


# LICENSE
This work is licensed under a [Apache-2.0 license](/LICENSE).

&copy; 2024 Wang Nan.