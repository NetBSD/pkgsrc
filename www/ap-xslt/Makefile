# $NetBSD: Makefile,v 1.40 2014/02/12 23:18:43 tron Exp $

DISTNAME=	modxslt-1.1
PKGNAME=	ap13-xslt-1.1
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modxslt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mod-xslt2.com/
COMMENT=	Simple, fast XSLT transformations for apache

CONFLICTS=	ap-xslt-[0-9]*

WRKSRC=		${WRKDIR}/modxslt

APACHE_MODULE_NAME=	mod_xslt.so
LDFLAGS+=		-lsablot

.include "../../www/apache/module.mk"

.include "../../textproc/sablotron/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
