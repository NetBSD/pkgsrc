# $NetBSD: Makefile,v 1.2 2001/05/22 15:22:21 jlam Exp $

DISTNAME=		sitecopy-0.10.15
CATEGORIES=		www
MASTER_SITES=		http://www.lyra.org/sitecopy/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.lyra.org/sitecopy/
COMMENT=		utility for synchronizing remote and local web sites

DEPENDS+=		libxml>=1.8.11:../../textproc/libxml

USE_SSL=		# defined
USE_LIBINTL=		# defined
USE_GMAKE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-included-neon
CONFIGURE_ARGS+=	--enable-libxml

.include "../../devel/libgetopt/Makefile.getopt"

CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${WRKINCDIR}
CFLAGS+=		-I${WRKINCDIR}

pre-configure: link-getopt-headers

# The build process doesn't correctly find the header for GNU fnmatch, which
# is provided in ${WRKSRC}/lib.  Help the compiler by linking the header
# to ${WRKSRC} and explicitly passing -I. to the compiler.
#
CFLAGS+=		-I.

pre-build:
	${RM} -f ${WRKSRC}/fnmatch.h
	${LN} -sf ${WRKSRC}/lib/fnmatch.h ${WRKSRC}/fnmatch.h

.include "../../mk/bsd.pkg.mk"
