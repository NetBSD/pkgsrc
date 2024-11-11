# $NetBSD: Makefile,v 1.18 2024/11/11 07:29:08 wiz Exp $

DISTNAME=	readme_renderer-44.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/readme_renderer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/readme_renderer
COMMENT=	Library for rendering "readme" descriptions for Warehouse
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.21.2:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-nh3>=0:../../www/py-nh3

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
