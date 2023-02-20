# $NetBSD: Makefile,v 1.1 2023/02/20 10:52:16 adam Exp $

DISTNAME=	markdown-it-py-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/markdown-it-py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/executablebooks/markdown-it-py
COMMENT=	Python port of markdown-it
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.4:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-mdurl>=0.1:../../www/py-mdurl

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} markdown-it markdown-it-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
