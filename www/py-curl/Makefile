# $NetBSD: Makefile,v 1.5 2002/10/20 02:53:03 shell Exp $

DISTNAME=	pycurl-7.10.1
PKGNAME=	${PYPKGPREFIX}-curl-7.10.1
CATEGORIES=	www
MASTER_SITES=	http://pycurl.sourceforge.net/download/

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://pycurl.sf.net/
COMMENT=	python module interface to the cURL library

DEPENDS+=	curl>=7.10.1:../../www/curl

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined
PYTHON_VERSIONS_ACCEPTED=	21pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
