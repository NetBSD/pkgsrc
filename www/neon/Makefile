# $NetBSD: Makefile,v 1.1.1.1 2002/01/13 19:29:02 agc Exp $

DISTNAME=		neon-0.18.3
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/neon/

MAINTAINER=		epg@pretzelnet.org
HOMEPAGE=		http://www.webdav.org/neon/
COMMENT=		HTTP and WebDAV client library

USE_GMAKE=		# defined
USE_BUILDLINK_ONLY=	# defined

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--enable-libxml
CONFIGURE_ARGS+=	--enable-shared

.include "../../devel/zlib/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
