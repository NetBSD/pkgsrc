# $NetBSD: Makefile,v 1.2.2.1 2002/06/23 19:04:36 jlam Exp $

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
