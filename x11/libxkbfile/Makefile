# $NetBSD: Makefile,v 1.15 2024/02/09 21:13:53 wiz Exp $

DISTNAME=		libxkbfile-1.1.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		The xkbfile Library from modular X.org

USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=		output/xkbfile.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../devel/meson/build.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
