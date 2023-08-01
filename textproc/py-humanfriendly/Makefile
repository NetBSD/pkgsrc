# $NetBSD: Makefile,v 1.5 2023/08/01 20:39:22 adam Exp $

DISTNAME=	humanfriendly-10.0
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/humanfriendly/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://humanfriendly.readthedocs.io/
COMMENT=	Human friendly output for text interfaces using Python
LICENSE=	mit

# py-capturer depends on this
#TEST_DEPENDS+=	${PYPKGPREFIX}-capturer>=2.1:../../devel/py-capturer
TEST_DEPENDS+=	${PYPKGPREFIX}-coloredlogs>=15.0.1:../../devel/py-coloredlogs
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.15:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.7:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.4.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} humanfriendly humanfriendly-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
