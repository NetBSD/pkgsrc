# $NetBSD: Makefile,v 1.98 2024/05/16 06:15:42 wiz Exp $

DISTNAME=	neon-0.33.0
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
CONFIGURE_ARGS+=	--with-ca-bundle=${SSLCERTS:Q}/ca-certificates.crt

PKGCONFIG_OVERRIDE=	neon.pc.in
TEST_TARGET=		check
#selftest needs perl
USE_TOOLS+=		perl

# Logic borrowed from security/mozilla-rootcerts
CHECK_BUILTIN.openssl=	yes
.include "../../security/openssl/buildlink3.mk"
CHECK_BUILTIN.openssl=	no
.if ${USE_BUILTIN.openssl:U:tl} == yes
SSLDIR=		/etc/openssl
.else
SSLDIR=		${PKG_SYSCONFDIR}/openssl
.endif

SSLCERTS=		${SSLDIR}/certs
SUBST_CLASSES=		paths
SUBST_MESSAGE.paths=	Setting CA bundle path in README.pkgsrc
SUBST_STAGE.paths=	post-build
SUBST_FILES.paths=	README.pkgsrc
SUBST_VARS.paths=	SSLCERTS

DOCDIR=		${PREFIX}/share/doc/${PKGNAME_NOREV}
INSTALLATION_DIRS=	${DOCDIR}

post-extract:
	${CP} ${FILESDIR}/README.pkgsrc ${WRKSRC} || ${TRUE};

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.pkgsrc ${DESTDIR}${DOCDIR};

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
