# $NetBSD: Makefile,v 1.3 2002/06/10 01:47:15 shell Exp $

DISTNAME=	pycurl-7.9.7
PKGNAME=	${PYPKGPREFIX}-curl-7.9.7
CATEGORIES=	www
MASTER_SITES=	http://pycurl.sourceforge.net/

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://pycurl.sf.net/
COMMENT=	python module interface to the cURL library

DEPENDS+=	curl>=7.9.7:../../www/curl

PYDISTUTILSPKG=	# defined
PYBINMODULE=	# defined

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
