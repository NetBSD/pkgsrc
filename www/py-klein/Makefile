# $NetBSD: Makefile,v 1.10 2023/06/22 16:45:39 adam Exp $

DISTNAME=	klein-21.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/klein/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://klein.readthedocs.io/en/latest/
COMMENT=	Micro-framework for developing web services
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-hyperlink-[0-9]*:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-incremental-[0-9]*:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-tubes-[0-9]*:../../devel/py-tubes
DEPENDS+=	${PYPKGPREFIX}-twisted>=16.6:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-zope.interface-[0-9]*:../../devel/py-zope.interface

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
