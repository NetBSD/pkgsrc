# $NetBSD: Makefile,v 1.15 2004/03/26 02:27:58 wiz Exp $

DISTNAME=	pycurl-7.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pycurl.sourceforge.net/download/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://pycurl.sf.net/
COMMENT=	Python module interface to the cURL library

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined
PYTHON_VERSIONS_ACCEPTED=	23pth 22pth
USE_BUILDLINK2=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../www/curl/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
