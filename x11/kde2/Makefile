# $NetBSD: Makefile,v 1.24 2004/04/26 04:27:55 snj Exp $

DISTNAME=	kde-2.2.2
PKGREVISION=	9
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdeartwork-2.2.2nb5:../../misc/kdeartwork2
DEPENDS+=	kdeaddons-2.2.2nb5:../../misc/kdeaddons2
DEPENDS+=	kdeadmin-2.2.2nb7:../../misc/kdeadmin2
DEPENDS+=	kdegames-2.2.2nb6:../../games/kdegames2
DEPENDS+=	kdegraphics-2.2.2nb7:../../graphics/kdegraphics2
DEPENDS+=	kdemultimedia-2.2.2nb6:../../multimedia/kdemultimedia2
DEPENDS+=	kdenetwork-2.2.2nb9:../../net/kdenetwork2
DEPENDS+=	kdepim-2.2.2nb7:../../misc/kdepim2
DEPENDS+=	kdetoys-2.2.2nb6:../../games/kdetoys2
DEPENDS+=	kdeutils-2.2.2nb6:../../misc/kdeutils2

EXTRACT_ONLY=	# empty
USE_X11BASE=	yes
NO_BUILDLINK=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
