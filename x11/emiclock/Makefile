# $NetBSD: Makefile,v 1.5 1999/10/11 15:32:16 minoura Exp $
#

DISTNAME=	emiclock-2.0.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.noge.com/pub/EmiClock/X11/

MAINTAINER=	minoura@netbsd.org

USE_X11BASE=	yes
USE_IMAKE=	yes
USE_XAW=	yes

.include "../../mk/bsd.prefs.mk"

XAW_TYPE?=	3d

post-install:
	$(MKDIR) $(PREFIX)/lib/X11/ja_JP.eucJP/app-defaults
	$(INSTALL_DATA) $(WRKSRC)/resources/R6/EUC/EmiClock.ad \
			$(PREFIX)/lib/X11/ja_JP.eucJP/app-defaults/EmiClock

.include "../../mk/bsd.pkg.mk"
