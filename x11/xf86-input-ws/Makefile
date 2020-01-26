# $NetBSD: Makefile,v 1.4 2020/01/26 17:32:27 rillig Exp $

DISTNAME=	xf86-input-ws-1.3.0.20151010
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xenocara.org/
COMMENT=	OpenBSD's wscons input driver for modular X.org

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
