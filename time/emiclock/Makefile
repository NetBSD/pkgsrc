# $NetBSD: Makefile,v 1.9 2004/04/25 04:52:18 snj Exp $
#

DISTNAME=	emiclock-2.0.2
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.noge.com/pub/EmiClock/X11/

MAINTAINER=	minoura@NetBSD.org
COMMENT=	Analog clock with image in the middle

LICENSE=	emiclock-license
RESTRICTED=	"Do not distribute"
NO_SRC_ON_FTP=${RESTRICTED}
NO_BIN_ON_FTP=${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

USE_BUILDLINK3=	yes
USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
post-patch:
	${ECHO} "#define USE_XAW3D" > ${WRKSRC}/xawconfig.h
.else
post-patch:
	${ECHO} "#undef USE_XAW3D" > ${WRKSRC}/xawconfig.h
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults
	${INSTALL_DATA} ${WRKSRC}/resources/R6/EUC/EmiClock.ad \
		${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults/EmiClock

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
