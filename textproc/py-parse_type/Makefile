# $NetBSD: Makefile,v 1.5 2022/01/04 20:55:01 wiz Exp $

DISTNAME=	parse_type-0.5.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
#MASTER_SITES=	${MASTER_SITE_PYPI:=p/parse_type/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=jenisys/}
GITHUB_PROJECT=	parse_type
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jenisys/parse_type
COMMENT=	Simplifies to build parse types based on the parse module
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-parse>=1.8.4:../../textproc/py-parse
DEPENDS+=	${PYPKGPREFIX}-six>=1.11:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-parse

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
