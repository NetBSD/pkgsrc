# $NetBSD: Makefile,v 1.31 2006/06/02 18:27:59 joerg Exp $

DISTNAME=	modxslt-1.1
PKGNAME=	ap13-xslt-1.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modxslt/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://modxslt.sourceforge.net/
COMMENT=	Simple, fast XSLT transformations for apache

CONFLICTS=	ap-xslt-[0-9]*

WRKSRC=		${WRKDIR}/modxslt

APACHE_MODULE_NAME=	mod_xslt.so
LDFLAGS+=	        -lsablot

.include "../../www/apache/module.mk"

.include "../../textproc/sablotron/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
