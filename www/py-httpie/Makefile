# $NetBSD: Makefile,v 1.8 2019/08/27 06:01:23 adam Exp $

DISTNAME=	httpie-1.0.3
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpie/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/jakubroztocil/httpie
COMMENT=	Human-friendly command line HTTP client
LICENSE=	original-bsd

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.1.3:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.4:../../devel/py-requests
# Tests are not included as of 1.0.3
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpbin-[0-9]*:../../www/py-test-httpbin

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} http http-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
