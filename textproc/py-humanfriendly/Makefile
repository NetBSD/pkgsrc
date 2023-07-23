# $NetBSD: Makefile,v 1.3 2023/07/23 02:02:00 wiz Exp $

DISTNAME=	humanfriendly-10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=h/humanfriendly/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/humanfriendly/
COMMENT=	Human friendly output for text interfaces using Python
LICENSE=	mit

#TEST_DEPENDS+=	${PYPKGPREFIX}-capturer>=2.1:../../devel/py-capturer
TEST_DEPENDS+=	${PYPKGPREFIX}-coloredlogs>=15.0.1:../../devel/py-coloredlogs
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.15:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.7:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.4.0:../../devel/py-test-cov

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
