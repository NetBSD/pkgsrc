# $NetBSD: Makefile,v 1.18 2017/02/15 23:21:07 joerg Exp $

DISTNAME=	CherryPy-10.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CherryPy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherrypy.org/
COMMENT=	CherryPy is a pythonic, object-oriented HTTP framework
LICENSE=	modified-bsd

USE_LANGUAGES=		# none

REPLACE_PYTHON+=	cherrypy/test/sessiondemo.py

DEPENDS+=	${PYPKGPREFIX}-cheroot-[0-9]*:../../www/py-cheroot
DEPENDS+=	${PYPKGPREFIX}-portend-[0-9]*:../../net/py-portend
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
