# $NetBSD: Makefile,v 1.10 2003/11/10 15:55:32 gavan Exp $
#

DISTNAME=	qvwm-1.1.12
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	ftp://www.qvwm.org/pub/qvwm/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.qvwm.org/
COMMENT=	Windows 95/98/NT like window manager for X11

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BUILDLINK2=	yes
USE_GCC_SHLIB=	yes

post-install:
	${MV} ${PREFIX}/man/man1/qvwm.1x ${PREFIX}/man/man1/qvwm.1

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
