# $NetBSD: Makefile,v 1.13 2003/05/25 09:35:28 epg Exp $

DISTNAME=		neon-0.23.9
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/neon/

MAINTAINER=		epg@pretzelnet.org
HOMEPAGE=		http://www.webdav.org/neon/
COMMENT=		HTTP and WebDAV client library

USE_BUILDLINK2=		# defined

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=yes
CONFIGURE_ARGS+=	--with-expat
CONFIGURE_ARGS+=	--enable-shared

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
