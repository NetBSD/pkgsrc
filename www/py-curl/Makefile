# $NetBSD: Makefile,v 1.36 2008/04/25 20:39:13 joerg Exp $

DISTNAME=	pycurl-7.16.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://pycurl.sourceforge.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pycurl.sourceforge.net/
COMMENT=	Python module interface to the cURL library

BROKEN_IN=		pkgsrc-2006Q4

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

BUILDLINK_API_DEPENDS.curl+=        curl>=7.16.1

.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
