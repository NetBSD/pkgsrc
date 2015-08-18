# $NetBSD: Makefile,v 1.11 2015/08/18 07:31:20 wiz Exp $
#

DISTNAME=		xrestop-0.4
PKGREVISION=		2
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
