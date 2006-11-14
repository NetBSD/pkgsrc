# $NetBSD: Makefile,v 1.1.1.1 2006/11/14 23:05:04 reed Exp $

DISTNAME=	xf86-video-wsfb-0.2.0
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/driver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@NetBSD.org
COMMENT=	Modular Xorg wsdisplay framebuffer video driver

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
