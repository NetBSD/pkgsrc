# $NetBSD: Makefile,v 1.16 2022/01/04 20:55:36 wiz Exp $

DISTNAME=	Uliweb-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/U/u/}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=U/Uliweb/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/Uliweb/
COMMENT=	Easy python web framework
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.2.3

REPLACE_PYTHON=		uliweb/contrib/csrf/*.py
REPLACE_PYTHON+=	uliweb/core/*.py
REPLACE_PYTHON+=	uliweb/i18n/*.py
REPLACE_PYTHON+=	uliweb/lib/rcssmin/rcssmin.py
REPLACE_PYTHON+=	uliweb/lib/rjsmin/rjsmin.py
REPLACE_PYTHON+=	uliweb/manage.py
REPLACE_PYTHON+=	uliweb/utils/*.py

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
