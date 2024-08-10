# $NetBSD: Makefile,v 1.21 2024/08/10 07:43:30 adam Exp $

DISTNAME=	pelican-4.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pelican/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://blog.getpelican.com/
COMMENT=	Static site generator that supports Markdown and reST syntax
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=1.3.7:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.7.0:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.20.1:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-feedgenerator>=2.1.0:../../www/py-feedgenerator
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-ordered-set>=4.1.0:../../devel/py-ordered-set
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.16.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-rich>=13.6.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-watchfiles>=0.21.0:../../misc/py-watchfiles

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	pelican/tools/pelican_import.py
REPLACE_PYTHON+=	pelican/tools/pelican_quickstart.py
REPLACE_PYTHON+=	pelican/tools/pelican_themes.py
REPLACE_PYTHON+=	pelican/tools/templates/publishconf.py.jinja2

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
