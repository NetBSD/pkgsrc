# $NetBSD: Makefile,v 1.2 2020/04/11 07:11:35 adam Exp $

DISTNAME=	rfc3986-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rfc3986/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rfc3986.readthedocs.io/
COMMENT=	Validating URI References per RFC 3986
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
