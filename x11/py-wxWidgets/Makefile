# $NetBSD: Makefile,v 1.71 2018/08/22 09:48:03 wiz Exp $

VERSION=	2.8.12.0
DISTNAME=	wxPython-src-${VERSION}
PKGNAME=	${PYPKGPREFIX}-wxWidgets-${VERSION}
PKGREVISION=	9
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wxpython.org/
COMMENT=	Python bindings for wxWidgets

WRKSRC=		${WRKDIR}/wxPython-src-${VERSION}/wxPython
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

# previous name of the package
CONFLICTS+=		${PYPKGPREFIX}-wxWindows-[0-9]*
PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 2.8.10.1

# no scripts to avoid conflicts
#PYSETUPBUILDARGS+=	NO_SCRIPTS=1
#PYSETUPINSTALLARGS+=	NO_SCRIPTS=1

PYSETUPBUILDARGS+=	WXPORT=gtk2 UNICODE=1
PYSETUPINSTALLARGS+=	WXPORT=gtk2 UNICODE=1

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing dynamic python
SUBST_FILES.fix-python+=	wx/lib/floatcanvas/*.py
SUBST_FILES.fix-python+=	wx/lib/floatcanvas/Utilities/*.py
SUBST_FILES.fix-python+=	wx/tools/Editra/*.py
SUBST_FILES.fix-python+=	wx/tools/Editra/src/*.py
SUBST_FILES.fix-python+=	wx/tools/Editra/src/extern/*.py
SUBST_FILES.fix-python+=	wx/tools/Editra/tests/syntax/python.python
SUBST_FILES.fix-python+=	wx/tools/Editra/Editra*
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'

CHECK_INTERPRETER_SKIP+=	wx/tools/Editra/tests/syntax/d.d
CHECK_INTERPRETER_SKIP+=	wx/tools/Editra/tests/syntax/octave.oct
CHECK_INTERPRETER_SKIP+=	wx/tools/Editra/tests/syntax/ruby.rb
CHECK_INTERPRETER_SKIP+=	wx/tools/Editra/tests/syntax/tcl_tk.tcl
CHECK_INTERPRETER_SKIP+=	wx/tools/Editra/tests/syntax/perl.pl

EGG_NAME=	${DISTNAME:S/-src-/_common-/}
EGG_NAME2=	${DISTNAME:S/-src-/-/}
PLIST_SUBST+=	EGG_FILE2=${EGG_NAME2}-py${PYVERSSUFFIX}.egg-info

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/wxGTK28-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
