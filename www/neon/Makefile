# $NetBSD: Makefile,v 1.2.2.1 2002/07/01 17:45:14 jlam Exp $

DISTNAME=		neon-0.19.3
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/neon/

MAINTAINER=		epg@pretzelnet.org
HOMEPAGE=		http://www.webdav.org/neon/
COMMENT=		HTTP and WebDAV client library

USE_GMAKE=		# defined
USE_BUILDLINK2=		# defined

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-libxml1
CONFIGURE_ARGS+=	--enable-shared

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
