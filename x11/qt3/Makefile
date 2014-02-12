# $NetBSD: Makefile,v 1.40 2014/02/12 23:18:54 tron Exp $

DISTNAME=	qt3-${QTVERSION}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	"meta-package" for the QT GUI C++ toolkit

META_PACKAGE=	yes

.include "./Makefile.common"

DEPENDS+=	qt3-libs-${QTVERSION}{,nb[0-9]*}:../../x11/qt3-libs
DEPENDS+=	qt3-tools-${QTVERSION}{,nb[0-9]*}:../../x11/qt3-tools
DEPENDS+=	qt3-docs-${QTVERSION}{,nb[0-9]*}:../../x11/qt3-docs

.include "../../mk/bsd.pkg.mk"
