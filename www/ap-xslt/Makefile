# $NetBSD: Makefile,v 1.37 2010/02/20 14:58:45 joerg Exp $

DISTNAME=	modxslt-1.1
PKGNAME=	ap13-xslt-1.1
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modxslt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mod-xslt2.com/
COMMENT=	Simple, fast XSLT transformations for apache

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ap-xslt-[0-9]*

WRKSRC=		${WRKDIR}/modxslt

APACHE_MODULE_NAME=	mod_xslt.so
LDFLAGS+=		-lsablot

.include "../../www/apache/module.mk"

.include "../../textproc/sablotron/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
