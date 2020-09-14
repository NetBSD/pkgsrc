# $NetBSD: Makefile,v 1.5 2020/09/14 07:36:25 adam Exp $

DISTNAME=	iso8601-0.1.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/iso8601/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/micktwomey/pyiso8601
COMMENT=	Simple Python module to parse ISO 8601 dates
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} iso8601/test_iso8601.py

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
