# $NetBSD: Makefile,v 1.1 2013/05/31 00:28:47 rodent Exp $

DISTNAME=	libWindowsWM-1.0.1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Cygwin/X rootless window management extension
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++ fortran
USE_TOOLS+=	gsed pkg-config

PKGCONFIG_OVERRIDE+=	windowswm.pc.in

.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../wm/windowswmproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
