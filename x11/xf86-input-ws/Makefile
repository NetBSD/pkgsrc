# $NetBSD: Makefile,v 1.9 2022/08/08 13:53:57 nia Exp $

DISTNAME=	xf86-input-ws-1.3.0.20220511
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xenocara.org/
COMMENT=	OpenBSD's wscons input driver for modular X.org

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

RELRO_SUPPORTED=	partial

X11_DRV_NAME=	ws
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
