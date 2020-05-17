# $NetBSD: Makefile,v 1.9 2020/05/17 20:37:20 adam Exp $

DISTNAME=	parsel-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parsel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scrapy/parsel
COMMENT=	Library to extract data from HTML and XML using XPath and CSS
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.9:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.19.0:../../www/py-w3lib
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-functools32-[0-9]*:../../devel/py-functools32
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
