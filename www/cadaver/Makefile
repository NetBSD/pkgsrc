# $NetBSD: Makefile,v 1.4 2001/05/22 16:09:14 jlam Exp $

DISTNAME=		cadaver-0.17.0
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/cadaver/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.webdav.org/cadaver/
COMMENT=		command-line WebDAV client

DEPENDS+=		libxml>=1.8.11:../../textproc/libxml

USE_SSL=		# defined
USE_LIBINTL=		# defined
USE_GMAKE=		# defined

ALL_TARGET=		cadaver
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURA_ARGS+=	--with-include-neon
CONFIGURE_ARGS+=	--enable-libxml
CONFIGURE_ARGS+=	--enable-netrc

.include "../../devel/libgetopt/Makefile.getopt"
.include "../../devel/readline/Makefile.readline"

CONFIGURE_ENV+=		LIBS="${LIBS}"
CONFIGURE_ENV+=		ac_cv_lib_curses_tputs=no
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tputs=no

CFLAGS+=		-I${WRKINCDIR} ${CPPFLAGS}
LDFLAGS+=		-L${WRKLIBDIR}
LIBS+=			-ltermcap

pre-configure: link-getopt-headers link-readline-headers link-readline-libs

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

.include "../../mk/bsd.pkg.mk"
