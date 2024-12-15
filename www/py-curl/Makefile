# $NetBSD: Makefile,v 1.96 2024/12/15 09:36:26 adam Exp $

DISTNAME=	pycurl-7.45.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycurl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pycurl.io/
COMMENT=	Python module interface to the cURL library
LICENSE=	gnu-lgpl-v2.1 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-bottle-[0-9]*:../../www/py-bottle
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

MAKE_ENV+=	PYCURL_SSL_LIBRARY=openssl
INSTALL_ENV+=	PYCURL_SSL_LIBRARY=openssl

BUILDLINK_API_DEPENDS.curl+=	curl>=7.19.0
.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
