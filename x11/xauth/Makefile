# $NetBSD: Makefile,v 1.15 2022/04/10 08:53:17 nia Exp $

DISTNAME=		xauth-1.1.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X authentication utility

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
CPPFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

X11_BIN_NAME=	xauth
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
