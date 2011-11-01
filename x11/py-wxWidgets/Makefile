# $NetBSD: Makefile,v 1.33 2011/11/01 06:03:06 sbd Exp $
#

VERSION=	2.8.10.1
DISTNAME=	wxPython-src-${VERSION}
PKGNAME=	${PYPKGPREFIX}-wxWidgets-${VERSION}
PKGREVISION=	8
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wxpython.org/
COMMENT=	Python bindings for wxWidgets

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/wxPython-src-${VERSION}/wxPython
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

# previous name of the package
CONFLICTS+=	${PYPKGPREFIX}-wxWindows-[0-9]*

WXARG=	WXPORT=gtk2 UNICODE=1

PYDISTUTILSPKG=	yes
# no scripts to avoid conflicts
#PYSETUPBUILDARGS=	NO_SCRIPTS=1 ${WXARG}
#PYSETUPINSTALLARGS=	NO_SCRIPTS=1 ${WXARG}

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

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/wxGTK28-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
