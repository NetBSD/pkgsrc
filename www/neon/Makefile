# $NetBSD: Makefile,v 1.9 2003/05/02 11:56:44 wiz Exp $

DISTNAME=		neon-0.23.7
PKGREVISION=	1
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
CONFIGURE_ARGS+=	--with-ssl=yes
CONFIGURE_ARGS+=	--with-libxml2
CONFIGURE_ARGS+=	--enable-shared

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
