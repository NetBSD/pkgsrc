# $NetBSD: Makefile,v 1.5 2005/01/27 14:10:07 ben Exp $
#

DISTNAME=		kkbswitch-1.4.3
CATEGORIES=		kde x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kkbswitch/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://kkbswitch.sourceforge.net/
COMMENT=		Keyboard layout indicator for KDE 2 or 3

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-ru-ua-layout

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
