# $NetBSD: Makefile,v 1.69 2016/07/09 06:39:13 wiz Exp $

DISTNAME=	neon-0.30.1
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.webdav.org/neon/
COMMENT=	HTTP and WebDAV client library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-expat
CONFIGURE_ARGS+=	--with-ssl=yes

PKGCONFIG_OVERRIDE=	neon.pc.in
TEST_TARGET=		check
#selftest needs perl
USE_TOOLS+=		perl

LDFLAGS.SunOS+=		-lintl

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
