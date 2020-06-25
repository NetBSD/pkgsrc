# $NetBSD: Makefile,v 1.8 2020/06/25 05:42:39 schmonz Exp $
#

DISTNAME=		leapsunpack-0.05
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		schmonz@NetBSD.org
#HOMEPAGE=		http://su.bze.ro/software/
COMMENT=		Creates libtai leapsecs.dat from compressed table

DEPENDS+=		libtai-[0-9]*:../../devel/libtai

DJB_RESTRICTED=		no

LDFLAGS.SunOS+=		-lsocket -lnsl

SUBST_CLASSES+=		djberrno

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_FILES.files=	leapsinstall.sh
SUBST_VARS.files=	PKG_SYSCONFDIR
SUBST_MESSAGE.files=	Fixing configuration files.

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/leapsunpack ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/leapsinstall ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
