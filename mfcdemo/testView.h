
// testView.h : CtestView 类的接口
//

#pragma once


class CtestView : public CView
{
protected: // 仅从序列化创建
	CtestView();
	DECLARE_DYNCREATE(CtestView)

// 特性
public:
	CtestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CtestView();
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
};

#ifndef _DEBUG  // testView.cpp 中的调试版本
inline CtestDoc* CtestView::GetDocument() const
   { return reinterpret_cast<CtestDoc*>(m_pDocument); }
#endif

