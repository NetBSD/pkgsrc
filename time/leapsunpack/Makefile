# $NetBSD: Makefile,v 1.11 2025/05/22 04:51:29 schmonz Exp $

DISTNAME=		leapsunpack-0.06
CATEGORIES=		time
MASTER_SITES=		https://su.bze.ro/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://su.bze.ro/software.html
COMMENT=		Creates libtai leapsecs.dat from compressed table

DEPENDS+=		libtai-[0-9]*:../../devel/libtai

LDFLAGS.SunOS+=		-lsocket -lnsl

DJB_ERRNO_FIXUP=	error.h

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_FILES.files=	leapsinstall.sh
SUBST_VARS.files=	PKG_SYSCONFDIR
SUBST_MESSAGE.files=	Fixing configuration files.

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	for i in leaps2zic leapsunpack; do \
	  ${INSTALL_PROGRAM} ${WRKSRC}/$${i} ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/leapsinstall ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
