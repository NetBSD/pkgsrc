# $NetBSD: Makefile,v 1.27 2025/12/03 07:38:29 wiz Exp $

DISTNAME=		xkbcomp-1.5.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		XKBD keymap compiler

USE_TOOLS+=		bison pkg-config

PKGCONFIG_OVERRIDE=	xkbcomp.pc.in

# XXX: still needed?
.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=		-Wno-error=string-compare
.endif

.include "../../devel/meson/build.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
