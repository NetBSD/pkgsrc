# $NetBSD: Makefile,v 1.8 2017/10/08 09:10:11 adam Exp $

DISTNAME=	generateDS-2.28b0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/0$//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/generateDS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.davekuhlman.org/generateDS.html
COMMENT=	Python XML data binding library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
