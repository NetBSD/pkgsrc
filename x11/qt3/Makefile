# $NetBSD: Makefile,v 1.26 2004/08/26 18:57:07 darcy Exp $

DISTNAME=	qt3-${QTVERSION}
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	"meta-package" for the QT GUI C++ toolkit

.include "./Makefile.common"

DEPENDS+=	qt3-libs-${QTVERSION}nb1:../../x11/qt3-libs
DEPENDS+=	qt3-tools-${QTVERSION}:../../x11/qt3-tools
DEPENDS+=	qt3-docs-${QTVERSION}:../../x11/qt3-docs

NO_BUILDLINK=	yes
USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
