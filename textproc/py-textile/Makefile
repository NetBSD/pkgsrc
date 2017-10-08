# $NetBSD: Makefile,v 1.17 2017/10/08 20:25:53 joerg Exp $

DISTNAME=	textile-2.3.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/textile/python-textile
COMMENT=	XHTML generator using a simple markup
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pytextile pytextile${PYVERSSUFFIX} || ${TRUE}


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
