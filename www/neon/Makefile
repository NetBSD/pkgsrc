# $NetBSD: Makefile,v 1.58 2013/02/06 23:20:54 jperkin Exp $

DISTNAME=	neon-0.29.6
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.webdav.org/neon/
COMMENT=	HTTP and WebDAV client library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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

post-build:
	cd ${WRKSRC}/doc/man && \
	for i in ne_*3; do \
		if grep -q '^.so ' $$i >/dev/null; then \
			sed -e "s_.so _.so man3/_" $$i > $$i.new && mv $$i.new $$i; \
		fi; \
	done

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
