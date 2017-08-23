# $NetBSD: Makefile,v 1.8 2017/08/23 12:17:28 wiz Exp $

DISTNAME=	cheroot-5.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/Cheroot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherrypy.org/
COMMENT=	High-performance, pure-Python HTTP server used by CherryPy
LICENSE=	modified-bsd

USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.8:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
