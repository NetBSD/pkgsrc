# $NetBSD: Makefile,v 1.8 2026/09/22 12:40:13 adam Exp $

DISTNAME=	pysaml2-7.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysaml2/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/IdentityPython/pysaml2
COMMENT=	Python implementation of SAML Version 2
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=26.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cryptography>=46.0.5:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-dateutil>=0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-xmlschema>=2.0.0:../../textproc/py-xmlschema

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	make_metadata mdexport merge_metadata parse_xsd2
REPLACE_PYTHON+=	src/saml2/authn_context/timesync.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
