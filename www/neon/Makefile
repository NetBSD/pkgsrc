# $NetBSD: Makefile,v 1.15 2003/09/23 12:18:57 recht Exp $

DISTNAME=		neon-0.24.1
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/neon/

MAINTAINER=		epg@pretzelnet.org
HOMEPAGE=		http://www.webdav.org/neon/
COMMENT=		HTTP and WebDAV client library

USE_BUILDLINK2=		# defined

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	neon.pc.in

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=yes
CONFIGURE_ARGS+=	--with-expat
CONFIGURE_ARGS+=	--enable-shared

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
