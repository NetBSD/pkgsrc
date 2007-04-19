# $NetBSD: Makefile,v 1.18 2007/04/19 21:39:17 wiz Exp $
#

DISTNAME=	libxklavier-3.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gswitchit/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://freedesktop.org/Software/LibXklavier
COMMENT=	High-level API for the X Keyboard Extension (XKB)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	libxklavier.pc.in

CONFIGURE_ARGS+=	--enable-xkb-support
CONFIGURE_ARGS+=	--enable-xmm-support

BUILDLINK_TRANSFORM+=	rm:-Werror

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
