# $NetBSD: Makefile,v 1.30 2013/05/09 14:05:20 joerg Exp $
#

DISTNAME=	QScintilla-gpl-2.7.1
PKGNAME=	${PYPKGPREFIX}-qt4-${DISTNAME:tl:S/-gpl-/-/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyqt/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://www.riverbankcomputing.co.uk/software/qscintilla/intro
COMMENT=	QScintilla -- Python bindings --
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}/Python

USE_LIBTOOL=		yes
USE_LANGUAGES=		c++

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} configure.py \
	    --qmake=${QTDIR}/bin/qmake --sip=${PREFIX}/bin/sip${PYVERSSUFFIX} \
	    --pyqt-sipdir=${PREFIX}/share/sip${PYVERSSUFFIX}


.include "../../lang/python/extension.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
