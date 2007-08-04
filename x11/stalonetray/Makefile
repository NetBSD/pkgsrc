# $NetBSD: Makefile,v 1.1 2007/08/04 13:44:20 smb Exp $
#
DISTNAME=stalonetray-0.6.5
CATEGORIES=x11
MASTER_SITES=${MASTER_SITE_SOURCEFORGE:=stalonetray/}

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://stalonetray.sourceforge.net/
COMMENT=	Stand-alone system tray

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-native-kde
USE_LANGUAGES+=	c

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/stalonetrayrc.sample  ${PREFIX}/share/examples/stalonetray.rc

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
