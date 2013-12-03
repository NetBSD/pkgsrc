# $NetBSD: Makefile,v 1.20 2013/12/03 15:23:51 adam Exp $

DISTNAME=	squid-3.3.11
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v3/${PKGVERSION_NOREV:R}/ \
		${SQUID_MASTER_SITES}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:run gmake
GNU_CONFIGURE=		yes

.include "../../www/squid/Makefile.squid"

CONFIGURE_ARGS+=	--disable-strict-error-checking
CONFIGURE_ARGS+=	--enable-auth
CONFIGURE_ARGS+=	--enable-icap-client
CONFIGURE_ARGS+=	--with-default-user=${SQUID_USER}
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/squid.pid

BUILD_DEFS+=		VARBASE
REPLACE_PERL+=		tools/helper-mux.pl

EGFILES+=	errors/errorpage.css
CONF_FILES+=	${PREFIX}/${EGDIR}/errorpage.css ${PKG_SYSCONFDIR}/errorpage.css

SQUID_BACKENDS?=	ufs
SQUID_NTLM_AUTH_HELPERS?= fakeauth
.include "options.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-[0-5]*-i386)
GNU_ARCH.i386=	i486
CFLAGS+=	-march=i486
.endif

post-build:
	cd ${WRKSRC}/src && ${CP} -pf squid.conf.documented squid.conf.default

.include "../../mk/bsd.pkg.mk"
