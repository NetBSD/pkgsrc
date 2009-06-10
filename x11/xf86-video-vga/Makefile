# $NetBSD: Makefile,v 1.6 2009/06/10 07:24:48 hasso Exp $
#

DISTNAME=	xf86-video-vga-4.1.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg generic VGA video driver

PKG_DESTDIR_SUPPORT=    user-destdir

USE_LIBTOOL=    yes
GNU_CONFIGURE=  yes
USE_TOOLS+=     autoconf autoheader automake autoreconf pkg-config

BUILD_DEPENDS+=	xorg-util-macros>=1.2.0:../../devel/xorg-util-macros

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
