# $NetBSD: Makefile,v 1.18 2003/09/23 09:05:23 wiz Exp $

DISTNAME=		sitecopy-0.13.4
CATEGORIES=		www
MASTER_SITES=		http://www.lyra.org/sitecopy/

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.lyra.org/sitecopy/
COMMENT=		Utility for synchronizing remote and local web sites

USE_GMAKE=		# defined
USE_BUILDLINK2=		# defined
USE_PKGLOCALEDIR=	# defined
BUILD_USES_MSGFMT=	# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-included-neon
CONFIGURE_ARGS+=	--with-libxml2

LIBS+=			${LIBGETOPT}

# The build process doesn't correctly find the header for GNU fnmatch, which
# is provided in ${WRKSRC}/lib.  Help the compiler by linking the header
# to ${WRKSRC} and explicitly passing -I. to the compiler.
#
CFLAGS+=		-I.

pre-build:
	${RM} -f ${WRKSRC}/fnmatch.h
	${LN} -sf ${WRKSRC}/lib/fnmatch.h ${WRKSRC}/fnmatch.h

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgetopt/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
