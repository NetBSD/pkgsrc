# $NetBSD: Makefile,v 1.18 2003/05/27 08:30:44 grant Exp $

DISTNAME=	modxslt-1.1
PKGNAME=	ap-xslt-1.1
PKGREVISION=	4
WRKSRC=		${WRKDIR}/modxslt
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modxslt/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://modxslt.sourceforge.net/
COMMENT=	Simple, fast XSLT transformations for apache

USE_BUILDLINK2=	YES
USE_CXX=	YES

APACHE_MODULE_NAME=	mod_xslt.so
LDFLAGS+=	        -lsablot -liconv -lstdc++ -lm

.include "../../textproc/sablotron/buildlink2.mk"
.include "../../www/libwww/buildlink2.mk"

.include "../../www/apache/module.mk"
.include "../../mk/gcc.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
