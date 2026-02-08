# $NetBSD: Makefile,v 1.19 2026/02/08 07:46:27 wiz Exp $

DISTNAME=		libxkbfile-1.2.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		The xkbfile Library from modular X.org

USE_TOOLS+=		pkg-config

FORCE_C_STD=		gnu99

PKGCONFIG_OVERRIDE+=		output/xkbfile.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/meson/build.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
