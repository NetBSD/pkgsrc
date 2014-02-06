# $NetBSD: Makefile,v 1.36 2014/02/06 17:28:24 drochner Exp $
#

DISTNAME=	QScintilla-gpl-2.8
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

MAKE_FLAGS+=		TARGET=Qsci.la TARGETD=Qsci.la TARGETL=Qsci.la
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} configure.py \
	    --qmake=${QTDIR}/bin/qmake --sip=${PREFIX}/bin/sip${PYVERSSUFFIX} \
	    --pyqt-sipdir=${PREFIX}/share/sip${PYVERSSUFFIX} \
	    --qsci-sipdir=${PREFIX}/share/sip${PYVERSSUFFIX}

post-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/Qsci.la \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/PyQt4/

.include "../../lang/python/extension.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
