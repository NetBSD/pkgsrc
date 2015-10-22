# $NetBSD: Makefile,v 1.8 2015/10/22 14:34:45 tnn Exp $
#

DISTNAME=	liblbxutil-1.1.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Low Bandwith X extension (LBX) utility routines
LICENSE=	x11 # XXX and others

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gsed pkg-config

PKGCONFIG_OVERRIDE+=	lbxutil.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
BUILDLINK_API_DEPENDS.xextproto+=	xextproto>=7.0.99.1
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
