# $NetBSD: Makefile,v 1.14 2003/12/18 09:52:01 wiz Exp $
#

DISTNAME=	qt2-${QTVERSION}
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	"meta-package" for the QT GUI C++ toolkit

.include "Makefile.common"

DEPENDS+=	qt2-libs-${QTVERSION}nb5:../../x11/qt2-libs
DEPENDS+=	{qt2-designer-${QTVERSION}nb2,qt2-designer-kde-${QTVERSION}nb2}:../../x11/qt2-designer
DEPENDS+=	qt2-docs-${QTVERSION}nb2:../../x11/qt2-docs
DEPENDS+=	qt2-examples-${QTVERSION}nb2:../../x11/qt2-examples

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
