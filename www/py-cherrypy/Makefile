# $NetBSD: Makefile,v 1.19 2017/03/12 18:51:01 adam Exp $

DISTNAME=	CherryPy-10.2.0
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
