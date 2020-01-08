# $NetBSD: Makefile,v 1.6 2020/01/08 19:08:18 adam Exp $

DISTNAME=	h2-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hyper.rtfd.org/
COMMENT=	HTTP/2 State-Machine based protocol implementation
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hyperframe>=5.2.0:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-hpack>=2.3:../../net/py-hpack
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34>=1.1.6:../../devel/py-enum34
.endif

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
