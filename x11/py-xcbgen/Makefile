# $NetBSD: Makefile,v 1.12 2012/10/29 05:06:46 asau Exp $
#

DISTNAME=	xcb-proto-1.8
PKGNAME=	${PYPKGPREFIX}-xcbgen-1.8
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB protocol descriptions (in XML)
LICENSE=	mit # with no-advertising clause

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

CONFLICTS+=	xcb-proto<1.4nb1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none
PY_PATCHPLIST=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
