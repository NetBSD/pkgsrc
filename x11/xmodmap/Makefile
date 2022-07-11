# $NetBSD: Makefile,v 1.11 2022/07/11 19:39:07 wiz Exp $

DISTNAME=		xmodmap-1.0.11
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X modmap program

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
