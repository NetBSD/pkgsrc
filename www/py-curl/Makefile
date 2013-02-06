# $NetBSD: Makefile,v 1.45 2013/02/06 23:24:03 jperkin Exp $

DISTNAME=	pycurl-7.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://pycurl.sourceforge.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pycurl.sourceforge.net/
COMMENT=	Python module interface to the cURL library
LICENSE=	gnu-lgpl-v2.1 OR mit

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

BUILDLINK_API_DEPENDS.curl+=	curl>=7.19.0

.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
