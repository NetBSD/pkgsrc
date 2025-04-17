# $NetBSD: Makefile,v 1.99 2025/04/17 21:52:52 wiz Exp $

DISTNAME=	pycurl-7.45.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycurl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pycurl.io/
COMMENT=	Python module interface to the cURL library
LICENSE=	gnu-lgpl-v2.1 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-bottle-[0-9]*:../../www/py-bottle
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

MAKE_ENV+=	PYCURL_SSL_LIBRARY=openssl
INSTALL_ENV+=	PYCURL_SSL_LIBRARY=openssl

BUILDLINK_API_DEPENDS.curl+=	curl>=7.19.0
.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
