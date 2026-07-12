# $NetBSD: Makefile,v 1.14 2026/07/12 20:04:53 wiz Exp $

DISTNAME=		xvinfo-1.1.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Query X-Video capabilities

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
