# $NetBSD: Makefile,v 1.23 2003/05/22 12:05:48 markd Exp $

DISTNAME=	kde-3.1.2
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdeartwork-3.1.2:../../misc/kdeartwork3
DEPENDS+=	kdeaddons-3.1.2:../../misc/kdeaddons3
DEPENDS+=	kdeadmin-3.1.2:../../misc/kdeadmin3
DEPENDS+=	kdeedu-3.1.2:../../misc/kdeedu3
DEPENDS+=	kdegames-3.1.2:../../games/kdegames3
DEPENDS+=	kdegraphics-3.1.2:../../graphics/kdegraphics3
DEPENDS+=	kdemultimedia-3.1.2:../../audio/kdemultimedia3
DEPENDS+=	kdenetwork-3.1.2:../../net/kdenetwork3
DEPENDS+=	kdepim-3.1.2:../../misc/kdepim3
DEPENDS+=	kdetoys-3.1.2:../../games/kdetoys3
DEPENDS+=	kdeutils-3.1.2:../../misc/kdeutils3
DEPENDS+=	quanta-3.1.2:../../www/quanta3

EXTRACT_ONLY=	# empty
USE_BUILDLINK2=	yes
USE_X11BASE=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
