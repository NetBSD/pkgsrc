# $NetBSD: Makefile,v 1.5 2001/12/03 15:37:16 skrll Exp $

DISTNAME=	kde-2.2.2
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdeadmin-2.2.2:../../misc/kdeadmin2
DEPENDS+=	kdegames-2.2.2:../../games/kdegames2
DEPENDS+=	kdegraphics-2.2.2:../../graphics/kdegraphics2
DEPENDS+=	kdemultimedia-2.2.2:../../audio/kdemultimedia2
DEPENDS+=	kdenetwork-2.2.2:../../net/kdenetwork2
DEPENDS+=	kdepim-2.2.2:../../misc/kdepim2
DEPENDS+=	kdetoys-2.2.2:../../games/kdetoys2
DEPENDS+=	kdeutils-2.2.2:../../misc/kdeutils2

EXTRACT_ONLY=	# empty
USE_X11BASE=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
