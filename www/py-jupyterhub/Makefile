# $NetBSD: Makefile,v 1.1 2026/05/27 11:00:10 markd Exp $
#

DISTNAME=	jupyterhub-5.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterhub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hub.jupyter.org/
COMMENT=	Multi-user server for Jupyter notebooks
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs
DEPENDS+=	${PYPKGPREFIX}-alembic>=1.4:../../databases/py-alembic
DEPENDS+=	${PYPKGPREFIX}-certipy>=0.1.2:../../security/py-certipy
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jupyter_events-[0-9]*:../../devel/py-jupyter_events
DEPENDS+=	${PYPKGPREFIX}-oauthlib>=3.0:../../security/py-oauthlib
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pamela>=1.1.0:../../security/py-pamela
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>=0.5.0:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.4.1:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-tornado>=5.1:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.3.2:../../devel/py-traitlets

PY_RENAME_BINARIES=	jupyterhub jupyterhub-singleuser
REPLACE_NODEJS=		share/jupyterhub/static/components/requirejs/bin/r.js

USE_LANGUAGES=	# none

.include "../../lang/nodejs/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
