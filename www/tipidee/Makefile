# $NetBSD: Makefile,v 1.1 2023/11/11 11:58:45 schmonz Exp $

DISTNAME=		tipidee-0.0.1.0
CATEGORIES=		www
MASTER_SITES=		${HOMEPAGE}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${MANPAGES_DIST}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/tipidee/
COMMENT=		Minimalistic web server
LICENSE=		isc

# man-pages version is usually not exactly in-sync with PKGVERSION_NOREV
MANPAGES_VERSION=	0.0.1.0.1
MANPAGES_DIST=		tipidee-man-pages-${MANPAGES_VERSION}.tar.gz
SITES.${MANPAGES_DIST}=	-https://git.sr.ht/~flexibeast/tipidee-man-pages/archive/v${MANPAGES_VERSION}.tar.gz

DEPENDS+=		s6-networking-[0-9]*:../../net/s6-networking

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALLATION_DIRS+=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8

.PHONY: do-install-manpages
post-install: do-install-manpages
do-install-manpages:
	cd ${WRKDIR}/${PKGBASE}-man-pages-*; for i in 5 8; do \
		for j in man$$i/*.$$i; do \
			${INSTALL_MAN} $$j \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; \
		done \
	done

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
