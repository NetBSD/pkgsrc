# $NetBSD: Makefile,v 1.5 2009/12/15 12:24:02 wiz Exp $
#

DISTNAME=	xcb-proto-1.6
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB protocol descriptions (in XML)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	xcb-proto.pc.in

CONFIGURE_ENV+=		XMLLLINT=${BUILDLINK_PREFIX.libxml}/bin/xmllint

# XXX just for the "configure" check
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
BUILDLINK_DEPMETHOD.libxml2?=	build
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
