# $NetBSD: Makefile,v 1.47 2014/02/12 23:18:44 tron Exp $

DISTNAME=		cadaver-0.23.3
PKGREVISION=		3
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/cadaver/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.webdav.org/cadaver/
COMMENT=		Command-line WebDAV client

BUILD_TARGET=		cadaver
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--enable-netrc
CONFIGURE_ARGS+=	--with-expat
#CONFIGURE_ARGS+=	--with-included-neon
CONFIGURE_ARGS+=	--with-ssl=yes
LIBS+=			${BUILDLINK_LDADD.termcap}

#INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR:Q}${PREFIX:Q}/bin		\
#			mandir=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}

.include "../../mk/readline.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
# DON'T make this package depend on the www/neon package until neon
# becomes stable; keep it using its internal copy of neon as with
# www/sitecopy.  This package has in the past bounced back and forth
# between using external and internal neon because neon moves faster
# than cadaver, and does so incompatibly.

.include "../../mk/bsd.pkg.mk"
