# $NetBSD: Makefile,v 1.1 2009/04/08 13:06:22 drochner Exp $
#

DISTNAME=	xcb-proto-1.4
PKGNAME=	${PYPKGPREFIX}-xcbgen-1.4
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB protocol descriptions (in XML)

CONFLICTS+=	xcb-proto<1.4nb1
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none
PY_PATCHPLIST=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
