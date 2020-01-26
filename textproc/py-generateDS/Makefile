# $NetBSD: Makefile,v 1.9 2020/01/26 17:32:17 rillig Exp $

DISTNAME=	generateDS-2.28b0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/0$//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/generateDS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.davekuhlman.org/generateDS.html
COMMENT=	Python XML data binding library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
