# $NetBSD: Makefile,v 1.1 2014/05/03 15:34:22 rodent Exp $
#

DISTNAME=	python-cjson-1.0.5
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/1}
CATEGORIES=	python textproc
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-cjson/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://ag-projects.com/
COMMENT=	Fast JSON encoder/decoder for Python
LICENSE=	gnu-lgpl-v2

PYDISTUTILSPKG= yes

do-test:
	( cd ${WKSRC} && ${PYTHONBIN} jsontest.py )

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
