# $NetBSD: Makefile,v 1.24 2004/01/20 12:27:58 agc Exp $

DISTNAME=	modxslt-1.1
PKGNAME=	ap-xslt-1.1
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modxslt/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://modxslt.sourceforge.net/
COMMENT=	Simple, fast XSLT transformations for apache

WRKSRC=		${WRKDIR}/modxslt
USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_xslt.so
LDFLAGS+=	        -lsablot

.include "../../textproc/sablotron/buildlink2.mk"
.include "../../www/libwww/buildlink2.mk"

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
