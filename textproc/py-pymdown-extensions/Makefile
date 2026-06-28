# $NetBSD: Makefile,v 1.2 2026/06/28 15:41:42 wiz Exp $

DISTNAME=	pymdown_extensions-10.21.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymdown-extensions/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/facelessuser/pymdown-extensions
COMMENT=	Extension pack for Python Markdown
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.6:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
