# $NetBSD: Makefile,v 1.10 2020/01/18 23:35:56 rillig Exp $
#
DISTNAME=	stalonetray-0.8.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stalonetray/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stalonetray.sourceforge.net/
COMMENT=	Stand-alone system tray
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-native-kde
USE_LANGUAGES+=		c

INSTALLATION_DIRS=	share/examples

post-install:
	${INSTALL_DATA} ${WRKSRC}/stalonetrayrc.sample ${DESTDIR}${PREFIX}/share/examples/stalonetray.rc

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
