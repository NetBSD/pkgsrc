# $NetBSD: Makefile,v 1.19 2018/03/13 11:46:13 adam Exp $

DISTNAME=	aiohttp-3.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohttp
COMMENT=	Async http client/server framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-async-timeout>=1.2.0:../../devel/py-async-timeout
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.4.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-chardet>=2.0:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-idna-ssl>=1.0:../../www/py-idna_ssl
DEPENDS+=	${PYPKGPREFIX}-multidict>=4.0:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-yarl>=1.0:../../www/py-yarl
BUILD_DEPENDS+=	${PYPKGPREFIX}-gunicorn-[0-9]*:../../www/py-gunicorn
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

PYTHON_VERSIONS_INCOMPATIBLE=	27 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
