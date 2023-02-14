# $NetBSD: Makefile,v 1.6 2023/02/14 18:29:33 adam Exp $

DISTNAME=	parse_type-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parse_type/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jenisys/parse_type
COMMENT=	Simplifies to build parse types based on the parse module
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-parse>=1.18.0:../../textproc/py-parse
DEPENDS+=	${PYPKGPREFIX}-six>=1.11:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-parse

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
