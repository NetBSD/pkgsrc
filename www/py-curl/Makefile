# $NetBSD: Makefile,v 1.21 2005/01/03 15:59:12 wiz Exp $

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
PYTHON_VERSIONS_ACCEPTED=	23pth 22pth
USE_BUILDLINK3=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

BUILDLINK_DEPENDS.curl+=        curl>=7.12.1

.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
