# $NetBSD: Makefile,v 1.10 2014/04/07 15:01:44 adam Exp $

DISTNAME=	cgic206
PKGNAME=	cgic-2.06
CATEGORIES=	www
MASTER_SITES=	http://www.boutell.com/cgic/

MAINTAINER=	pkgsrc@ka8zrt.com
HOMEPAGE=	http://www.boutell.com/cgic/
COMMENT=	Thomas Boutell's ANSI C library for CGI Programming

INSTALLATION_DIRS=	include lib
USE_LIBTOOL=		yes
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}

.include "../../mk/bsd.pkg.mk"
