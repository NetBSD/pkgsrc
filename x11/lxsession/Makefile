# $NetBSD: Makefile,v 1.21 2018/11/14 22:22:46 kleink Exp $

DISTNAME=	lxsession-0.5.3
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://lxde.org/
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

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	lxsession/environement.c
SUBST_FILES.prefix+=	lxsession/app.c
SUBST_FILES.prefix+=	lxsession/settings.c
SUBST_FILES.prefix+=	lxsession-db/desktop-files-backend.c
SUBST_FILES.prefix+=	data/desktop.conf.example
SUBST_SED.prefix=	-e 's,/etc/xdg,${PKG_SYSCONFDIR},g'
SUBST_SED.prefix+=	-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.prefix+=	-e 's,/usr/lib,${PREFIX}/lib,g'
SUBST_SED.prefix+=	-e 's,/usr/bin/pkexec,${PREFIX}/bin/pkexec,g'

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
