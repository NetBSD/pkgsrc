# $NetBSD: Makefile,v 1.9 2024/03/03 10:04:01 wiz Exp $

DISTNAME=	libXaw3d-1.6.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	X 3D Athena Widget Set
#LICENSE=	x11 # AND others

CONFLICTS+=	Xaw-Xpm-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex pkg-config

PKGCONFIG_OVERRIDE+=	xaw3d.pc.in

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
