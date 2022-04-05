# $NetBSD: Makefile,v 1.1 2022/04/05 07:15:09 adam Exp $

DISTNAME=	ini2toml-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ini2toml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abravalheri/ini2toml
COMMENT=	Automatically conversion of .ini/.cfg files to TOML equivalents
LICENSE=	mpl-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-packaging>=20.7:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-configupdater>=3.0.1:../../devel/py-configupdater
TEST_DEPENDS+=	${PYPKGPREFIX}-test>0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>0:../../devel/py-test-cov

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ini2toml ini2toml-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
