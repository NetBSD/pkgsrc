# $NetBSD: Makefile,v 1.23 2004/04/01 11:43:56 tron Exp $

DISTNAME=	qt3-${QTVERSION}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	"meta-package" for the QT GUI C++ toolkit

.include "./Makefile.common"

DEPENDS+=	qt3-libs-${QTVERSION}nb1:../../x11/qt3-libs
DEPENDS+=	qt3-tools-${QTVERSION}nb1:../../x11/qt3-tools
DEPENDS+=	qt3-docs-${QTVERSION}:../../x11/qt3-docs

USE_BUILDLINK2=	yes
USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
