
// MFCApplication2Dlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CMFCApplication2Dlg



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, M_RESULT(_T(""))
	, M_Binario(FALSE)
	, M_Hexadecimal(FALSE)
	, M_Decimal(FALSE)
	//, Decimal(FALSE)
	, M_RESULT_ENTERO(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULT_EDIT1, M_RESULT);
	DDX_Check(pDX, IDC_Ob_CHECK, M_Binario);
	DDX_Check(pDX, IDC_Ox_CHECK, M_Hexadecimal);
	//DDX_Check(pDX, IDC_10_CHECK1, M_Decimal);
	//DDX_Check(pDX, IDC_10_CHECK, Decimal);
	DDX_Text(pDX, IDC_RESULT_STATIC, M_RESULT_ENTERO);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0_BUTTON, &CMFCApplication2Dlg::OnBnClicked0Button)
	ON_BN_CLICKED(IDC_1_BUTTON, &CMFCApplication2Dlg::OnBnClicked1Button)
	ON_BN_CLICKED(IDC_2_BUTTON, &CMFCApplication2Dlg::OnBnClicked2Button)
	ON_BN_CLICKED(IDC_3_BUTTON, &CMFCApplication2Dlg::OnBnClicked3Button)
	ON_BN_CLICKED(IDC_4_BUTTON, &CMFCApplication2Dlg::OnBnClicked4Button)
	ON_BN_CLICKED(IDC_5_BUTTON, &CMFCApplication2Dlg::OnBnClicked5Button)
	ON_BN_CLICKED(IDC_6_BUTTON, &CMFCApplication2Dlg::OnBnClicked6Button)
	ON_BN_CLICKED(IDC_7_BUTTON, &CMFCApplication2Dlg::OnBnClicked7Button)
	ON_BN_CLICKED(IDC_8_BUTTON, &CMFCApplication2Dlg::OnBnClicked8Button)
	ON_BN_CLICKED(IDC_9_BUTTON, &CMFCApplication2Dlg::OnBnClicked9Button)
	ON_BN_CLICKED(IDC_Ob_CHECK, &CMFCApplication2Dlg::OnBnClickedObCheck)
	ON_BN_CLICKED(IDC_Ox_CHECK, &CMFCApplication2Dlg::OnBnClickedOxCheck)
	ON_NOTIFY(BCN_DROPDOWN, IDC_Ob_CHECK, &CMFCApplication2Dlg::OnDropdownObCheck)
	ON_NOTIFY(BCN_DROPDOWN, IDC_Ox_CHECK, &CMFCApplication2Dlg::OnDropdownOxCheck)
	ON_BN_CLICKED(IDC_10_CHECK, &CMFCApplication2Dlg::OnClicked10Check)
	//ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2Dlg::OnBnClickedButton7)
	//ON_BN_CLICKED(IDC_10_CHECK1, &CMFCApplication2Dlg::OnBnClicked10Check1)
	ON_BN_CLICKED(IDC_SUMA_BUTTON, &CMFCApplication2Dlg::OnBnClickedSumaButton)
	ON_BN_CLICKED(IDC_POR_BUTTON, &CMFCApplication2Dlg::OnBnClickedPorButton)
	ON_BN_CLICKED(IDC_IGUAL_BUTTON, &CMFCApplication2Dlg::OnBnClickedIgualButton)
	ON_BN_CLICKED(IDC_Borrar_BUTTON, &CMFCApplication2Dlg::OnBnClickedBorrarButton)
	ON_BN_CLICKED(IDC_REST_BUTTON, &CMFCApplication2Dlg::OnBnClickedRestButton)
	ON_BN_CLICKED(IDC_DIVI_BUTTON, &CMFCApplication2Dlg::OnBnClickedDiviButton)
END_MESSAGE_MAP()


// Controladores de mensajes de CMFCApplication2Dlg

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int Conteo = 0 , Op1, Op2;

int Codigo_de_Operacion;
int Op1Add;
int Op2Add;
int ResultadoAdd;

void CMFCApplication2Dlg::OnBnClicked0Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (Conteo == 0) {
		M_RESULT = "0";
		M_RESULT_ENTERO = 0;
		Op1 = M_RESULT_ENTERO;

	}
	else {
		Op2 = M_RESULT_ENTERO * 10;
		Op1 = Op2;
		M_RESULT_ENTERO = Op1;

		CString MyCadena;
		MyCadena.Format(L"%d", Op1);
		M_RESULT = MyCadena;
	}


	
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClicked1Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (Conteo == 0) {
		M_RESULT = "1";
		M_RESULT_ENTERO = 1;
		Op1 = M_RESULT_ENTERO;

	}
	else {
		Op2 = M_RESULT_ENTERO * 10;
		Op1 = Op2 + 1;
		M_RESULT_ENTERO = Op1;

		CString MyCadena;
		MyCadena.Format(L"%d", Op1);
		M_RESULT = MyCadena;
	}
	Conteo++;
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClicked2Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (Conteo == 0) {
		M_RESULT = "2";
		M_RESULT_ENTERO = 2;
		Op1 = M_RESULT_ENTERO;

	}
	else {
		Op2 = M_RESULT_ENTERO * 10;
		Op1 = Op2 + 2;
		M_RESULT_ENTERO = Op1;

		CString MyCadena;
		MyCadena.Format(L"%d", Op1);
		M_RESULT = MyCadena;
	}
	Conteo++;
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClicked3Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (Conteo == 0) {
		M_RESULT = "3";
		M_RESULT_ENTERO = 3;
		Op1 = M_RESULT_ENTERO;

	}
	else {
		Op2 = M_RESULT_ENTERO * 10;
		Op1 = Op2 + 3;
		M_RESULT_ENTERO = Op1;

		CString MyCadena;
		MyCadena.Format(L"%d", Op1);
		M_RESULT = MyCadena;
	}
	Conteo++;
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClicked4Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (Conteo == 0) {
		M_RESULT = "4";
		M_RESULT_ENTERO = 4;
		Op1 = M_RESULT_ENTERO;

	}
	else {
		Op2 = M_RESULT_ENTERO * 10;
		Op1 = Op2 + 4;
		M_RESULT_ENTERO = Op1;

		CString MyCadena;
		MyCadena.Format(L"%d", Op1);
		M_RESULT = MyCadena;
	}
	Conteo++;
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClicked5Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (Conteo == 0) {
		M_RESULT = "5";
		M_RESULT_ENTERO = 5;
		Op1 = M_RESULT_ENTERO;

	}
	else {
		Op2 = M_RESULT_ENTERO * 10;
		Op1 = Op2 + 5;
		M_RESULT_ENTERO = Op1;

		CString MyCadena;
		MyCadena.Format(L"%d", Op1);
		M_RESULT = MyCadena;
	}
	Conteo++;
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClicked6Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (Conteo == 0) {
		M_RESULT = "6";
		M_RESULT_ENTERO = 6;
		Op1 = M_RESULT_ENTERO;

	}
	else {
		Op2 = M_RESULT_ENTERO * 10;
		Op1 = Op2 + 6;
		M_RESULT_ENTERO = Op1;

		CString MyCadena;
		MyCadena.Format(L"%d", Op1);
		M_RESULT = MyCadena;
	}
	Conteo++;
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClicked7Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (Conteo == 0) {
		M_RESULT = "7";
		M_RESULT_ENTERO = 7;
		Op1 = M_RESULT_ENTERO;

	}
	else {
		Op2 = M_RESULT_ENTERO * 10;
		Op1 = Op2 + 7;
		M_RESULT_ENTERO = Op1;

		CString MyCadena;
		MyCadena.Format(L"%d", Op1);
		M_RESULT = MyCadena;
	}
	Conteo++;
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClicked8Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (Conteo == 0) {
		M_RESULT = "8";
		M_RESULT_ENTERO = 8;
		Op1 = M_RESULT_ENTERO;

	}
	else {
		Op2 = M_RESULT_ENTERO * 10;
		Op1 = Op2 + 8;
		M_RESULT_ENTERO = Op1;

		CString MyCadena;
		MyCadena.Format(L"%d", Op1);
		M_RESULT = MyCadena;
	}
	Conteo++;
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClicked9Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (Conteo == 0) {
		M_RESULT = "9";
		M_RESULT_ENTERO = 9;
		Op1 = M_RESULT_ENTERO;

	}
	else {
		Op2 = M_RESULT_ENTERO * 10;
		Op1 = Op2 + 9;
		M_RESULT_ENTERO = Op1;

		CString MyCadena;
		MyCadena.Format(L"%d", Op1);
		M_RESULT = MyCadena;
	}
	Conteo++;
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClickedObCheck()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (M_Binario == TRUE) {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(FALSE);
		M_Decimal = FALSE;
		M_Hexadecimal = FALSE;
	}
	else {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClickedOxCheck()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (M_Hexadecimal == TRUE) {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
		M_Binario = FALSE;
		M_Decimal = FALSE;
	}
	else {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnDropdownObCheck(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
	// TODO: Agregue aquí su código de controlador de notificación de control
	*pResult = 0;
}


void CMFCApplication2Dlg::OnDropdownOxCheck(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
	// TODO: Agregue aquí su código de controlador de notificación de control
	*pResult = 0;
}


void CMFCApplication2Dlg::OnClicked10Check()
{
	// TODO: Agregue aquí su código de controlador de notificación de control

	UpdateData(TRUE);
	if (M_Decimal == TRUE) {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
		M_Binario = FALSE;
		M_Hexadecimal = FALSE;
	}
	else {
		GetDlgItem(IDC_0_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_1_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_2_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_3_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_4_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_5_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_6_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_7_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_8_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_9_BUTTON)->EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}



void CMFCApplication2Dlg::OnBnClickedSumaButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	Codigo_de_Operacion = 1;

	Op1Add = Op1;
	Op2Add = Op2;
	ResultadoAdd = M_RESULT_ENTERO;

	Conteo = 0;
	Op1 = 0;
	Op2 = 0;
	M_RESULT_ENTERO =0;

	CString MyCadenita;
	MyCadenita.Format(L"%d +", ResultadoAdd);
	M_RESULT = MyCadenita;

	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClickedPorButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	Codigo_de_Operacion = 3;

	Op1Add = Op1;
	Op2Add = Op2;
	ResultadoAdd = M_RESULT_ENTERO;

	Conteo = 0;
	CString MyCadenita;
	MyCadenita.Format(L"%d *", ResultadoAdd);
	M_RESULT = MyCadenita;

	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClickedIgualButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	switch (Codigo_de_Operacion)
	{
	case 1:
		M_RESULT_ENTERO = ResultadoAdd + Op1;
		break;
	case 2:
		M_RESULT_ENTERO = ResultadoAdd - Op1;
		break;
	case 3:
		M_RESULT_ENTERO = ResultadoAdd * Op1;
		break;
	case 4:
		M_RESULT_ENTERO = ResultadoAdd / Op1;
		break;

	default:
		break;
	}
	CString MyCadenita;
	MyCadenita.Format(L"= %d", M_RESULT_ENTERO);
	M_RESULT = MyCadenita;

	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClickedBorrarButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	Conteo = 0;
	Op1 = 0;
	Op2 = 0;
	M_RESULT_ENTERO = 0;
	ResultadoAdd = 0;

	CString MyCadenita;
	MyCadenita.Format(L"= %d", M_RESULT_ENTERO);
	M_RESULT = MyCadenita;

	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClickedRestButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	Codigo_de_Operacion = 2;

	Op1Add = Op1;
	Op2Add = Op2;
	ResultadoAdd = M_RESULT_ENTERO;

	Conteo = 0;
	CString MyCadenita;
	MyCadenita.Format(L"%d -", ResultadoAdd);
	M_RESULT = MyCadenita;

	UpdateData(FALSE);
}


void CMFCApplication2Dlg::OnBnClickedDiviButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	Codigo_de_Operacion = 4;

	Op1Add = Op1;
	Op2Add = Op2;
	ResultadoAdd = M_RESULT_ENTERO;

	Conteo = 0;
	CString MyCadenita;
	MyCadenita.Format(L"%d /", ResultadoAdd);
	M_RESULT = MyCadenita;

	UpdateData(FALSE);
}
