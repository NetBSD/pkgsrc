# $NetBSD: Makefile,v 1.9 2020/05/17 20:18:35 adam Exp $

DISTNAME=	betamax-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/betamax/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sigmavirus24/betamax
COMMENT=	VCR imitation for python-requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests

PYTHON_VERSIONED_DEPENDENCIES=	test:build

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
