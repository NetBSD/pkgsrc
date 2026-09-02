# $NetBSD: Makefile,v 1.22 2026/09/02 10:00:42 adam Exp $

DISTNAME=	readme_renderer-46.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/readme_renderer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/readme_renderer
COMMENT=	Library for rendering "readme" descriptions for Warehouse
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.21.2:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-nh3>=0.2.14:../../www/py-nh3
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.1:../../textproc/py-pygments
# md
DEPENDS+=	${PYPKGPREFIX}-comrak>=0.0.13:../../textproc/py-comrak

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
