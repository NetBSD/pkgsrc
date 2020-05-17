# $NetBSD: Makefile,v 1.3 2020/05/17 20:18:36 adam Exp $

DISTNAME=	rfc3986-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rfc3986/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rfc3986.readthedocs.io/
COMMENT=	Validating URI References per RFC 3986
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
