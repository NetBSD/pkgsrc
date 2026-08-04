# $NetBSD: Makefile,v 1.12 2026/08/04 20:29:19 wiz Exp $

DISTNAME=	cgic206
PKGNAME=	cgic-2.06
CATEGORIES=	www
MASTER_SITES=	http://www.boutell.com/cgic/

MAINTAINER=	pkgsrc@ka8zrt.com
HOMEPAGE=      https://github.com/boutell/cgic
COMMENT=	Thomas Boutell's ANSI C library for CGI Programming

INSTALLATION_DIRS=	include lib
USE_LIBTOOL=		yes
MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
