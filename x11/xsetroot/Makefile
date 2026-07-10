# $NetBSD: Makefile,v 1.13 2026/07/10 17:54:47 wiz Exp $

DISTNAME=		xsetroot-1.1.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X root window parameter setting program

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
