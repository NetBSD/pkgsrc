# $NetBSD: Makefile,v 1.14 1998/08/20 15:17:34 tsarna Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/27 00:47:46 se Exp
#

DISTNAME=	kde-1.0
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	kdeutils-1.0:../../misc/kdeutils
DEPENDS+=	kdegames-1.0:../../games/kdegames
DEPENDS+=	kdenetwork-1.0:../../net/kdenetwork
DEPENDS+=	kdegraphics-1.0:../../graphics/kdegraphics

CONFLICTS=	kde-2.1b kde-3.1b kde-4.1b

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
