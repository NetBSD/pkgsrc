# $NetBSD: Makefile,v 1.20 2003/05/25 10:14:23 epg Exp $

DISTNAME=		cadaver-0.21.0
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/cadaver/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.webdav.org/cadaver/
COMMENT=		command-line WebDAV client

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
