# $NetBSD: Makefile,v 1.19 2019/09/21 13:09:38 adam Exp $

DISTNAME=	furl-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/furl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gruns/furl
COMMENT=	URL manipulation made simple
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-orderedmultidict>=1.0:../../databases/py-orderedmultidict
DEPENDS+=	${PYPKGPREFIX}-six>=1.8.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
