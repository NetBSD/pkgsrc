# $NetBSD: Makefile,v 1.4 2016/06/08 17:43:41 wiz Exp $
#

DISTNAME=	python-cjson-1.0.5
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/1}
CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-cjson/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://ag-projects.com/
COMMENT=	Fast JSON encoder/decoder for Python
LICENSE=	gnu-lgpl-v2

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # Uses old string API.

do-test:
	( cd ${WKSRC} && ${PYTHONBIN} jsontest.py )

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
