# $NetBSD: Makefile,v 1.35 2023/11/08 13:21:42 wiz Exp $
#
# When updating this package, also update x11/py-xcbgen

DISTNAME=	xcb-proto-1.16.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://xorg.freedesktop.org/archive/individual/proto/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	XCB protocol descriptions (in XML)
LICENSE=	mit # with no-advertising clause

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	xcb-proto.pc.in

CONFIGURE_ENV+=		XMLLLINT=${BUILDLINK_PREFIX.libxml2}/bin/xmllint

# XXX just for the "configure" check
PYTHON_FOR_BUILD_ONLY=	tool
.include "../../lang/python/application.mk"
BUILDLINK_DEPMETHOD.libxml2?=	build
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
