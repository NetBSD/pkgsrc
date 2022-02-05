# $NetBSD: Makefile,v 1.9 2022/02/05 09:44:04 adam Exp $

DISTNAME=	mkdocs-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mkdocs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mkdocs/mkdocs
COMMENT=	Fast and simple static site generator for documentation
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=3.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-ghp-import>=1.0:../../misc/py-ghp-import
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.10:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-livereload>=2.5.1:../../www/py-livereload
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.2.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-mergedeep>=1.3.4:../../devel/py-mergedeep
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.5:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pyyaml_env_tag>=0.1:../../textproc/py-pyyaml_env_tag
DEPENDS+=	${PYPKGPREFIX}-tornado>=5.0:../../www/py-tornado
# should be watchdog>=2.0
DEPENDS+=	${PYPKGPREFIX}-watchdog>0:../../sysutils/py-watchdog
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} mkdocs mkdocs-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
