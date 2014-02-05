# $NetBSD: Makefile,v 1.17 2014/02/05 09:44:18 obache Exp $

DISTNAME=	xrandr-1.4.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Primitive command line interface to RandR extension
LICENSE=	mit

DEPENDS+=	nickle-[0-9]*:../../math/nickle

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		nickle
SUBST_SED.nickle=	-e "s,.!/usr/bin/env nickle,${PREFIX}/bin/nickle,"
SUBST_FILES.nickle=	xkeystone
SUBST_STAGE.nickle=	post-build
SUBST_MESSAGE.nickle=	Fixing path to nickle.

BUILDLINK_API_DEPENDS.libXrandr+=	libXrandr>=1.4
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_API_DEPENDS.xproto+=	xproto>=7.0.17
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
