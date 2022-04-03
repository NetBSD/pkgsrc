# $NetBSD: Makefile,v 1.11 2022/04/03 18:39:42 wiz Exp $

DISTNAME=		editres-1.0.8
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Dynamic resource editor for libXt applications

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXaw/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXt+=	libXt>=1.0.99.1
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
