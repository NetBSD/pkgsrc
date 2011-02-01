# $NetBSD: Makefile,v 1.5 2011/02/01 04:38:11 schnoebe Exp $
#
DISTNAME=stalonetray-0.8.1
CATEGORIES=x11
MASTER_SITES=${MASTER_SITE_SOURCEFORGE:=stalonetray/}

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://stalonetray.sourceforge.net/
COMMENT=	Stand-alone system tray
LICENSE=	gnu-gpl-v2

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
