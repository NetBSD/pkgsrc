# $NetBSD: Makefile,v 1.11 1998/05/01 20:24:08 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/27 00:47:46 se Exp
#

DISTNAME=	kde-4.1b
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@netbsd.org

DEPENDS+=	kdeutils-4.1b:../../misc/kdeutils
DEPENDS+=	kdegames-4.1b:../../games/kdegames
DEPENDS+=	kdenetwork-4.1b:../../net/kdenetwork
DEPENDS+=	kdegraphics-4.1b:../../graphics/kdegraphics

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
