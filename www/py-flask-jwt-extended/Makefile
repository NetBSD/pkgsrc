# $NetBSD: Makefile,v 1.2 2019/07/02 03:36:18 adam Exp $

DISTNAME=	Flask-JWT-Extended-3.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-JWT-Extended/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vimalloc/flask-jwt-extended
COMMENT=	Extended JWT integration with Flask
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-JWT-[0-9]*:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.3:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.14:../../www/py-werkzeug
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
