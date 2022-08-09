# $NetBSD: Makefile,v 1.87 2022/08/09 12:08:32 jperkin Exp $

DISTNAME=	neon-0.32.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://notroj.github.io/neon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://notroj.github.io/neon/
COMMENT=	HTTP and WebDAV client library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-expat

PKGCONFIG_OVERRIDE=	neon.pc.in
TEST_TARGET=		check
#selftest needs perl
USE_TOOLS+=		perl

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
