
// MFCApplication2.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'pch.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CMFCApplication2App:
// Consulte MFCApplication2.cpp para obtener información sobre la implementación de esta clase
//

class CMFCApplication2App : public CWinApp
{
public:
	CMFCApplication2App();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication2App theApp;
