# $NetBSD: Makefile,v 1.7 2016/03/04 13:54:25 wen Exp $

DISTNAME=	Uliweb-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/U/u/}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/U/Uliweb/

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/Uliweb/
COMMENT=	Easy python web framework
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.2.3

REPLACE_PYTHON=		uliweb/contrib/csrf/*.py
REPLACE_PYTHON+=	uliweb/core/*.py
REPLACE_PYTHON+=	uliweb/i18n/*.py
REPLACE_PYTHON+=	uliweb/lib/pysimplesoap-1.05a/pysimplesoap-1.05a/pysimplesoap/*.py
REPLACE_PYTHON+=	uliweb/lib/pysimplesoap-1.05a/pysimplesoap-1.05a/setup.py
REPLACE_PYTHON+=	uliweb/lib/pysimplesoap-1.05a/pysimplesoap-1.05a/tests/*.py
REPLACE_PYTHON+=	uliweb/lib/pysimplesoap/*.py
REPLACE_PYTHON+=	uliweb/lib/rcssmin/rcssmin.py
REPLACE_PYTHON+=	uliweb/lib/rjsmin/rjsmin.py
REPLACE_PYTHON+=	uliweb/manage.py
REPLACE_PYTHON+=	uliweb/template_files/support/fcgi/fcgi_handler.fcgi
REPLACE_PYTHON+=	uliweb/utils/*.py

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
