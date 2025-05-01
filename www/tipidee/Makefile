# $NetBSD: Makefile,v 1.8 2025/05/01 16:12:13 schmonz Exp $

DISTNAME=		tipidee-0.0.5.1
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		${HOMEPAGE}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${MANPAGES_DIST}
# man-pages version is usually not exactly in-sync with PKGVERSION_NOREV
MANPAGES_VERSION=	0.0.5.0.1
MANPAGES_DIST=		tipidee-man-pages-${MANPAGES_VERSION}.tar.gz
SITES.${MANPAGES_DIST}=	-https://git.sr.ht/~flexibeast/tipidee-man-pages/archive/v${MANPAGES_VERSION}.tar.gz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/tipidee/
COMMENT=		Minimalistic web server
LICENSE=		isc

DEPENDS+=		s6-networking>=2.7.0.4:../../net/s6-networking

WRKMANSRC=		${WRKDIR}/${PKGBASE}-man-pages-v${MANPAGES_VERSION}

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	pre-configure
SUBST_FILES.sysconfdir=	${WRKMANSRC}/man*/*
SUBST_SED.sysconfdir=	-e 's|/etc/tipidee|/etc/pkg/tipidee|g'

EGDIR=			share/examples/${PKGBASE}
CONF_FILES+=		${PREFIX}/${EGDIR}/tipidee.conf \
			${PKG_SYSCONFDIR}/tipidee.conf

INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man7 ${PKGMANDIR}/man8

INSTALL_DIRS+=		. ${WRKMANSRC}
INSTALL_ENV+=		PREFIX=${PREFIX:Q} MAN_DIR=${PREFIX:Q}/${PKGMANDIR:Q}

# 0.0.5.1 tipidee-config dumps core, reported upstream
BUILDLINK_TRANSFORM.NetBSD+=	rm:-fstack-check

.PHONY: do-install-examples
post-install: do-install-examples
do-install-examples:
	cd ${WRKSRC}/examples; for i in tipidee.conf; do \
		${INSTALL_DATA} $$i \
		${DESTDIR}${PREFIX}/${EGDIR}/$$i; \
	done

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
