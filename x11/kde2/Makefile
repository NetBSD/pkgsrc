# $NetBSD: Makefile,v 1.10 2002/09/20 12:30:04 jlam Exp $

DISTNAME=	kde-2.2.2
PKGREVISION=	2
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdeartwork-2.2.2:../../misc/kdeartwork2
DEPENDS+=	kdeaddons-2.2.2:../../misc/kdeaddons2
DEPENDS+=	kdeadmin-2.2.2nb1:../../misc/kdeadmin2
DEPENDS+=	kdegames-2.2.2nb1:../../games/kdegames2
DEPENDS+=	kdegraphics-2.2.2nb1:../../graphics/kdegraphics2
DEPENDS+=	kdemultimedia-2.2.2nb1:../../audio/kdemultimedia2
DEPENDS+=	kdenetwork-2.2.2nb2:../../net/kdenetwork2
DEPENDS+=	kdepim-2.2.2nb2:../../misc/kdepim2
DEPENDS+=	kdetoys-2.2.2nb1:../../games/kdetoys2
DEPENDS+=	kdeutils-2.2.2nb1:../../misc/kdeutils2

EXTRACT_ONLY=	# empty
USE_X11BASE=	yes
USE_BUILDLINK2=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
