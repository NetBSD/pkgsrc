# $NetBSD: Makefile,v 1.8 2024/08/27 07:58:27 adam Exp $

DISTNAME=	parse_type-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parse_type/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jenisys/parse_type
COMMENT=	Simplifies to build parse types based on the parse module
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-parse>=1.18.0:../../textproc/py-parse
DEPENDS+=	${PYPKGPREFIX}-six>=1.15:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
