# $NetBSD: Makefile,v 1.11 2021/03/07 17:30:22 adam Exp $

DISTNAME=	Flask-JWT-Extended-4.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-JWT-Extended/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vimalloc/flask-jwt-extended
COMMENT=	Extended JWT integration with Flask
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-JWT>=2.0:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-flask>=1.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.14:../../www/py-werkzeug
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
