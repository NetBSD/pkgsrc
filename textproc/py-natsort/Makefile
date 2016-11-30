# $NetBSD: Makefile,v 1.2 2016/11/30 14:38:58 wiz Exp $

DISTNAME=	natsort-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/natsort/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/SethMMorton/natsort
COMMENT=	Natural sorting for python
LICENSE=	mit

USE_LANGUAGES=	# none

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes
BUILD_DEPENDS+=	${PYPKGPREFIX}-pep8-[0-9]*:../../devel/py-pep8
# these are currently unpackaged
#BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cache-[0-9]*:../../devel/py-test-cache
#BUILD_DEPENDS+=	${PYPKGPREFIX}-test-flakes-[0-9]*:../../devel/py-test-flakes
#BUILD_DEPENDS+=	${PYPKGPREFIX}-test-pep8-[0-9]*:../../devel/py-test-pep8
#BUILD_DEPENDS+=	${PYPKGPREFIX}-execnet-[0-9]*:../../devel/py-execnet

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
