# $NetBSD: Makefile,v 1.3 2001/06/07 02:01:12 hubertf Exp $
#

DISTNAME=	blackbox-0.61.1
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://portal.alug.org/pub/blackbox/0.6x.x/

MAINTAINER=	carneous@carneous.net
HOMEPAGE=	http://blackbox.alug.org/
COMMENT=	small and fast X11R6 window manager

USE_X11BASE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--prefix=${X11PREFIX} \
			--x-includes=${X11BASE}/include \
			--x-libraries=${X11BASE}/lib \
			--enable-kde

HAS_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
