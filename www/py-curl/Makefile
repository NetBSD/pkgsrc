# $NetBSD: Makefile,v 1.29 2006/11/19 11:50:25 wiz Exp $

DISTNAME=	pycurl-7.13.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://pycurl.sourceforge.net/download/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://pycurl.sourceforge.net/
COMMENT=	Python module interface to the cURL library

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined
PYTHON_VERSIONS_ACCEPTED=	23 22
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

BUILDLINK_API_DEPENDS.curl+=        curl>=7.12.1

.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
