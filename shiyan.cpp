#include <stdio.h>
void Get_Next(int str_len,char T[], int next[])
{
    int i=1,j=0;
    next[0]=0;
    next[1]=0;
    while(i<=str_len)
    {
        if(j==0||T[i-1]==T[j-1])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}
int KMP(int str_len,char S[],int sub_len, char T[], int next[])
{
    int i = 1, j = 1;
    while (i <= str_len && j <= sub_len)
    {
        if (T[j-1] == S[i-1] || j == 0)
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > sub_len)
        return i-sub_len;
    else
        return 0;
}
int main()
{
    while (true)
    {
        /* code */
    
    char str[50], substr[20];
    int next[50]={0},str_len,sub_len;
    printf("�����ַ���������:");
    scanf("%d", &str_len);
    getchar();
    scanf("%s",str);
    printf("�����Ӵ�������:");
    scanf("%d", &sub_len);
    getchar();
    scanf("%s", substr);
    Get_Next(str_len,str, next);
    int a = KMP(str_len,str,sub_len, substr, next);
    if (a)
        printf("�Ӵ����ַ����ĵ�%d��λ��\n\n\n", a);
    else
        printf("�ַ�����û�д��Ӵ�\n\n\n");
    }
    getchar();
    getchar();
    getchar();
}