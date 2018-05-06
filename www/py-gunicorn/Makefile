# $NetBSD: Makefile,v 1.13 2018/05/06 09:10:48 adam Exp $

DISTNAME=	gunicorn-19.8.1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gunicorn/}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://gunicorn.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.5:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.4.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} gunicorn gunicorn-${PYVERSSUFFIX} && \
		${MV} gunicorn_paster gunicorn_paster-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
