# $NetBSD: Makefile,v 1.13 2002/02/28 18:23:57 jlam Exp $

DISTNAME=		cadaver-0.19.1
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/cadaver/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.webdav.org/cadaver/
COMMENT=		command-line WebDAV client

USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES

ALL_TARGET=		cadaver
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-netrc
CONFIGURE_ARGS+=	--with-included-neon
CONFIGURE_ARGS+=	--with-libxml1
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}

# We don't need curses, just termcap.
CONFIGURE_ENV+=		ac_cv_lib_curses_tputs=no
LIBS+=			-ltermcap

# The build process doesn't correctly find some headers for utility functions
# which are provided in ${WRKSRC}/lib.  Help the compiler by linking the
# headers to ${WRKSRC} and explicitly passing -I. to the compiler.
#
CFLAGS+=		-I.

pre-build:
	${RM} -f ${WRKSRC}/glob.h
	${LN} -sf ${WRKSRC}/lib/glob.h ${WRKSRC}/glob.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/cadaver.1 ${PREFIX}/man/man1

.include "../../devel/readline/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
