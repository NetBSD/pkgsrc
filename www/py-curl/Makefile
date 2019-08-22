# $NetBSD: Makefile,v 1.64 2019/08/22 12:23:54 ryoon Exp $

DISTNAME=	pycurl-7.43.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	5
CATEGORIES=	www python
MASTER_SITES=	http://dl.bintray.com/pycurl/pycurl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pycurl.io/
COMMENT=	Python module interface to the cURL library
LICENSE=	gnu-lgpl-v2.1 OR mit

PYSETUPARGS=	--with-openssl

BUILDLINK_API_DEPENDS.curl+=	curl>=7.19.0
.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
