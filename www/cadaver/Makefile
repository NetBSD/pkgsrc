# $NetBSD: Makefile,v 1.11 2001/08/20 03:55:32 jlam Exp $

DISTNAME=		cadaver-0.17.0
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/cadaver/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.webdav.org/cadaver/
COMMENT=		command-line WebDAV client

USE_GMAKE=		# defined
USE_BUILDLINK_ONLY=	# defined

ALL_TARGET=		cadaver
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-include-neon
CONFIGURE_ARGS+=	--enable-libxml
CONFIGURE_ARGS+=	--enable-netrc

LIBS+=			${LIBGETOPT}

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

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/libgetopt/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
