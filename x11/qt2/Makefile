# $NetBSD: Makefile,v 1.9 2001/11/16 09:11:38 jlam Exp $
#

DISTNAME=	qt2-${QTVERSION}nb2
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	"meta-package" for the QT GUI C++ toolkit

.include "Makefile.common"

DEPENDS+=	qt2-libs-${QTVERSION}nb1:../../x11/qt2-libs
DEPENDS+=	{qt2-designer-${QTVERSION}nb1,qt2-designer-kde-${QTVERSION}nb1}:../../x11/qt2-designer
DEPENDS+=	qt2-docs-${QTVERSION}:../../x11/qt2-docs
DEPENDS+=	qt2-examples-${QTVERSION}:../../x11/qt2-examples

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
