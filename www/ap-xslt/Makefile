# $NetBSD: Makefile,v 1.27 2004/10/03 00:18:24 tv Exp $

DISTNAME=	modxslt-1.1
PKGNAME=	ap-xslt-1.1
PKGREVISION=	9
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modxslt/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://modxslt.sourceforge.net/
COMMENT=	Simple, fast XSLT transformations for apache

WRKSRC=		${WRKDIR}/modxslt
USE_BUILDLINK3=	YES

APACHE_MODULE_NAME=	mod_xslt.so
LDFLAGS+=	        -lsablot

.include "../../www/apache/module.mk"

.include "../../textproc/sablotron/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
