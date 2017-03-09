
// File1View.h : CFile1View 类的接口
//

#pragma once


class CFile1View : public CView
{
protected: // 仅从序列化创建
	CFile1View();
	DECLARE_DYNCREATE(CFile1View)

// 特性
public:
	CFile1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CFile1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileWrite();
	afx_msg void OnFileRead();
};

#ifndef _DEBUG  // File1View.cpp 中的调试版本
inline CFile1Doc* CFile1View::GetDocument() const
   { return reinterpret_cast<CFile1Doc*>(m_pDocument); }
#endif

