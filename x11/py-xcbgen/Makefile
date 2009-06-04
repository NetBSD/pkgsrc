# $NetBSD: Makefile,v 1.3 2009/06/04 09:56:20 hasso Exp $
#

DISTNAME=	xcb-proto-1.5
PKGNAME=	${PYPKGPREFIX}-xcbgen-1.5
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB protocol descriptions (in XML)

CONFLICTS+=	xcb-proto<1.4nb1
PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	26 25

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none
PY_PATCHPLIST=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
