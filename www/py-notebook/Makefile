# $NetBSD: Makefile,v 1.29 2023/09/02 05:36:30 adam Exp $

DISTNAME=	notebook-7.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/notebook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Web-based notebook environment for interactive computing
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.11:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-jupyterlab>=4.0.2:../../www/py-jupyterlab
DEPENDS+=	${PYPKGPREFIX}-jupyterlab-server>=2.22.1:../../www/py-jupyterlab-server
DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=2.4.0:../../www/py-jupyter_server
DEPENDS+=	${PYPKGPREFIX}-notebook_shim>=0.2:../../www/py-notebook_shim
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2.0:../../www/py-tornado

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes
PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

SUBST_CLASSES+=		jlpm
SUBST_STAGE.jlpm=	pre-configure
SUBST_MESSAGE.jlpm=	Fixing jlpm executable name.
SUBST_FILES.jlpm=	pyproject.toml
SUBST_SED.jlpm=		-e 's,"jlpm,"jlpm-${PYVERSSUFFIX},g'

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-notebook jupyter-notebook-${PYVERSSUFFIX} || ${TRUE}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
