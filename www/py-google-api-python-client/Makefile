# $NetBSD: Makefile,v 1.17 2018/01/21 11:54:02 adam Exp $

DISTNAME=	google-api-python-client-1.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-api-python-client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/google-api-python-client
COMMENT=	Python client library for Google's discovery based APIs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.9.2:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-oauth2client>=1.5.0:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-uritemplate>=3.0.0:../../textproc/py-uritemplate

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
