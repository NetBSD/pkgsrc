# $NetBSD: Makefile,v 1.3 2017/11/25 12:56:31 wiz Exp $

DISTNAME=	pytest-httpbin-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-httpbin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pytest-httpbin
COMMENT=	Easily test your HTTP library against a local copy of httpbin
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-httpbin-[0-9]*:../../www/py-httpbin
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

# test failure in 0.3.0:
# https://github.com/kevin1024/pytest-httpbin/issues/46

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
