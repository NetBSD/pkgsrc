# $NetBSD: Makefile,v 1.3 1999/06/10 15:29:11 hubertf Exp $
#

DISTNAME=	emiclock-1.0.4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.plaza.hitachi-sk.co.jp/pub/EmiClock/X11/

MAINTAINER=	minoura@netbsd.org

DEPENDS=	Xaw3d-1.5:../../x11/Xaw3d

USE_X11BASE=	YES
USE_IMAKE=	YES

post-install:
	$(MKDIR) $(PREFIX)/lib/X11/ja_JP.eucJP/app-defaults
	$(INSTALL_DATA) $(WRKSRC)/resources/R6/EUC/EmiClock.ad \
			$(PREFIX)/lib/X11/ja_JP.eucJP/app-defaults/EmiClock

.include "../../mk/bsd.pkg.mk"
