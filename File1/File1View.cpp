
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
	FILE *pFile = fopen("1.txt", "w");
	fwrite(_T("aaaaaaaa"), 1, strlen("aaaaaaaa"), pFile);
	//fseek(pFile, 0, SEEK_SET);//δ�ɹ���aaaa�����ǵ��ˡ�
	fwrite(_T("C++�����"), 1, strlen("C++�����")+1, pFile);
	fclose(pFile);
	//fflushˢ�����ݻ�����������������д���������
	
	//C++д���ļ��ǰ���һ�����ص��ļ�ָ�롣
	//fseek���������ƶ��ļ�ָ�롣

	//fflush(pFile);

}


void CFile1View::OnFileRead()
{
	// TODO: �ڴ���������������
	FILE *pFile = fopen("1.txt", "r");
	TCHAR ch[100];
	fread(ch, 1, 100, pFile);//ÿ�ζ�1�� ѭ����ȡ100�Ρ�
	MessageBox(ch);
	fclose(pFile);
}
