# $NetBSD: Makefile,v 1.35 2007/10/25 22:01:09 jlam Exp $

DISTNAME=	qt3-${QTVERSION}
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	"meta-package" for the QT GUI C++ toolkit

.include "./Makefile.common"

DEPENDS+=	qt3-libs-${QTVERSION}{,nb[0-9]*}:../../x11/qt3-libs
DEPENDS+=	qt3-tools-${QTVERSION}{,nb[0-9]*}:../../x11/qt3-tools
DEPENDS+=	qt3-docs-${QTVERSION}{,nb[0-9]*}:../../x11/qt3-docs

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
