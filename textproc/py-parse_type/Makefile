# $NetBSD: Makefile,v 1.2 2019/08/13 11:00:35 adam Exp $

DISTNAME=	parse_type-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parse_type/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jenisys/parse_type
COMMENT=	Simplifies to build parse types based on the parse module
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-parse>=1.8.4:../../textproc/py-parse
DEPENDS+=	${PYPKGPREFIX}-six>=1.11:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
