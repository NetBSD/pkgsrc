# $NetBSD: Makefile,v 1.10 2020/01/26 17:32:19 rillig Exp $

DISTNAME=	xtide-2.15.2
CATEGORIES=	time misc x11
MASTER_SITES=	https://flaterco.com/files/xtide/
DISTFILES=	${DISTNAME}.tar.bz2 ${HARMONICS_FILE}.bz2 wvs.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flaterco.com/
COMMENT=	X11 tide predictor
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PREV_PKGPATH=	misc/xtide

HARMONICS_FILE=	harmonics-dwf-20060708.tcd

EGDIR=		${PREFIX}/share/examples/xtide
CONF_FILES=	${EGDIR}/xtide.conf ${PKG_SYSCONFDIR}/xtide.conf

LDFLAGS.SunOS+=	-lsocket -lnsl

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	libxtide/Global.cc tide.1 xtide.1 xttpd.8
SUBST_SED.paths=	-e 's,/etc/xtide.conf,${PKG_SYSCONFDIR}/xtide.conf,'
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},'

INSTALLATION_DIRS=	share/xtide share/xtide/wvs ${EGDIR}

PLIST_SUBST+=		HARMONICS_FILE=${HARMONICS_FILE:Q}

DEPENDS+=	font-schumacher-misc>=1.1.2:../../fonts/font-schumacher-misc

post-extract:
	${ECHO} "${PREFIX}/share/xtide/${HARMONICS_FILE}" > ${WRKDIR}/xtide.conf
	${ECHO} "${PREFIX}/share/xtide/wvs" >> ${WRKDIR}/xtide.conf

post-install:
	${INSTALL_DATA} ${WRKDIR}/xtide.conf ${DESTDIR}${EGDIR}/xtide.conf
	${INSTALL_DATA} ${WRKDIR}/${HARMONICS_FILE} ${DESTDIR}${PREFIX}/share/xtide
	${INSTALL_DATA} ${WRKDIR}/wvs*.dat ${DESTDIR}${PREFIX}/share/xtide/wvs

.include "../../databases/libtcd/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXaw3d/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
