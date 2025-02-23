# $NetBSD: Makefile,v 1.40 2025/02/23 18:28:23 wiz Exp $

DISTNAME=	jinja2-3.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=J/Jinja2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jinja.palletsprojects.com/
COMMENT=	Small but fast and easy to use stand-alone template engine
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-babel>=2.7:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.0:../../textproc/py-markupsafe
TEST_DEPENDS+=	${PYPKGPREFIX}-trio-[0-9]*:../../devel/py-trio

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
