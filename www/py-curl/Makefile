# $NetBSD: Makefile,v 1.2 2002/04/21 12:14:50 shell Exp $

DISTNAME=	pycurl-0.4.9
PKGNAME=	${PYPKGPREFIX}-curl-0.4.9
CATEGORIES=	www
MASTER_SITES=	http://pycurl.sourceforge.net/

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://pycurl.sf.net/
COMMENT=	python module interface to the cURL library

DEPENDS+=	curl>=7.9.6:../../www/curl

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
