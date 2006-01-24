# $NetBSD: Makefile,v 1.33 2006/01/24 07:32:49 wiz Exp $

DISTNAME=		neon-0.25.5
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/neon/

MAINTAINER=		epg@NetBSD.org
HOMEPAGE=		http://www.webdav.org/neon/
COMMENT=		HTTP and WebDAV client library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	neon.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=yes
CONFIGURE_ARGS+=	--with-expat
CONFIGURE_ARGS+=	--enable-shared

TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
