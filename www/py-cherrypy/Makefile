# $NetBSD: Makefile,v 1.21 2017/07/19 17:32:38 adam Exp $

DISTNAME=	CherryPy-11.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CherryPy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherrypy.org/
COMMENT=	CherryPy is a pythonic, object-oriented HTTP framework
LICENSE=	modified-bsd

USE_LANGUAGES=		# none

REPLACE_PYTHON+=	cherrypy/test/sessiondemo.py

DEPENDS+=	${PYPKGPREFIX}-cheroot>=5.2.0:../../www/py-cheroot
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-portend>=2.1.1:../../net/py-portend
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
