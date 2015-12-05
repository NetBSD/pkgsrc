# $NetBSD: Makefile,v 1.32 2015/12/05 21:26:09 adam Exp $

DISTNAME=	Pmw.1.3.2
EGG_NAME=	${DISTNAME:S/./-/}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pmw.sourceforge.net/
COMMENT=	Python meta widgets (python-2.x version)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
DEPENDS+=	blt>=2.4i:../../x11/blt

USE_LANGUAGES=	# empty

PYSETUPSUBDIR=	src
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
