# $NetBSD: Makefile,v 1.6 2015/12/07 09:04:50 wiz Exp $

DISTNAME=	httplib2-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httplib2/}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/jcgregorio/httplib2
COMMENT=	Comprehensive http client library for Python
LICENSE=	mit

# permissions are usually wrong
post-install:
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/*
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${PYSITELIB}/httplib2/cacerts.txt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
