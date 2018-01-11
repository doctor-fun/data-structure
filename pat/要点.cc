scanf（
内双引号内的内容其实就是整个输入，只不过把数据换成它们对应格式符并把变量的地址按次序写在后面而已
%c格式可以读入空格和换行（同printf）
除了%c外，scanf输入时以空格和tab作为结束判断标志
%s以空格和换行作为读入结束的标志(同printf)
）
%md,m位内的整数右对齐输出，不够m位的空格补齐
%0md,m位内的整数右对齐输出，不够m位的0补齐
%.mf浮点数保留m位小数输出（四舍六入五成双）

getchar输入单个字符,getchar（'\n'）可以识别换行符,putchar输出换行符

typedef取一个别名
fabs(double x)取绝对值
floor(double x) ceil(double x)向下取整和向上取整
pow(double r,double p) 返回r^p
sqrt（double x);
log(double x)；底数位自然对数
sin(double x),cos(double x),tan(double x)
asin,acos,atan...
round(double x)
swicth case()
for(循环变量附初值；循环条件；循环变量改变)
break，退出整个循环
continue 退出当前循环

二维数组赋初值{{},{},{}},一行一行的进行定义，没定义的自动赋为0；
string.h:memset(数组名，值，sizeof(数组名))
fill  std::fill(v.begin(), v.end(), -1);
gets 识别\n作为结束符（比scanf更严格）
puts 自动带一个\n
如果先scanf再gets,则需要scanf+getchar()+gets();因为scanf输入结束提交时要输入\n，而scanf并不会接收\n,如果没有getchar,则gets()接收到\n,
那么此时scanf和gets都结束了
只有scanf和gets会自动在字符串后面加\0
strlen()可以得到第一个\0前的字符的个数
strcmp()  <0;=0;>0
strcpy() 清空字符串1，将字符串2（包括\0）填到字符串1中
strcat() 去掉字符串1的\0,将字符串2接到字符串1后面


sscanf(str,"%d",&n);将str内容以%d的方式输入到n中；
springt(str,"%d",n);将n的内容以%d的方式输入到str中去；

数组作为函数的参数改变的是原位置的值
指针减法是两个地址位置的偏移（以基类型为单元）
p+1是p所指的int型变量的下一个int型变量首地址(假如p所指的是int)
p++=p+1=&a[1]
（表达式）？（） ：（）

to_string:-1999转换成string后，-号占一个字节
c_str();字符数组

size_type position=a.find('c');
while(position!=string::nops)
{


}

这时候, (a|b) 描述了 a 和 b, 整体加了一个 *, 意味者我们可以任意选 a 或者 b 一个接一个拼起来,

string a;
cin.getline(a,100000);
getline(cin,a)
或者
char a[100000];
gets(a);
string str_a(a)

unsigned int printf("%u",n);
