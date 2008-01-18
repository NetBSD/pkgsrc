# $NetBSD: Makefile,v 1.43 2008/01/18 05:09:52 tnn Exp $

# Note: when upgrading neon to >=0.27, make sure that subversion still
# works. 1.4.5 does not.
DISTNAME=	neon-0.26.3
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://www.webdav.org/neon/
COMMENT=	HTTP and WebDAV client library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-expat
CONFIGURE_ARGS+=	--with-ssl=yes

PKGCONFIG_OVERRIDE=	neon.pc.in
TEST_TARGET=		check

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
