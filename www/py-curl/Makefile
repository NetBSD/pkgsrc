# $NetBSD: Makefile,v 1.10 2003/07/22 04:14:35 martti Exp $

DISTNAME=	pycurl-7.10.1
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-curl-7.10.1
CATEGORIES=	www
MASTER_SITES=	http://pycurl.sourceforge.net/download/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://pycurl.sf.net/
COMMENT=	Python module interface to the cURL library

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined
PYTHON_VERSIONS_ACCEPTED=	21pth 22pth
USE_BUILDLINK2=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../www/curl/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
