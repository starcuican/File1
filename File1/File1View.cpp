
// File1View.cpp : CFile1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFile1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_WRITE, &CFile1View::OnFileWrite)
	ON_COMMAND(ID_FILE_READ, &CFile1View::OnFileRead)
END_MESSAGE_MAP()

// CFile1View ����/����

CFile1View::CFile1View()
{
	// TODO: �ڴ˴���ӹ������

}

CFile1View::~CFile1View()
{
}

BOOL CFile1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFile1View ����

void CFile1View::OnDraw(CDC* /*pDC*/)
{
	CFile1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CFile1View ��ӡ


void CFile1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFile1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFile1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFile1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CFile1View ���

#ifdef _DEBUG
void CFile1View::AssertValid() const
{
	CView::AssertValid();
}

void CFile1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFile1Doc* CFile1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFile1Doc)));
	return (CFile1Doc*)m_pDocument;
}
#endif //_DEBUG


// CFile1View ��Ϣ�������


void CFile1View::OnFileWrite()
{
	// TODO: �ڴ���������������
	// �����ļ�ϵͳ��װ��������֮���һ���͵�����������Ϊ������û��������û��һ�¾��͵���������
	//�����ǹرճ����ʱ�򣬳���Ὣ���������ļ�������������������Ǿ��ܿ�������д��������ˡ�
	/*FILE *pFile = fopen("1.txt", "w");
	fwrite(_T("aaaaaaaa"), 1, strlen("aaaaaaaa"), pFile);

	//C++д���ļ�ʱ����һ�����ص��ļ�ָ�롣
	//fseek���������ƶ��ļ�ָ�롣
	//fseek(pFile, 0, SEEK_SET);//δ�ɹ���aaaa�����ǵ��ˡ�
	fwrite(_T("C++�����"), 1, strlen("C++�����"), pFile);
	fclose(pFile);*/
	//fflushˢ�����ݻ�����������������д���������
	
	

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
	//���鳤��Ϊ5�Ļ�����Խ�硣
	char ch[6]; 
	/*ch[0] = 9 + 48;
	ch[1] = 8 + 48;
	ch[2] = 3 + 48;
	ch[3] = 4 + 48;
	ch[4] = 1 + 48;*/
	/*_itoa(i, ch, 10);//��i�ڵ�������ʮ���Ƶ���ʽ�����ch�����С�
	//fwrite(&i, 4,1, pFile);
	fwrite(ch, 5, 1, pFile);
	fclose(pFile);*/

	ofstream ofs("4.txt");
	ofs.write("aaaaaaa", strlen("aaaaaaa"));
	ofs.close();

}


void CFile1View::OnFileRead()
{
	// TODO: �ڴ���������������
	//FILE *pFile = fopen("1.txt", "r");
	/*char ch[100];
	//memset��������һ��������һ��buffer���ڶ�������Ϊ�Ǹ��ַ������������ô�С
	memset(ch, 0, 100);
	
	fread(ch, 1, 100, pFile);//ÿ�ζ�1�� ѭ����ȡ100�Ρ�
	MessageBox(ch);*/

	//ftell����������ȡ�ļ����ļ�ָ�뵱ǰ��λ�á����ļ�ָ���ƶ����ļ��Ľ�β�����������ǿ����������õ��ļ��ĳ��ȡ�
	/*char *pbuf;
	fseek(pFile, 0, SEEK_END);
	int len = ftell(pFile);
	pbuf = new char[len + 1];
	
	//rewind�������Խ��ļ�ָ�����·����ļ���ʼ����
	rewind(pFile);
	
	fread(pbuf, 1, len, pFile);
	pbuf[len] = 0;//���������һ���ֽ��Ա�˴������һ���ַ�����Ϊ0
	MessageBox(pbuf);
	fclose(pFile);*/


	//ע���ȡ��ʽ������������ı���ʽ���Ļ����������ֽ��ǿ��Զ�ȡ��ab�ġ�
	//���Զ����Ʒ�ʽ���Ļ���������Ҫ��ȡ�ĸ��ֽڲſ��Զ�ȡ��ab��
	//�ı���ʽд��Ͷ�ȡ֮�����һ��ת����13 10ת��Ϊ10�ٽ�10ת��Ϊ13 10
	//�������Ʒ�ʽ��д�Ļ����������ڴ��еĴ�����ʽԭ��������ļ��С�
	FILE *pFile = fopen("2.txt", "rb");
	char ch[100];
	//�ڶ�ȡ����֮���¸���������Ϊ0.
	fread(ch, 1, 4, pFile);
	ch[4] = 0;
	MessageBox(ch);
	fclose(pFile);
}
