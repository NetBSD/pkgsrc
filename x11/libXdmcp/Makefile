# $NetBSD: Makefile,v 1.13 2022/04/10 08:53:15 nia Exp $

DISTNAME=		libXdmcp-1.1.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Display Manager Control Protocol library from X.org

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xdmcp.pc.in
GNU_CONFIGURE=		yes

X11_LIB_NAME?=		libXdmcp
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
