# $NetBSD: Makefile,v 1.15 2004/10/05 10:30:35 agc Exp $
#

DISTNAME=	matchbox-window-manager-0.8.4
PKGNAME=	matchbox-0.8.4
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://matchbox.handhelds.org/sources/matchbox-window-manager/0.8/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/
COMMENT=	Window manager designed for computers with small displays

USE_BUILDLINK3=	yes
USE_X11=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
