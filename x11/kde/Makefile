# $NetBSD: Makefile,v 1.32 2003/07/17 22:56:33 grant Exp $
#

DISTNAME=	kde-1.1.2
PKGREVISION=	2
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdeutils-1.1.2nb1:../../misc/kdeutils
DEPENDS+=	kdenetwork-1.1.2nb2:../../net/kdenetwork
DEPENDS+=	kdegraphics-1.1.2nb1:../../graphics/kdegraphics
DEPENDS+=	kdegames-1.1.2nb1:../../games/kdegames
DEPENDS+=	kdemultimedia-1.1.2nb1:../../audio/kdemultimedia
DEPENDS+=	kdetoys-1.1.2nb1:../../games/kdetoys
DEPENDS+=	korganizer-1.1.2nb1:../../time/korganizer

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
