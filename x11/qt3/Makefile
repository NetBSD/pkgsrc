# $NetBSD: Makefile,v 1.22 2003/12/24 12:02:46 tron Exp $

DISTNAME=	qt3-${QTVERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	"meta-package" for the QT GUI C++ toolkit

.include "./Makefile.common"

DEPENDS+=	qt3-libs-${QTVERSION}:../../x11/qt3-libs
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
