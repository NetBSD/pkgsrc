# $NetBSD: Makefile,v 1.4 2001/06/30 09:24:56 zuntum Exp $
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

.include "../../mk/bsd.pkg.mk"
