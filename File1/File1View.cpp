
// File1View.cpp : CFile1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "File1.h"
#endif

#include "File1Doc.h"
#include "File1View.h" 
//#include <iostream>
//#include <fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFile1View

IMPLEMENT_DYNCREATE(CFile1View, CView)

BEGIN_MESSAGE_MAP(CFile1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFile1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_WRITE, &CFile1View::OnFileWrite)
	ON_COMMAND(ID_FILE_READ, &CFile1View::OnFileRead)
END_MESSAGE_MAP()

// CFile1View 构造/析构

CFile1View::CFile1View()
{
	// TODO: 在此处添加构造代码

}

CFile1View::~CFile1View()
{
}

BOOL CFile1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFile1View 绘制

void CFile1View::OnDraw(CDC* /*pDC*/)
{
	CFile1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CFile1View 打印


void CFile1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFile1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFile1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFile1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CFile1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFile1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFile1View 诊断

#ifdef _DEBUG
void CFile1View::AssertValid() const
{
	CView::AssertValid();
}

void CFile1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFile1Doc* CFile1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFile1Doc)));
	return (CFile1Doc*)m_pDocument;
}
#endif //_DEBUG


// CFile1View 消息处理程序


void CFile1View::OnFileWrite()
{
	// TODO: 在此添加命令处理程序代码
	// 缓冲文件系统，装满缓冲区之后才一起送到存盘区。因为缓冲区没满，所以没第一下就送到存盘区。
	//当我们关闭程序的时候，程序会将缓冲区的文件送入磁盘区。这样我们就能看到我们写入的数据了。
	/*FILE *pFile = fopen("1.txt", "w");
	fwrite(_T("aaaaaaaa"), 1, strlen("aaaaaaaa"), pFile);

	//C++写入文件时包含一个隐藏的文件指针。
	//fseek函数用来移动文件指针。
	//fseek(pFile, 0, SEEK_SET);//未成功，aaaa被覆盖掉了。
	fwrite(_T("C++真好玩"), 1, strlen("C++真好玩"), pFile);
	fclose(pFile);*/
	//fflush刷新数据缓冲区，将数据立即写入磁盘区。
	
	

	//fflush(pFile);

	/*FILE *pFile = fopen("2.txt", "w");
	char ch[3];
	ch[0] = 'a';
	ch[1] = 10;
	ch[2] = 'b';
	fwrite(ch, 1,3, pFile);
	fclose(pFile);*/

	/*FILE *pFile = fopen("3.txt", "w");
	int i = 98341;
	//数组长度为5的话数组越界。
	char ch[6]; 
	/*ch[0] = 9 + 48;
	ch[1] = 8 + 48;
	ch[2] = 3 + 48;
	ch[3] = 4 + 48;
	ch[4] = 1 + 48;*/
	/*_itoa(i, ch, 10);//将i内的内容以十进制的形式存放在ch数组中。
	//fwrite(&i, 4,1, pFile);
	fwrite(ch, 5, 1, pFile);
	fclose(pFile);*/

	ofstream ofs("4.txt");
	ofs.write("aaaaaaa", strlen("aaaaaaa"));
	ofs.close();

}


void CFile1View::OnFileRead()
{
	// TODO: 在此添加命令处理程序代码
	//FILE *pFile = fopen("1.txt", "r");
	/*char ch[100];
	//memset函数。第一个设置哪一个buffer，第二个设置为那个字符，第三个设置大小
	memset(ch, 0, 100);
	
	fread(ch, 1, 100, pFile);//每次读1， 循环读取100次。
	MessageBox(ch);*/

	//ftell函数用来获取文件的文件指针当前的位置。当文件指针移动到文件的结尾处，所以我们可以用它来得到文件的长度。
	/*char *pbuf;
	fseek(pFile, 0, SEEK_END);
	int len = ftell(pFile);
	pbuf = new char[len + 1];
	
	//rewind函数可以将文件指针重新放在文件开始处。
	rewind(pFile);
	
	fread(pbuf, 1, len, pFile);
	pbuf[len] = 0;//上面多设置一个字节以便此处将最后一个字符设置为0
	MessageBox(pbuf);
	fclose(pFile);*/


	//注意读取方式，如果我们以文本方式读的话，是三个字节是可以读取到ab的。
	//而以二进制方式读的话，我们需要读取四个字节才可以读取到ab。
	//文本方式写入和读取之间会有一个转换将13 10转换为10再将10转换为13 10
	//而二进制方式读写的话，数据在内存中的储存形式原样输出到文件中。
	FILE *pFile = fopen("2.txt", "rb");
	char ch[100];
	//在读取数据之后将下个数据设置为0.
	fread(ch, 1, 4, pFile);
	ch[4] = 0;
	MessageBox(ch);
	fclose(pFile);
}
