# $NetBSD: Makefile,v 1.23 2003/08/29 15:50:07 xtraeme Exp $

DISTNAME=	modxslt-1.1
PKGNAME=	ap-xslt-1.1
PKGREVISION=	7
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
