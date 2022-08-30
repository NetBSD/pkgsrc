# $NetBSD: Makefile,v 1.17 2022/08/30 18:36:36 wiz Exp $

DISTNAME=		xauth-1.1.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X authentication utility

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

X11_BIN_NAME=	xauth
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
