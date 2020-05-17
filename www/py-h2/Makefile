# $NetBSD: Makefile,v 1.8 2020/05/17 20:18:36 adam Exp $

DISTNAME=	h2-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hyper.rtfd.org/
COMMENT=	HTTP/2 State-Machine based protocol implementation
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hyperframe>=5.2.0:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-hpack>=3.0:../../net/py-hpack
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34>=1.1.6:../../devel/py-enum34
.endif

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} test

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
