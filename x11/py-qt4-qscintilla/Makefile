# $NetBSD: Makefile,v 1.22 2012/10/02 17:12:18 tron Exp $
#

DISTNAME=	QScintilla-gpl-2.6.2
PKGNAME=	${PYPKGPREFIX}-qt4-${DISTNAME:tl:S/-gpl-/-/}
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.riverbankcomputing.com/static/Downloads/QScintilla2/

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://www.riverbankcomputing.co.uk/software/qscintilla/intro
COMMENT=	QScintilla -- Python bindings --
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE+=	25

WRKSRC=		${WRKDIR}/${DISTNAME}/Python

USE_LIBTOOL=		yes
USE_LANGUAGES=		c++

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

do-configure:
		(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}  \
	  	${PYTHONBIN} configure.py)


.include "../../lang/python/extension.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
