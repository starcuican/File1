
// File1View.h : CFile1View ��Ľӿ�
//

#pragma once


class CFile1View : public CView
{
protected: // �������л�����
	CFile1View();
	DECLARE_DYNCREATE(CFile1View)

// ����
public:
	CFile1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CFile1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileWrite();
	afx_msg void OnFileRead();
};

#ifndef _DEBUG  // File1View.cpp �еĵ��԰汾
inline CFile1Doc* CFile1View::GetDocument() const
   { return reinterpret_cast<CFile1Doc*>(m_pDocument); }
#endif

