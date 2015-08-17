# $NetBSD: Makefile,v 1.10 2015/08/17 17:11:31 wiz Exp $
#

DISTNAME=		xrestop-0.4
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://labs.o-hand.com/sources/xrestop/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/wiki/Software/xrestop
COMMENT=		X11 clients' server-side resource usage monitor

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
