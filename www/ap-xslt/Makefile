# $NetBSD: Makefile,v 1.21 2003/07/13 13:53:46 wiz Exp $

DISTNAME=	modxslt-1.1
PKGNAME=	ap-xslt-1.1
PKGREVISION=	6
WRKSRC=		${WRKDIR}/modxslt
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modxslt/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://modxslt.sourceforge.net/
COMMENT=	Simple, fast XSLT transformations for apache

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_xslt.so
LDFLAGS+=	        -lsablot

.include "../../textproc/sablotron/buildlink2.mk"
.include "../../www/libwww/buildlink2.mk"

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
