# $NetBSD: Makefile,v 1.3 2000/12/06 16:25:53 tron Exp $
#

DISTNAME=	qt2-2.2.2
PKGNAME=	qt2-2.2.2
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://www.trolltech.com/

DEPENDS+=	qt2-libs-2.2.2:../../x11/qt2-libs
DEPENDS+=	qt2-docs-2.2.2:../../x11/qt2-docs
DEPENDS+=	qt2-designer-2.2.2:../../x11/qt2-designer

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
