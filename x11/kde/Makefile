# $NetBSD: Makefile,v 1.9 1998/04/24 09:20:38 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/27 00:47:46 se Exp
#

DISTNAME=	kde-3.1b
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org

DEPENDS+=	kdelibs-3.1b:../../x11/kdelibs
RUN_DEPENDS=	kwm:../../x11/kdebase \
		kcalc:../../misc/kdeutils \
		kmahjongg:../../games/kdegames \
		kmail:../../net/kdenetwork

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
