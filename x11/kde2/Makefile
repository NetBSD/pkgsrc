# $NetBSD: Makefile,v 1.25 2004/10/28 11:49:07 wiz Exp $

DISTNAME=	kde-2.2.2
PKGREVISION=	10
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdeartwork-2.2.2nb6:../../misc/kdeartwork2
DEPENDS+=	kdeaddons-2.2.2nb6:../../misc/kdeaddons2
DEPENDS+=	kdeadmin-2.2.2nb8:../../misc/kdeadmin2
DEPENDS+=	kdegames-2.2.2nb7:../../games/kdegames2
DEPENDS+=	kdegraphics-2.2.2nb8:../../graphics/kdegraphics2
DEPENDS+=	kdemultimedia-2.2.2nb7:../../multimedia/kdemultimedia2
DEPENDS+=	kdenetwork-2.2.2nb10:../../net/kdenetwork2
DEPENDS+=	kdepim-2.2.2nb8:../../misc/kdepim2
DEPENDS+=	kdetoys-2.2.2nb7:../../games/kdetoys2
DEPENDS+=	kdeutils-2.2.2nb7:../../misc/kdeutils2

EXTRACT_ONLY=	# empty
USE_X11BASE=	yes
NO_BUILDLINK=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
