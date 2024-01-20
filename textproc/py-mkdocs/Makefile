# $NetBSD: Makefile,v 1.11 2024/01/20 10:07:54 adam Exp $

DISTNAME=	mkdocs-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mkdocs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mkdocs/mkdocs
COMMENT=	Fast and simple static site generator for documentation
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-ghp-import>=1.0:../../misc/py-ghp-import
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.2.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.0.1:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-mergedeep>=1.3.4:../../devel/py-mergedeep
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.5:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.11.1:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.2.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-watchdog>=2.0:../../sysutils/py-watchdog
DEPENDS+=	${PYPKGPREFIX}-pyyaml_env_tag>=0.1:../../textproc/py-pyyaml_env_tag
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.10:../../devel/py-importlib-metadata
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} mkdocs mkdocs-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
