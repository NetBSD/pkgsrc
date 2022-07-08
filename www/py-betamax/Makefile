# $NetBSD: Makefile,v 1.11 2022/07/08 14:14:09 wiz Exp $

DISTNAME=	betamax-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/betamax/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sigmavirus24/betamax
COMMENT=	VCR imitation for python-requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
