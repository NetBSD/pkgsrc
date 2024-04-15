# $NetBSD: Makefile,v 1.28 2024/04/15 16:34:48 wiz Exp $
#
# When updating this, also update x11/xcb-proto

DISTNAME=	xcb-proto-1.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/xcb-proto/xcbgen/}
CATEGORIES=	x11
MASTER_SITES=	https://xorg.freedesktop.org/archive/individual/proto/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	XCB protocol descriptions (in XML)
LICENSE=	mit # with no-advertising clause

CONFLICTS+=	xcb-proto<1.4nb1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none
PY_PATCHPLIST=	yes

# pkgsrc infrastructure does not support opt-2 files
post-install:
	${RM} -f ${DESTDIR}/${PREFIX}/${PYSITELIB}/xcbgen/__pycache__/*opt-2*pyc

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
