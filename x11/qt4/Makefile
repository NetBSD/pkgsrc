# $NetBSD: Makefile,v 1.3 2008/01/04 15:54:46 rillig Exp $

DISTNAME=	qt4-${QTVERSION}
CATEGORIES=	x11
MASTER_SITES=	# none

COMMENT=	"meta-package" for the QT GUI C++ toolkit

.include "Makefile.common"

DEPENDS+=	qt4-libs-${QTVERSION}{,nb[0-9]*}:../../x11/qt4-libs
DEPENDS+=	qt4-tools-${QTVERSION}{,nb[0-9]*}:../../x11/qt4-tools
DEPENDS+=	qt4-docs-${QTVERSION}{,nb[0-9]*}:../../x11/qt4-docs

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
