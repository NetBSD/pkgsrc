# $NetBSD: Makefile,v 1.5 2001/01/13 12:41:38 skrll Exp $
#

DISTNAME=	qt2-${QTVERSION}
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

.include "Makefile.common"

DEPENDS+=	qt2-libs-${QTVERSION}:../../x11/qt2-libs
DEPENDS+=	qt2-docs-${QTVERSION}:../../x11/qt2-docs
DEPENDS+=	qt2-examples-${QTVERSION}:../../x11/qt2-examples
DEPENDS+=	qt2-designer-${QTVERSION}:../../x11/qt2-designer

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
