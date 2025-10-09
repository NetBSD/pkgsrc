# $NetBSD: Makefile,v 1.6 2025/10/09 12:08:24 wiz Exp $

DISTNAME=	eradicate-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eradicate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/myint/eradicate
COMMENT=	Removes commented-out code
LICENSE=	mit

USE_LANGUAGES=	# none

# https://github.com/PyCQA/eradicate/issues/57
PYTHON_VERSIONS_INCOMPATIBLE=	314

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} eradicate eradicate-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
