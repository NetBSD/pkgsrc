# $NetBSD: Makefile,v 1.30 2007/01/31 00:04:13 wiz Exp $

DISTNAME=	pycurl-7.13.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://pycurl.sourceforge.net/download/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://pycurl.sourceforge.net/
COMMENT=	Python module interface to the cURL library

BROKEN_IN=		pkgsrc-2006Q4

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined
PYTHON_VERSIONS_ACCEPTED=	23 22
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

BUILDLINK_API_DEPENDS.curl+=        curl>=7.12.1

.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
