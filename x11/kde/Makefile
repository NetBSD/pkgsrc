# $NetBSD: Makefile,v 1.17 1999/02/18 23:40:25 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/27 00:47:46 se Exp
#

DISTNAME=	kde-1.1
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	kdeutils-1.1:../../misc/kdeutils
DEPENDS+=	kdenetwork-1.1:../../net/kdenetwork
DEPENDS+=	kdegraphics-1.1:../../graphics/kdegraphics
#DEPENDS+=	kdegames-1.1:../../games/kdegames

CONFLICTS=	kde-*

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
