# $NetBSD: Makefile,v 1.22 2003/07/22 04:14:21 martti Exp $

DISTNAME=		cadaver-0.21.0
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/cadaver/

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.webdav.org/cadaver/
COMMENT=		Command-line WebDAV client

USE_BUILDLINK2=		YES

ALL_TARGET=		cadaver
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-netrc

# We don't need curses, just termcap.
CONFIGURE_ENV+=		ac_cv_lib_curses_tputs=no
LIBS+=			-ltermcap

.include "../../devel/readline/buildlink2.mk"
.include "../../www/neon/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
