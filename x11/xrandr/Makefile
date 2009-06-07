# $NetBSD: Makefile,v 1.8 2009/06/07 18:34:54 wiz Exp $
#

DISTNAME=	xrandr-1.3.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Primitive command line interface to RandR extension

DEPENDS+=	nickle-[0-9]*:../../math/nickle

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		nickle
SUBST_SED.nickle=	-e "s,.!/usr/bin/env nickle,${PREFIX}/bin/nickle,"
SUBST_FILES.nickle=	xkeystone
SUBST_STAGE.nickle=	post-build
SUBST_MESSAGE.nickle=	Fixing path to nickle.

BUILDLINK_API_DEPENDS.libXrandr+=	libXrandr>=1.2
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
