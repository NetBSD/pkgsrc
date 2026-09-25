# $NetBSD: Makefile,v 1.18 2026/09/25 13:45:22 wiz Exp $

DISTNAME=		xrdb-1.2.3
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X server resource database utility

USE_TOOLS+=		pkg-config

MESON_ARGS+=		-Dcpp=${CPPPATH}

.include "../../devel/meson/build.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
