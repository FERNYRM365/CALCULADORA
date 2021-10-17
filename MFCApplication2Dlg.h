
// MFCApplication2Dlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CMFCApplication2Dlg
class CMFCApplication2Dlg : public CDialogEx
{
// Construcción
public:
	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString M_RESULT;
	afx_msg void OnBnClicked0Button();
	afx_msg void OnBnClicked1Button();
	afx_msg void OnBnClicked2Button();
	afx_msg void OnBnClicked3Button();
	afx_msg void OnBnClicked4Button();
	afx_msg void OnBnClicked5Button();
	afx_msg void OnBnClicked6Button();
	afx_msg void OnBnClicked7Button();
	afx_msg void OnBnClicked8Button();
	afx_msg void OnBnClicked9Button();
	afx_msg void OnBnClickedObCheck();
	afx_msg void OnBnClickedOxCheck();
	BOOL M_Binario;
	BOOL M_Hexadecimal;
	BOOL M_Decimal;
	afx_msg void OnDropdownObCheck(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDropdownOxCheck(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClicked10Check();
	afx_msg void OnBnClickedButton7();
	BOOL Decimal;
	afx_msg void OnBnClicked10Check1();
	int M_RESULT_ENTERO;
	afx_msg void OnBnClickedSumaButton();
	afx_msg void OnBnClickedPorButton();
	afx_msg void OnBnClickedIgualButton();
	afx_msg void OnBnClickedBorrarButton();
	afx_msg void OnBnClickedRestButton();
	afx_msg void OnBnClickedDiviButton();
};
