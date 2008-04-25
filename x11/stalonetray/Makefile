# $NetBSD: Makefile,v 1.4 2008/04/25 15:04:32 smb Exp $
#
DISTNAME=stalonetray-0.7.6
CATEGORIES=x11
MASTER_SITES=${MASTER_SITE_SOURCEFORGE:=stalonetray/}
PKGREVISION=	1

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://stalonetray.sourceforge.net/
COMMENT=	Stand-alone system tray

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-native-kde
USE_LANGUAGES+=	c

INSTALLATION_DIRS=	share/examples

post-install:
	${INSTALL_DATA} ${WRKSRC}/stalonetrayrc.sample ${DESTDIR}${PREFIX}/share/examples/stalonetray.rc

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
