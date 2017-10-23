# $NetBSD: Makefile,v 1.6 2017/10/23 15:45:29 adam Exp $

DISTNAME=	httpbin-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpbin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Runscope/httpbin/
COMMENT=	HTTP Request and Response Service
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-brotlipy-[0-9]*:../../archivers/py-brotlipy
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-common-[0-9]*:../../www/py-flask-common
DEPENDS+=	${PYPKGPREFIX}-Flask-Limiter-[0-9]*:../../www/py-flask-limiter
DEPENDS+=	${PYPKGPREFIX}-itsdangerous-[0-9]*:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
