# $NetBSD: Makefile,v 1.14 2003/02/18 00:41:35 grant Exp $

DISTNAME=	modxslt-1.1
PKGNAME=	ap-xslt-1.1
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modxslt/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://modxslt.sourceforge.net/
COMMENT=	Simple, fast XSLT transformations for apache

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_xslt.so
LDFLAGS+=	        -lsablot -liconv -lstdc++ -lm

.include "../../textproc/sablotron/buildlink2.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
