# $NetBSD: Makefile,v 1.27 2004/04/24 22:46:13 jlam Exp $

DISTNAME=		sitecopy-0.13.4
PKGREVISION=		4
CATEGORIES=		www
MASTER_SITES=		http://www.lyra.org/sitecopy/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.lyra.org/sitecopy/
COMMENT=		Utility for synchronizing remote and local web sites

BUILD_USES_MSGFMT=	# defined

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-included-neon
CONFIGURE_ARGS+=	--with-libxml2

# The build process doesn't correctly find the header for GNU fnmatch, which
# is provided in ${WRKSRC}/lib.  Help the compiler by linking the header
# to ${WRKSRC} and explicitly passing -I. to the compiler.
#
CFLAGS+=		-I.

pre-build:
	${RM} -f ${WRKSRC}/fnmatch.h
	${LN} -sf ${WRKSRC}/lib/fnmatch.h ${WRKSRC}/fnmatch.h

.if !exists(/usr/include/getopt.h)
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
