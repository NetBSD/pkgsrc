# $NetBSD: Makefile,v 1.22 2005/01/23 20:41:49 recht Exp $

DISTNAME=	pycurl-7.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://pycurl.sourceforge.net/download/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://pycurl.sf.net/
COMMENT=	Python module interface to the cURL library

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined
PYTHON_VERSIONS_ACCEPTED=	23 22
USE_BUILDLINK3=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

BUILDLINK_DEPENDS.curl+=        curl>=7.12.1

.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
