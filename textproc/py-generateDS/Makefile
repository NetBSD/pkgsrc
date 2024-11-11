# $NetBSD: Makefile,v 1.13 2024/11/11 07:29:02 wiz Exp $

DISTNAME=	generateDS-2.43.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/0$//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/generateDS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.davekuhlman.org/generateDS.html
COMMENT=	Python XML data binding library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests>=2.21.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
