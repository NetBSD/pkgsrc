# $NetBSD: Makefile,v 1.15 2004/10/07 16:34:37 tv Exp $
#

DISTNAME=	qt2-${QTVERSION}
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	"meta-package" for the QT GUI C++ toolkit

.include "Makefile.common"

DEPENDS+=	qt2-libs-${QTVERSION}nb{,nb[0-9]*}:../../x11/qt2-libs
DEPENDS+=	qt2-designer{,-kde}-${QTVERSION}{,nb[0-9]*}:../../x11/qt2-designer
DEPENDS+=	qt2-docs-${QTVERSION}{,nb[0-9]*}:../../x11/qt2-docs
DEPENDS+=	qt2-examples-${QTVERSION}{,nb[0-9]*}:../../x11/qt2-examples

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
