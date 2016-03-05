# $NetBSD: Makefile,v 1.9 2016/03/05 11:29:35 jperkin Exp $

DISTNAME=	c_icap_modules-0.3.2
PKGNAME=	${DISTNAME:S/_/-/g}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=c-icap/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://c-icap.sourceforge.net/
COMMENT=	C-ICAP server modules
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-c-icap=${BUILDLINK_PREFIX.c-icap}

EGDIR=		${PREFIX}/share/c-icap
CONF_FILES=	${EGDIR}/srv_url_check.conf.default ${PKG_SYSCONFDIR}/srv_url_check.conf

INSTALLATION_DIRS=	etc share/c-icap

post-install:
	${FIND} ${DESTDIR}${PREFIX}/share/c_icap/templates -type f -exec ${CHMOD} -x {} \;

.include "options.mk"

.include "../../www/c-icap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
