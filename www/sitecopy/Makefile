# $NetBSD: Makefile,v 1.39 2008/01/18 05:09:53 tnn Exp $

DISTNAME=		sitecopy-0.16.2
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://www.lyra.org/sitecopy/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lyra.org/sitecopy/
COMMENT=		Utility for synchronizing remote and local web sites

USE_FEATURES=		getopt_long
USE_TOOLS+=		gmake msgfmt
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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
