# $NetBSD: Makefile,v 1.3 2017/09/16 19:27:26 wiz Exp $
#

DISTNAME=	libXprintAppUtil-1.0.1
PKGREVISION=	1
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Xprint application utility routines
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gsed pkg-config

PKGCONFIG_OVERRIDE+=	xprintapputil.pc.in

.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/printproto/buildlink3.mk"
.include "../../x11/libXprintUtil/buildlink3.mk"
BUILD_DEPENDS+=	xp-[0-9]*:../../x11/xp
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
