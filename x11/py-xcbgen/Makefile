# $NetBSD: Makefile,v 1.23 2022/05/04 04:38:06 wiz Exp $

DISTNAME=	xcb-proto-1.15
PKGNAME=	${PYPKGPREFIX}-xcbgen-1.15
CATEGORIES=	x11
MASTER_SITES=	https://xorg.freedesktop.org/archive/individual/proto/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	XCB protocol descriptions (in XML)
LICENSE=	mit # with no-advertising clause

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CONFLICTS+=	xcb-proto<1.4nb1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none
PY_PATCHPLIST=	yes

# pkgsrc infrastructure does not support opt-2 files
post-install:
	${RM} -f ${DESTDIR}/${PREFIX}/${PYSITELIB}/xcbgen/__pycache__/*opt-2*pyc

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
