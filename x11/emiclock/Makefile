# $NetBSD: Makefile,v 1.7 2000/07/14 05:06:37 minoura Exp $
#

DISTNAME=	emiclock-2.0.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.noge.com/pub/EmiClock/X11/

MAINTAINER=	minoura@netbsd.org

USE_X11BASE=	yes
USE_IMAKE=	yes
USE_XAW=	yes

.include "../../mk/bsd.prefs.mk"

.if (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
post-patch:
	echo "#define USE_XAW3D" > ${WRKSRC}/xawconfig.h
.else
post-patch:
	echo "#undef USE_XAW3D" > ${WRKSRC}/xawconfig.h
.endif

post-install:
	${MKDIR} ${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults
	${INSTALL_DATA} ${WRKSRC}/resources/R6/EUC/EmiClock.ad \
			${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults/EmiClock

.include "../../mk/bsd.pkg.mk"
