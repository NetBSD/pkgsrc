# $NetBSD: Makefile,v 1.9 2005/03/22 16:05:13 jmmv Exp $
#

DISTNAME=	libxklavier-2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gswitchit/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://pdx.freedesktop.org/Software/LibXklavier
COMMENT=	High-level API for the X Keyboard Extension (XKB)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

PKGCONFIG_OVERRIDE=	libxklavier.pc.in

CONFIGURE_ARGS+=	--enable-xkb-support
CONFIGURE_ARGS+=	--enable-xmm-support

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
