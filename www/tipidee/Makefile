# $NetBSD: Makefile,v 1.11 2025/07/08 21:19:18 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		tipidee-0.0.6.0
PKGREVISION=		2
MANPAGES_VERSION=	0.0.5.0.1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=skarnet/}
GITHUB_PROJECT=		tipidee
GITHUB_TAG=		9acee22dd82472bf408204a066476334c3568e87
MANPAGES_DIST=		tipidee-man-pages-${MANPAGES_VERSION}.tar.gz
DISTFILES=		${_GITHUB_DEFAULT_DISTFILES} ${MANPAGES_DIST}
SITES.${MANPAGES_DIST}=	-https://git.sr.ht/~flexibeast/${PKGBASE}-man-pages/archive/v${MANPAGES_VERSION}.tar.gz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/tipidee/
COMMENT=		Minimalistic web server
LICENSE=		isc

TOOL_DEPENDS+=		coreutils-[0-9]*:../../sysutils/coreutils
DEPENDS+=		s6-networking>=2.7.1.0nb1:../../net/s6-networking

WRKMANSRC=		${WRKDIR}/${PKGBASE}-man-pages-v${MANPAGES_VERSION}

USE_TOOLS+=		gmake
TOOLS_PLATFORM.install=	${PREFIX}/bin/ginstall
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-pkgconfig
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-allstatic

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	pre-configure
SUBST_FILES.sysconfdir=	${WRKMANSRC}/man*/*
SUBST_SED.sysconfdir=	-e 's|/etc/tipidee|${PKG_SYSCONFDIR}/tipidee|g'

EGDIR=			share/examples/${PKGBASE}
CONF_FILES+=		${PREFIX}/${EGDIR}/tipidee.conf \
			${PKG_SYSCONFDIR}/tipidee.conf

INSTALL_DIRS+=		. ${WRKMANSRC}
INSTALL_ENV+=		PREFIX=${PREFIX:Q} MAN_DIR=${PREFIX:Q}/${PKGMANDIR:Q}

INSTALLATION_DIRS+=	${EGDIR}

.PHONY: do-install-examples
post-install: do-install-examples
do-install-examples:
	cd ${WRKSRC}/examples; for i in tipidee.conf; do \
		${INSTALL_DATA} $$i \
		${DESTDIR}${PREFIX}/${EGDIR}/$$i; \
	done

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
