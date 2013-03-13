# $NetBSD: Makefile,v 1.5 2013/03/13 17:11:25 taca Exp $

DISTNAME=	squid-3.3.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v3/${PKGVERSION_NOREV:R}/ \
		${SQUID_MASTER_SITES}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake
GNU_CONFIGURE=		yes

.include "../../www/squid/Makefile.squid"

CONFIGURE_ARGS+=	--disable-strict-error-checking
CONFIGURE_ARGS+=	--enable-auth
CONFIGURE_ARGS+=	--enable-icap-client
CONFIGURE_ARGS+=	--with-default-user=${SQUID_USER}
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/squid.pid

REPLACE_PERL+=		tools/helper-mux.pl

EGFILES+=	errors/errorpage.css
CONF_FILES+=	${PREFIX}/${EGDIR}/errorpage.css ${PKG_SYSCONFDIR}/errorpage.css

SQUID_BACKENDS?=	ufs
SQUID_NTLM_AUTH_HELPERS?= fakeauth
.include "options.mk"

post-build:
	cd ${WRKSRC}/src && ${CP} -pf squid.conf.documented squid.conf.default

.include "../../mk/bsd.pkg.mk"
