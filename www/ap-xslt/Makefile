# $NetBSD: Makefile,v 1.22 2003/07/17 22:55:27 grant Exp $

DISTNAME=	modxslt-1.1
PKGNAME=	ap-xslt-1.1
PKGREVISION=	6
WRKSRC=		${WRKDIR}/modxslt
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modxslt/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://modxslt.sourceforge.net/
COMMENT=	Simple, fast XSLT transformations for apache

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_xslt.so
LDFLAGS+=	        -lsablot

.include "../../textproc/sablotron/buildlink2.mk"
.include "../../www/libwww/buildlink2.mk"

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
