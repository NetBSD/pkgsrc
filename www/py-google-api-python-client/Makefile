# $NetBSD: Makefile,v 1.3 2015/12/05 21:26:05 adam Exp $

DISTNAME=	google-api-python-client-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	-https://github.com/google/google-api-python-client/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/google-api-python-client
COMMENT=	Python client library for Google's discovery based APIs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-oauth2client-[0-9]*:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-uritemplate-[0-9]*:../../textproc/py-uritemplate

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # as of 1.3.1

# doesn't work, but doesn't matter
# see also https://github.com/google/google-api-python-client/issues/40
REPLACE_PYTHON+=	googleapiclient/errors.py
REPLACE_PYTHON+=	googleapiclient/model.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
