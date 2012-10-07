# $NetBSD: Makefile,v 1.11 2012/10/07 22:08:43 wiz Exp $
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
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none
PY_PATCHPLIST=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
