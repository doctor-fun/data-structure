%f: 会输出小数点后6位
%u,十进制无符号
%o,八进制整数
%x,十六进制输入输出一个整数
%d，十进制输出一个整数
整数/小数，获得小数
小写字母的ascii码值大于大写字母的ascii码值
八位数是0开头，16位是0x开头
1)rewind(fp)回到文件头
2)fseek(fp,offset,from);
from:
seek_set、
seek_cur、
seek_end;
3)获取当前读写位置指针的位置：距离文件开头位移量
4）while(!feof(fp))
判断是否读到文件尾

fgets() fputc() 字符操作
fputs() fgets() 字符串操作

putc()等价于fputc,getc()等价于fgetc()

fscanf()    将代表数字的字符转换为数字
fprintf()  控制格式输入输出,

fread() fwrite()  二进制
encrypt（）函数加密


c语言事先定义好的宏
__LINE__
__FILE__
__DATE__
__TIME__
__STDC__
int main(int argc,char const *argv[])
{
    printf("%s:%d\n",_FILE_,_LINE_);
    return 0;
}
while(!foef(fp1));
fp=fopen(fname," ");这里的双引号别忘了加
2^n=pow(2,n);

