# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:17 wiz Exp $
#

DISTNAME=	emiclock-2.0.2
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.noge.com/pub/EmiClock/X11/

MAINTAINER=	minoura@netbsd.org

USE_X11BASE=	yes
USE_IMAKE=	yes
USE_XAW=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
post-patch:
	${ECHO} "#define USE_XAW3D" > ${WRKSRC}/xawconfig.h
.else
post-patch:
	${ECHO} "#undef USE_XAW3D" > ${WRKSRC}/xawconfig.h
.endif

post-install:
	${MKDIR} ${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults
	${INSTALL_DATA} ${WRKSRC}/resources/R6/EUC/EmiClock.ad \
			${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults/EmiClock

.include "../../mk/bsd.pkg.mk"
