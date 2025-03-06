# $NetBSD: Makefile,v 1.42 2025/03/06 08:08:52 adam Exp $

DISTNAME=	jinja2-3.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=J/Jinja2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jinja.palletsprojects.com/
COMMENT=	Small but fast and easy to use stand-alone template engine
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.0:../../textproc/py-markupsafe
# i18n
DEPENDS+=	${PYPKGPREFIX}-babel>=2.7:../../devel/py-babel
TEST_DEPENDS+=	${PYPKGPREFIX}-trio-[0-9]*:../../devel/py-trio

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
