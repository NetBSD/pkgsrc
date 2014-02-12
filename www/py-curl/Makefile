# $NetBSD: Makefile,v 1.47 2014/02/12 23:18:46 tron Exp $

DISTNAME=	pycurl-7.19.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://pycurl.sourceforge.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pycurl.sourceforge.net/
COMMENT=	Python module interface to the cURL library
LICENSE=	gnu-lgpl-v2.1 OR mit

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

BUILDLINK_API_DEPENDS.curl+=	curl>=7.19.0

PYSETUPARGS=	--with-ssl

.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
