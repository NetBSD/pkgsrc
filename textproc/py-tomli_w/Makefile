# $NetBSD: Makefile,v 1.6 2024/10/10 12:26:06 adam Exp $

DISTNAME=	tomli_w-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tomli-w/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hukkin/tomli-w
COMMENT=	Lil' TOML writer
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2.0:../../devel/py-flit_core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
