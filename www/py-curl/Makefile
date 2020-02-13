# $NetBSD: Makefile,v 1.68 2020/02/13 19:07:04 adam Exp $

DISTNAME=	pycurl-7.43.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=pycurl/}
GITHUB_PROJECT=	pycurl
GITHUB_TAG=	REL_7_43_0_5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pycurl.io/
COMMENT=	Python module interface to the cURL library
LICENSE=	gnu-lgpl-v2.1 OR mit

PYSETUPARGS=	--with-openssl
MAKE_FLAGS+=	PYTHON=${PYTHONBIN}

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS}

BUILDLINK_API_DEPENDS.curl+=	curl>=7.19.0
.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
