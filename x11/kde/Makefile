# $NetBSD: Makefile,v 1.25 2000/04/24 14:18:02 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/27 00:47:46 se Exp
#

DISTNAME=	kde-1.1.2
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	kdeutils-1.1.2:../../misc/kdeutils
DEPENDS+=	kdenetwork-1.1.2:../../net/kdenetwork
DEPENDS+=	kdegraphics-1.1.2:../../graphics/kdegraphics
DEPENDS+=	kdegames-1.1.2:../../games/kdegames
DEPENDS+=	kdemultimedia-1.1.2:../../audio/kdemultimedia
DEPENDS+=	kdetoys-1.1.2:../../games/kdetoys
DEPENDS+=	korganizer-1.1.2:../../x11/korganizer

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
