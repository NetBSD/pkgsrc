# $NetBSD: Makefile,v 1.20 2004/11/28 13:04:03 recht Exp $

DISTNAME=	pycurl-7.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	www python
MASTER_SITES=	http://pycurl.sourceforge.net/download/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://pycurl.sf.net/
COMMENT=	Python module interface to the cURL library

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined
PYTHON_VERSIONS_ACCEPTED=	23pth 22pth
USE_BUILDLINK3=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

BUILDLINK_DEPENDS.curl+=        curl>=7.12.1

.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
