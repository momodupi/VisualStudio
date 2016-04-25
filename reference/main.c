#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#pragma warning(disable:4996) 

struct SerialType
{
	char Author[256];
	char Title[256];
	char Name[512];
	char Time[128];
	char Type[2];
	char No[128];
	char Pages[64];
	char Publisher[256];
	char Place[256];
	char Country[256];
};

int num = 0;
int choose = 0;
int close_flag = 0;
char Debug[2];
FILE *fp;

/*期刊文献*/
void WriteJournals(void)
{
	struct SerialType Buffer[256];
	struct SerialType *Journals;
	Journals = Buffer;
	printf("****************************************************************\n");
	printf("*                        期刊文献 (-ω-)                       *\n");
	printf("****************************************************************\n\n");
	printf("作者： （如：张三, 赵四）\n");
	scanf("%s", Journals->Author);
	printf("题目：\n");
	gets(Debug);
	scanf("%s", Journals->Title);
	printf("期刊名：\n");
	gets(Debug);
	scanf("%s", Journals->Name);
	printf("出版年份：\n");
	gets(Debug);
	scanf("%s", Journals->Time);
	printf("卷号(期号):起止页码： （如：31-34）\n");
	scanf("%s", Journals->No);
	printf("\n[%d]%s.%s[J].%s,%s,%s.\n", (++num), Journals->Author, Journals->Title, Journals->Name, Journals->Time, Journals->No);
	fprintf(fp, "[%d]%s.%s[J].%s,%s,%s.\n", (num), Journals->Author, Journals->Title, Journals->Name, Journals->Time, Journals->No);
	printf("****************************************************************\n\n");
}

/*普通图书*/
void WriteMonographs(void)
{
	struct SerialType Buffer[256];
	struct SerialType *Monographs;
	Monographs = Buffer;
	printf("****************************************************************\n");
	printf("*                        普通图书 (-ω-)                       *\n");
	printf("****************************************************************\n\n");
	printf("作者： （如：张三, 赵四）\n");
	scanf("%s", Monographs->Author);
	printf("书名：\n");
	gets(Debug);
	scanf("%s", Monographs->Title);
	printf("版本： （第一版不写）\n");
	gets(Debug);
	scanf("%s", Monographs->No);
	printf("出版地:出版社：\n");
	gets(Debug);
	scanf("%s", Monographs->Place);
	printf("出版年份:起止页码：\n");
	gets(Debug);
	scanf("%s", Monographs->Time);
	printf("\n[%d]%s.%s[M].%s,%s,%s.\n", (++num), Monographs->Author, Monographs->Title, Monographs->No, Monographs->Place, Monographs->Time);
	fprintf(fp, "[%d]%s.%s[M].%s,%s,%s.\n", num, Monographs->Author, Monographs->Title, Monographs->No, Monographs->Place, Monographs->Time);
	printf("****************************************************************\n\n");
}

/*专著析出文献*/
void WriteContributions(void)
{
	struct SerialType Buffer[256];
	struct SerialType *Contributions;
	Contributions = Buffer;
	printf("****************************************************************\n");
	printf("*                      专著析出文献 (-ω-)                     *\n");
	printf("****************************************************************\n\n");
	printf("作者： （如：张三, 赵四）\n");
	scanf("%s", Contributions->Author);
	printf("题目：\n");
	gets(Debug);
	scanf("%s", Contributions->Title);
	printf("专著类型： C：论文集 M：专著\n");
	gets(Debug);
	scanf("%s", Contributions->Type);
	printf("专著作者：\n");
	gets(Debug);
	scanf("%s", Contributions->Name);
	printf("专著题名：\n");
	gets(Debug);
	scanf("%s", Contributions->No);
	printf("出版地:出版社：\n");
	gets(Debug);
	scanf("%s", Contributions->Place);
	printf("出版年份:起止页码：\n");
	gets(Debug);
	scanf("%s", Contributions->Time);
	printf("\n[%d]%s.%s[%s]//%s.%s.%s,%s.\n", (++num), Contributions->Author, Contributions->Title, Contributions->Type, Contributions->Name, Contributions->No, Contributions->Place, Contributions->Time);
	fprintf(fp, "[%d]%s.%s[%s]//%s.%s.%s,%s.\n", num, Contributions->Author, Contributions->Title, Contributions->Type, Contributions->Name, Contributions->No, Contributions->Place, Contributions->Time);
	printf("****************************************************************\n\n");
}

/*学位论文*/
void WriteDissertations(void)
{
	struct SerialType Buffer[256];
	struct SerialType *Dissertations;
	Dissertations = Buffer;
	printf("****************************************************************\n");
	printf("*                        学位论文 (-ω-)                       *\n");
	printf("****************************************************************\n\n");
	printf("作者： （如：张三, 赵四）\n");
	scanf("%s", Dissertations->Author);
	printf("题目：\n");
	gets(Debug);
	scanf("%s", Dissertations->Title);
	printf("保存地:保存单位：\n");
	gets(Debug);
	scanf("%s", Dissertations->Place);
	printf("年份：\n");
	gets(Debug);
	scanf("%s", Dissertations->Time);
	printf("\n[%d]%s.%s[D].%s,%s.\n", (++num), Dissertations->Author, Dissertations->Title, Dissertations->Place, Dissertations->Time);
	fprintf(fp, "[%d]%s.%s[D].%s,%s.\n", num, Dissertations->Author, Dissertations->Title, Dissertations->Place, Dissertations->Time);
	printf("****************************************************************\n\n");
}

/*科技报告*/
void WriteReports(void)
{
	struct SerialType Buffer[256];
	struct SerialType *Reports;
	Reports = Buffer;
	printf("****************************************************************\n");
	printf("*                        科技报告 (-ω-)                       *\n");
	printf("****************************************************************\n\n");
	printf("作者： （如：张三, 赵四）\n");
	scanf("%s", Reports->Author);
	printf("题目：\n");
	gets(Debug);
	scanf("%s", Reports->Title);
	printf("报告地:主办单位：\n");
	gets(Debug);
	scanf("%s", Reports->Place);
	printf("报告年份：\n");
	gets(Debug);
	scanf("%s", Reports->Time);
	printf("\n[%d]%s.%s[R].%s,%s.\n", (++num), Reports->Author, Reports->Title, Reports->Place, Reports->Time);
	fprintf(fp, "[%d]%s.%s[R].%s,%s.\n", num, Reports->Author, Reports->Title, Reports->Place, Reports->Time);
	printf("****************************************************************\n\n");
}

/*专利文献*/
void WritePatents(void)
{
	struct SerialType Buffer[256];
	struct SerialType *Patents;
	Patents = Buffer;
	printf("****************************************************************\n");
	printf("*                        专利文献 (-ω-)                       *\n");
	printf("****************************************************************\n\n");
	printf("专利申请者： （如：张三, 赵四）\n");
	scanf("%s", Patents->Author);
	printf("专利题名：\n");
	gets(Debug);
	scanf("%s", Patents->Title);
	printf("申请国别：\n");
	gets(Debug);
	scanf("%s", Patents->Country);
	printf("专利号：\n");
	gets(Debug);
	scanf("%s", Patents->No);
	printf("公告日期[引用日期]：\n");
	gets(Debug);
	scanf("%s", Patents->Time);
	printf("\n[%d]%s.%s[P].%s:%s,%s.\n", (++num), Patents->Author, Patents->Title, Patents->Country, Patents->No, Patents->Time);
	fprintf(fp, "[%d]%s.%s[P].%s:%s,%s.\n", num, Patents->Author, Patents->Title, Patents->Country, Patents->No, Patents->Time);
	printf("****************************************************************\n\n");
}

/*报纸文献*/
void WriteNewspapers(void)
{
	struct SerialType Buffer[256];
	struct SerialType *Newspapers;
	Newspapers = Buffer;
	printf("****************************************************************\n");
	printf("*                        报纸文献 (-ω-)                       *\n");
	printf("****************************************************************\n\n");
	printf("作者： （如：张三, 赵四）\n");
	scanf("%s", Newspapers->Author);
	printf("题目：\n");
	gets(Debug);
	scanf("%s", Newspapers->Title);
	printf("报纸名：\n");
	gets(Debug);
	scanf("%s", Newspapers->Name);
	printf("出版时间(版次)：\n");
	gets(Debug);
	scanf("%s", Newspapers->Time);
	printf("\n[%d]%s.%s[N].%s,%s.\n", (++num), Newspapers->Author, Newspapers->Title, Newspapers->Name, Newspapers->Time);
	fprintf(fp, "[%d]%s.%s[N].%s,%s.\n", num, Newspapers->Author, Newspapers->Title, Newspapers->Name, Newspapers->Time);
	printf("****************************************************************\n\n");
}

/*论文集、会议录*/
void WriteCollections(void)
{
	struct SerialType Buffer[256];
	struct SerialType *Collections;
	Collections = Buffer;
	printf("****************************************************************\n");
	printf("*                      论文集、会议录 (-ω-)                     *\n");
	printf("****************************************************************\n\n");
	printf("作者： （如：张三, 赵四）\n");
	scanf("%s", Collections->Author);
	printf("题目：\n");
	gets(Debug);
	scanf("%s", Collections->Title);
	printf("出版地:出版单位：\n");
	gets(Debug);
	scanf("%s", Collections->Place);
	printf("出版年份:起止页码：\n");
	gets(Debug);
	scanf("%s", Collections->Time);
	printf("\n[%d]%s.%s[C].%s,%s.\n", (++num), Collections->Author, Collections->Title, Collections->Place, Collections->Time);
	fprintf(fp, "[%d]%s.%s[C].%s,%s.\n", num, Collections->Author, Collections->Title, Collections->Place, Collections->Time);
	printf("****************************************************************\n\n");
}

/*国际、国际标准*/
void WriteStandards(void)
{
	struct SerialType Buffer[256];
	struct SerialType *Standards;
	Standards = Buffer;
	printf("****************************************************************\n");
	printf("*                      国际、国际标准 (-ω-)                   *\n");
	printf("****************************************************************\n\n");
	printf("标准名称：\n");
	scanf("%s", Standards->Title);
	gets(Debug);
	printf("标准编号：\n");	
	scanf("%s", Standards->No);
	printf("\n[%d]%s.%s.\n", (++num), Standards->Title, Standards->No);
	fprintf(fp, "[%d]%s.%s.\n", num, Standards->Title, Standards->No);
	printf("****************************************************************\n\n");
}

void SaveAndClose(void)
{
	fclose(fp);
	system("参考文献.txt");
	close_flag = 1;
}



int main(void)
{
	printf("**********************************************************************\n");
	printf("*                ('ω')欢迎使用参考文献助手v1.1                      *\n");
	printf("*      　  妈妈再也不用担心我的参考文献格式排版啦(^▽^)              *\n");
	printf("*                                                                    *\n");
	printf("* 软件作者：邵仕平                                                   *\n");
	printf("* 软件版本：v1.1                                                     *\n");
	printf("* 软件功能：参考文献自动排版                                         *\n");
	printf("* 使用方法：依据提示选择文献种类，并输入相关信息。                   *\n");
	printf("*           结果保存在安装目录<参考文献.txt>中。复制到文档即可。     *\n");
	printf("*           输入“:”等标点符号时请使用英文半角输入。                *\n");
	printf("*           粘贴文字方法：右键标题栏 -> 编辑 -> 粘贴。（尽量打字）   *\n");
	printf("*           在输入日期、时间、卷号等数字时尽量不要使用粘贴。         *\n");
	printf("*           避免直接从PDF文档粘贴。                                  *\n");
	printf("**********************************************************************\n\n");
	fp = fopen("参考文献.txt", "w+");
	fprintf(fp, "**********************************************************************\n");
	fprintf(fp, "*                ('ω')欢迎使用参考文献助手v1.1                      *\n");
	fprintf(fp, "*      　  妈妈再也不用担心我的参考文献格式排版啦(^▽^)              *\n");
	fprintf(fp, "*                                                                    *\n");
	fprintf(fp, "* 软件名称：参考文献助手                                             *\n");
	fprintf(fp, "* 软件作者：邵仕平                                                   *\n");
	fprintf(fp, "* 软件版本：v1.1                                                     *\n");
	fprintf(fp, "* 软件功能：参考文献自动排版                                         *\n");
	fprintf(fp, "* 使用方法：复制到文档即可。                                         *\n");
	fprintf(fp, "**********************************************************************\n\n");
	
	while (1)
	{
		printf("请选择参考文献种类：\n\n");
		printf("1.期刊文献          2.普通图书\n");
		printf("3.专著析出文献      4.学位论文\n");
		printf("5.科技报告          6.专利文献\n");
		printf("7.报纸文献          8.论文集、会议录\n");
		printf("9.国际、国际标准    0.保存并退出\n\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: WriteJournals(); break;
		case 2: WriteMonographs(); break;
		case 3: WriteContributions(); break;
		case 4: WriteDissertations(); break;
		case 5: WriteReports(); break;
		case 6: WritePatents(); break;
		case 7: WriteNewspapers(); break;
		case 8: WriteCollections(); break;
		case 9: WriteStandards(); break;
		case 0: SaveAndClose(); break;
		}

		if (close_flag == 1)
		{
			break;
		}
	}
	
	return 0;
}