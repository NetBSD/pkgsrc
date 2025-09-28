# $NetBSD: Makefile,v 1.5 2025/09/28 20:00:19 wiz Exp $

DISTNAME=	pysaml2-7.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysaml2/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/IdentityPython/pysaml2
COMMENT=	Python implementation of SAML Version 2
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.1:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-xmlschema-[0-9]*:../../textproc/py-xmlschema

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/saml2/authn_context/timesync.py

post-install:
.for bin in make_metadata mdexport merge_metadata parse_xsd2
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
