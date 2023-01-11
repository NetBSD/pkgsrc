# $NetBSD: Makefile,v 1.9 2023/01/11 11:48:35 adam Exp $

DISTNAME=	cssselect-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cssselect/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.python.org/cssselect/
COMMENT=	Parses CSS3 Selectors and translates them to XPath 1.0
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
