# $NetBSD: Makefile,v 1.5 2001/08/29 22:41:22 jlam Exp $
#

DISTNAME=	blackbox-0.61.1
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://portal.alug.org/pub/blackbox/0.6x.x/

MAINTAINER=	carneous@carneous.net
HOMEPAGE=	http://blackbox.alug.org/
COMMENT=	small and fast X11R6 window manager

USE_BUILDLINK_ONLY=	yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-kde

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
