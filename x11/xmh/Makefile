# $NetBSD: Makefile,v 1.8 2024/03/07 17:40:22 wiz Exp $

DISTNAME=	xmh-1.0.5
CATEGORIES=	x11 mail
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Provides a GUI to the MH Message Handling System
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	appdefaultdir=${PREFIX}/lib/X11/app-defaults

BUILDLINK_API_DEPENDS.xbitmaps+=	xbitmaps>=1.1.0
.include "../../x11/xbitmaps/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXt+=	libXt>=1.3
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
