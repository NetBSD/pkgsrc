# $NetBSD: Makefile,v 1.11 2003/02/17 17:57:19 grant Exp $

DISTNAME=	modxslt
PKGNAME=	ap-xslt-1.1
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/modxslt/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://modxslt.sourceforge.net/
COMMENT=	Simple, fast XSLT transformations for apache

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_xslt.so
APACHE_MODULE_SRC=	*.c

.include "../../textproc/sablotron/buildlink2.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
