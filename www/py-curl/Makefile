# $NetBSD: Makefile,v 1.50 2016/08/28 15:48:36 wiz Exp $

DISTNAME=	pycurl-7.19.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://pycurl.sourceforge.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pycurl.sourceforge.net/
COMMENT=	Python module interface to the cURL library
LICENSE=	gnu-lgpl-v2.1 OR mit

PYSETUPARGS=	--with-ssl

BUILDLINK_API_DEPENDS.curl+=	curl>=7.19.0
.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
