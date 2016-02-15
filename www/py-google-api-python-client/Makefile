# $NetBSD: Makefile,v 1.5 2016/02/15 00:21:29 mef Exp $

DISTNAME=	google-api-python-client-1.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:C/^${PYPKGPREFIX}-//}

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
