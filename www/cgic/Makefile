# $NetBSD: Makefile,v 1.8 2012/02/16 19:58:58 hans Exp $

DISTNAME=	cgic205
PKGNAME=	cgic-2.05
CATEGORIES=	www
MASTER_SITES=	http://www.boutell.com/cgic/

MAINTAINER=	pkgsrc@ka8zrt.com
HOMEPAGE=	http://www.boutell.com/cgic/
COMMENT=	Thomas Boutell's ANSI C library for CGI Programming

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	include lib
USE_LIBTOOL=		yes
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}

.include "../../mk/bsd.pkg.mk"
