# $NetBSD: Makefile,v 1.23.2.1 2004/04/27 08:50:25 agc Exp $

DISTNAME=		neon-0.24.5
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/neon/

MAINTAINER=		epg@pretzelnet.org
HOMEPAGE=		http://www.webdav.org/neon/
COMMENT=		HTTP and WebDAV client library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	neon.pc.in

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=yes
CONFIGURE_ARGS+=	--with-expat
CONFIGURE_ARGS+=	--enable-shared

TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
