# $NetBSD: Makefile,v 1.34 2006/02/21 05:54:43 hiramatsu Exp $

DISTNAME=		sitecopy-0.16.2
CATEGORIES=		www
MASTER_SITES=		http://www.lyra.org/sitecopy/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.lyra.org/sitecopy/
COMMENT=		Utility for synchronizing remote and local web sites

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--with-included-neon
CONFIGURE_ARGS+=	--with-libxml2

# The build process doesn't correctly find the header for GNU fnmatch, which
# is provided in ${WRKSRC}/lib.  Help the compiler by linking the header
# to ${WRKSRC} and explicitly passing -I. to the compiler.
#
CFLAGS+=		-I.

pre-build:
	${RM} -f ${WRKSRC:Q}/fnmatch.h
	${LN} -sf ${WRKSRC:Q}/lib/fnmatch.h ${WRKSRC:Q}/fnmatch.h

.if !exists(/usr/include/getopt.h)
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
