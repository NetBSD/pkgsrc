# $NetBSD: Makefile,v 1.15 2024/05/06 08:40:33 jperkin Exp $

DISTNAME=	xrestop-0.6
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://xorg.freedesktop.org/archive/individual/app/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/xrestop
COMMENT=	X11 clients' server-side resource usage monitor

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
