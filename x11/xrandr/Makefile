# $NetBSD: Makefile,v 1.24 2019/11/14 10:30:43 wiz Exp $

DISTNAME=	xrandr-1.5.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

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

BUILDLINK_API_DEPENDS.libXrandr+=	libXrandr>=1.5.0
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
