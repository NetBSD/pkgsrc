# $NetBSD: Makefile,v 1.10 2001/08/20 03:55:32 jlam Exp $

DISTNAME=		sitecopy-0.10.15
CATEGORIES=		www
MASTER_SITES=		http://www.lyra.org/sitecopy/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.lyra.org/sitecopy/
COMMENT=		utility for synchronizing remote and local web sites

USE_GMAKE=		# defined
USE_BUILDLINK_ONLY=	# defined
BUILD_USES_MSGFMT=	# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-included-neon
CONFIGURE_ARGS+=	--enable-libxml

LIBS+=			${LIBGETOPT}

# The build process doesn't correctly find the header for GNU fnmatch, which
# is provided in ${WRKSRC}/lib.  Help the compiler by linking the header
# to ${WRKSRC} and explicitly passing -I. to the compiler.
#
CFLAGS+=		-I.

pre-build:
	${RM} -f ${WRKSRC}/fnmatch.h
	${LN} -sf ${WRKSRC}/lib/fnmatch.h ${WRKSRC}/fnmatch.h

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/libgetopt/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
