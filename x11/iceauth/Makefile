# $NetBSD: Makefile,v 1.16 2026/04/19 07:54:12 wiz Exp $

DISTNAME=		iceauth-1.0.11
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		ICE protocol utility

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
