# $NetBSD: Makefile,v 1.3 2016/05/05 11:37:32 wiz Exp $

DISTNAME=	betamax-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/cc/bd/4879257f4d7c44bb3f19b9d48c9b5e5d1f4ea6efab2d4da48c6bd55468ff/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/betamax
COMMENT=	VCR imitation for python-requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
