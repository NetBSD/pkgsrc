# $NetBSD: Makefile,v 1.15 2003/01/30 12:14:32 drochner Exp $

DISTNAME=		cadaver-0.20.5
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/cadaver/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.webdav.org/cadaver/
COMMENT=		command-line WebDAV client

USE_GMAKE=		YES
USE_BUILDLINK2=		YES

ALL_TARGET=		cadaver
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-netrc
CONFIGURE_ARGS+=	--with-libxml1
CONFIGURE_ARGS+=	--with-ssl=yes

# We don't need curses, just termcap.
CONFIGURE_ENV+=		ac_cv_lib_curses_tputs=no
LIBS+=			-ltermcap

.include "../../devel/readline/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../www/neon/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
