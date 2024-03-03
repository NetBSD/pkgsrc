# $NetBSD: Makefile,v 1.19 2024/03/03 21:00:07 wiz Exp $

DISTNAME=		xauth-1.1.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X authentication utility

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

X11_BIN_NAME=	xauth
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
