# $NetBSD: Makefile,v 1.21 2020/02/23 22:32:03 wiz Exp $

DISTNAME=	xcb-proto-1.14
PKGNAME=	${PYPKGPREFIX}-xcbgen-1.14
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

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
