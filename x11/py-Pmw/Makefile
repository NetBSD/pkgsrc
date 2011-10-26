# $NetBSD: Makefile,v 1.28 2011/10/26 13:10:08 obache Exp $
#

DISTNAME=	Pmw.1.3.2
EGG_NAME=	${DISTNAME:S/./-/}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pmw.sourceforge.net/
COMMENT=	Python meta widgets
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
DEPENDS+=	blt>=2.4i:../../x11/blt

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

PYSETUPSUBDIR=	src

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
