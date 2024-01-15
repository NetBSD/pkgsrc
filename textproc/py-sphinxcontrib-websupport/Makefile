# $NetBSD: Makefile,v 1.7 2024/01/15 10:58:30 wiz Exp $

DISTNAME=	sphinxcontrib_websupport-1.2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-websupport/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sphinx-doc.org/
COMMENT=	Sphinx API for Web Apps
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.7:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-sphinx>=5:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-serializinghtml-[0-9]*:../../textproc/py-sphinxcontrib-serializinghtml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
