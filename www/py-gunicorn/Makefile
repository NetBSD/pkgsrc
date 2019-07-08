# $NetBSD: Makefile,v 1.15 2019/07/08 10:36:27 nia Exp $

DISTNAME=	gunicorn-19.9.0
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gunicorn/}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://gunicorn.org/
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
