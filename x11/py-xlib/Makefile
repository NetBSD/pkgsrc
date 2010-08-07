# $NetBSD: Makefile,v 1.1.1.1 2010/08/07 04:53:24 obache Exp $
#

DISTNAME=	python-xlib-0.14
PKGNAME=	${DISTNAME:S/python-/${PYPKGPREFIX}-/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-xlib/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://python-xlib.sourceforge.net/
COMMENT=	Pure Python X Library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
EGG_NAME=	python_xlib-0.12

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
