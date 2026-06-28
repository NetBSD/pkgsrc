# $NetBSD: Makefile,v 1.23 2026/06/28 15:41:47 wiz Exp $

DISTNAME=	httpbin-0.10.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpbin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/psf/httpbin
COMMENT=	HTTP Request and Response Service
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-brotlicffi-[0-9]*:../../archivers/py-brotlicffi
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-greenlet>=3.0.0:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-flasgger-[0-9]*:../../www/py-flasgger
DEPENDS+=	${PYPKGPREFIX}-flask>=2.2.4:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=2.2.2:../../www/py-werkzeug

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
