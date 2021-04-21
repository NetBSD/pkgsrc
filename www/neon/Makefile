# $NetBSD: Makefile,v 1.79 2021/04/21 13:24:18 adam Exp $

DISTNAME=	neon-0.31.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://notroj.github.io/neon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://notroj.github.io/neon/
COMMENT=	HTTP and WebDAV client library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-expat

PKGCONFIG_OVERRIDE=	neon.pc.in
TEST_TARGET=		check
#selftest needs perl
USE_TOOLS+=		perl

LDFLAGS.SunOS+=		-lintl

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
