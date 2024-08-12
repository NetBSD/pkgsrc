# $NetBSD: Makefile,v 1.7 2024/08/12 10:05:10 wiz Exp $

DISTNAME=	markdown-it-py-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/markdown-it-py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/executablebooks/markdown-it-py
COMMENT=	Python port of markdown-it
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.4:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-mdurl>=0.1:../../www/py-mdurl
DEPENDS+=	${PYPKGPREFIX}-linkify-it-py>=0:../../textproc/py-linkify-it-py

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} markdown-it markdown-it-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
