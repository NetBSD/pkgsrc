# $NetBSD: Makefile,v 1.45 2011/12/15 15:24:05 drochner Exp $

DISTNAME=		sitecopy-0.16.6
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		http://www.manyfish.co.uk/sitecopy/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.manyfish.co.uk/sitecopy/
COMMENT=		Utility for synchronizing remote and local web sites

PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES=		getopt_long
USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl
#CONFIGURE_ARGS+=	--with-included-neon
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
.include "../../www/neon/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
