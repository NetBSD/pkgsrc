# $NetBSD: Makefile,v 1.18 2024/05/08 18:35:49 spz Exp $

DISTNAME=	Pound-2.8
PKGNAME=	${DISTNAME:S/Pound/pound/}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.apsis.ch/pound/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.apsis.ch/pound.html
COMMENT=	Reverse proxy, load balancer and HTTPS front-end
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_FEATURES.openssl=	threads

RCD_SCRIPTS=		pound

SUBST_CLASSES=		config
SUBST_MESSAGE.config=	Fixing path to default config file.
SUBST_STAGE.config=	post-build
SUBST_FILES.config=	pound.8
SUBST_SED.config=	-e "s,/usr/local/etc/,"${PKG_SYSCONFDIR}"/,g"

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man8

# OpenSSL removed the dhparam -C option in 3.0, and the call hangs
# for some reason on i386
NOT_FOR_BULK_PLATFORM   += NetBSD-10.0-*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pound \
		${DESTDIR}${PREFIX}/sbin/pound
	${INSTALL_PROGRAM} ${WRKSRC}/poundctl \
		${DESTDIR}${PREFIX}/sbin/poundctl
	${INSTALL_MAN} ${WRKSRC}/pound.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/pound.8
	${INSTALL_MAN} ${WRKSRC}/poundctl.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/poundctl.8

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
