# $NetBSD: Makefile,v 1.3 2024/05/08 09:12:15 adam Exp $

DISTNAME=	json5-0.9.25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/json5/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dpranke/pyjson5
COMMENT=	Python implementation of the JSON5 data format
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pyjson5 pyjson5-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
