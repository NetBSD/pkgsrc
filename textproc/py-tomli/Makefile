# $NetBSD: Makefile,v 1.9 2022/03/31 08:40:49 adam Exp $

DISTNAME=	tomli-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_WHEEL:=tomli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hukkin/tomli
COMMENT=	Lil' TOML parser
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# use the wheel here to avoid a circular dependency
# py-tomli -> (py-flit_core|wheel.mk) -> py-build -> py-tomli
NO_BUILD=		yes
#BUILD_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
