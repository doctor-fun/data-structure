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
