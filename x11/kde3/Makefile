# $NetBSD: Makefile,v 1.7 2002/09/11 09:16:18 wiz Exp $

DISTNAME=	kde-3.0.3
PKGREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdeartwork-3.0.3:../../misc/kdeartwork3
DEPENDS+=	kdeaddons-3.0.3:../../misc/kdeaddons3
DEPENDS+=	kdeadmin-3.0.3:../../misc/kdeadmin3
DEPENDS+=	kdeedu-3.0.3:../../misc/kdeedu3
DEPENDS+=	kdegames-3.0.3:../../games/kdegames3
DEPENDS+=	kdegraphics-3.0.3:../../graphics/kdegraphics3
DEPENDS+=	kdemultimedia-3.0.3:../../audio/kdemultimedia3
DEPENDS+=	kdenetwork-3.0.3:../../net/kdenetwork3
DEPENDS+=	kdepim-3.0.3nb1:../../misc/kdepim3
DEPENDS+=	kdetoys-3.0.3:../../games/kdetoys3
DEPENDS+=	kdeutils-3.0.3:../../misc/kdeutils3

EXTRACT_ONLY=	# empty
USE_X11BASE=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
