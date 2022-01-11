# $NetBSD: Makefile,v 1.6 2022/01/11 21:53:33 nros Exp $

DISTNAME=	tomli-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tomli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hukkin/tomli
COMMENT=	Lil' TOML parser
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

.include "../../lang/python/wheel.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
