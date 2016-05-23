# $NetBSD: Makefile,v 1.11 2016/05/23 08:56:21 youri Exp $

DISTNAME=	lxsession-0.5.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://lxde.org/
COMMENT=	Session manager for LXDE
LICENSE=	gnu-gpl-v2

LXDE_CONF=		share/examples/lxsession
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	share/doc/lxsession
USE_TOOLS+=		intltool msgfmt pkg-config

PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${PKG_SYSCONFDIR}/autostart

CONF_FILES+=	${LXDE_CONF}/lxpolkit.desktop \
		${PKG_SYSCONFDIR}/autostart/lxpolkit.desktop

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/lxsession/

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
