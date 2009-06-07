# $NetBSD: Makefile,v 1.6 2009/06/07 08:36:36 tron Exp $

DISTNAME=	squid-3.1.0.8
PKGNAME=	${DISTNAME}	# Necessary for "pkgsrc/www/squid/options.mk"
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v3/3.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake
GNU_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	destdir

.include "../../www/squid/Makefile.squid"

CONFIGURE_ARGS+=	--with-default-user=${SQUID_USER}
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/squid.pid

EGFILES+=     errors/errorpage.css
CONF_FILES+=  ${PREFIX}/${EGDIR}/errorpage.css ${PKG_SYSCONFDIR}/errorpage.css

SQUID_BACKENDS?=           ufs
SQUID_NTLM_AUTH_HELPERS?=  fakeauth
.include "../../www/squid/options.mk"

post-build:
	${CP} -pf ${WRKSRC}/src/squid.conf.documented \
	  ${WRKSRC}/src/squid.conf.default

.include "../../mk/bsd.pkg.mk"
