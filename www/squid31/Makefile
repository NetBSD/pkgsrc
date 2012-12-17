# $NetBSD: Makefile,v 1.42 2012/12/17 14:42:54 tron Exp $

DISTNAME=	squid-3.1.22
PKGNAME=	${DISTNAME}	# Necessary for "pkgsrc/www/squid/options.mk"
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v3/3.1/ \
		${SQUID_MASTER_SITES}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake
GNU_CONFIGURE=		yes

.include "../../www/squid/Makefile.squid"

CONFIGURE_ARGS+=	--disable-strict-error-checking
CONFIGURE_ARGS+=	--enable-auth=basic,digest,ntlm
CONFIGURE_ARGS+=	--enable-icap-client
CONFIGURE_ARGS+=	--with-default-user=${SQUID_USER}
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/squid.pid

EGFILES+=	errors/errorpage.css
CONF_FILES+=	${PREFIX}/${EGDIR}/errorpage.css ${PKG_SYSCONFDIR}/errorpage.css

SQUID_BACKENDS?=	ufs
SQUID_NTLM_AUTH_HELPERS?= fakeauth
.include "../../www/squid/options.mk"

post-build:
	cd ${WRKSRC}/src && ${CP} -pf squid.conf.documented squid.conf.default

.include "../../mk/bsd.pkg.mk"
