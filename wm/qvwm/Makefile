# $NetBSD: Makefile,v 1.8 2003/07/13 13:53:43 wiz Exp $
#

DISTNAME=	qvwm-1.1.12
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	ftp://www.qvwm.org/pub/qvwm/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.qvwm.org/
COMMENT=	Windows 95/98/NT like window manager for X11

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BUILDLINK2=	yes

post-install:
	${MV} ${PREFIX}/man/man1/qvwm.1x ${PREFIX}/man/man1/qvwm.1

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
