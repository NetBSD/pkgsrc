# $NetBSD: Makefile,v 1.1 2014/12/05 21:40:40 rodent Exp $

DISTNAME=	google-api-python-client-py3-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/g/google-api-python-client-py3/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://code.google.com/p/google-api-python-client/
COMMENT=	Google API Client Library for Python (python 3x port)
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.8:../../www/py-httplib2

USE_LANGUAGES=			# none
PYTHON_VERSIONS_INCOMPATIBLE=	26 27 # won't CONFLICT with the 2.x version

REPLACE_PYTHON+=	apiclient/*.py oauth2client/*.py
EGG_NAME=		${DISTNAME:S/-/_/g:S/3_/3-/1}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
