# $NetBSD: Makefile,v 1.19 2003/08/01 15:31:07 drochner Exp $

DISTNAME=	qt3-${QTVERSION}
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	"meta-package" for the QT GUI C++ toolkit

.include "./Makefile.common"

DEPENDS+=	qt3-libs-${QTVERSION}nb2:../../x11/qt3-libs
DEPENDS+=	qt3-tools-${QTVERSION}nb3:../../x11/qt3-tools
DEPENDS+=	qt3-docs-${QTVERSION}nb1:../../x11/qt3-docs

USE_BUILDLINK2=	yes
USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
