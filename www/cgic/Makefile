# $NetBSD: Makefile,v 1.9 2012/10/28 06:30:12 asau Exp $

DISTNAME=	cgic205
PKGNAME=	cgic-2.05
CATEGORIES=	www
MASTER_SITES=	http://www.boutell.com/cgic/

MAINTAINER=	pkgsrc@ka8zrt.com
HOMEPAGE=	http://www.boutell.com/cgic/
COMMENT=	Thomas Boutell's ANSI C library for CGI Programming

INSTALLATION_DIRS=	include lib
USE_LIBTOOL=		yes
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}

.include "../../mk/bsd.pkg.mk"
