# $NetBSD: Makefile,v 1.2 2001/09/07 14:27:13 drochner Exp $
#

DISTNAME=	kde-2.1
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdeutils>=2.1:../../misc/kdeutils2
DEPENDS+=	kdenetwork>=2.1:../../net/kdenetwork2
DEPENDS+=	kdegraphics>=2.1:../../graphics/kdegraphics2
DEPENDS+=	kdegames>=2.1:../../games/kdegames2
DEPENDS+=	kdemultimedia>=2.1:../../audio/kdemultimedia2
DEPENDS+=	kdetoys>=2.1:../../games/kdetoys2
DEPENDS+=	kdepim>=2.1:../../misc/kdepim2
DEPENDS+=	kdeadmin>=2.1:../../misc/kdeadmin2

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
