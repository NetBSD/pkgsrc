# $NetBSD: Makefile,v 1.12 2004/01/24 15:18:32 grant Exp $
#

DISTNAME=	qvwm-1.1.12
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	ftp://www.qvwm.org/pub/qvwm/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.qvwm.org/
COMMENT=	Windows 95/98/NT like window manager for X11

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_BUILDLINK2=	yes
USE_GCC_SHLIB=	yes

post-install:
	${MV} ${PREFIX}/man/man1/qvwm.1x ${PREFIX}/man/man1/qvwm.1

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
