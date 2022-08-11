# $NetBSD: Makefile,v 1.8 2022/08/11 05:09:29 gutteridge Exp $

DISTNAME=	gdm-40.0
PKGNAME=	lib${DISTNAME}
PKGREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}
GITHUB_PROJECT=	gdm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Gnome Display Manager - client library
LICENSE=	gnu-gpl-v2

DEPENDS+=	zenity>=3.32.0:../../x11/zenity

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		msgfmt pkg-config gdbus-codegen itstool
BUILD_DEFS+=		VARBASE

USE_LANGUAGES=		c c++

CPPFLAGS+=		-DWITH_CONSOLE_KIT=1
CPPFLAGS+=		-DCONSOLEKIT_DIR=\"${PREFIX}/libexec\"

MESON_ARGS+=		-Dlocalstatedir=${VARBASE}
MESON_ARGS+=		--sysconfdir=${EGDIR}
MESON_ARGS+=		-Ddmconfdir=${PKG_SYSCONFDIR}/dm
MESON_ARGS+=		-Dsysconfsubdir=
MESON_ARGS+=		-Dplymouth=disabled
MESON_ARGS+=		-Dsystemd-journal=false
MESON_ARGS+=		-Duser-display-server=false
MESON_ARGS+=		-Duser=${GDMOWN}
MESON_ARGS+=		-Dgroup=${GDMGRP}
MESON_ARGS+=		-Ddbus-sys=${PREFIX}/share/examples/dbus-1/system.d
MESON_ARGS+=		-Dgdm-xsession=true
MESON_ARGS+=		-Dwayland-support=false
MESON_ARGS+=		-Ddefault-path="/usr/local/bin:/usr/local/sbin:${PREFIX}/bin:${PREFIX}/sbin:/usr/bin:/usr/sbin:/bin/sbin"
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	GDM_CUSTOM_CONF=${EGDIR}/custom.conf
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
MAKE_ENV+=		CHMOD=${CHMOD:Q} CHOWN=${CHOWN:Q}

# only install libgdm, without the daemon and login screen
INSTALLATION_DIRS+=	include/gdm
INSTALLATION_DIRS+=	lib/girepository-1.0
INSTALLATION_DIRS+=	lib/
INSTALLATION_DIRS+=	lib/pkgconfig
INSTALLATION_DIRS+=	share/gir-1.0 share/glib-2.0/schemas

INSTALL_DIRS=	# disable meson install

do-install:
	${INSTALL_DATA} ${WRKSRC}/output/libgdm/gdm-client-glue.h \
		${DESTDIR}${PREFIX}/include/gdm
	${INSTALL_DATA} ${WRKSRC}/libgdm/gdm-client.h \
		${DESTDIR}${PREFIX}/include/gdm
	${INSTALL_DATA} ${WRKSRC}/libgdm/gdm-sessions.h \
		${DESTDIR}${PREFIX}/include/gdm
	${INSTALL_DATA} ${WRKSRC}/libgdm/gdm-user-switching.h \
		${DESTDIR}${PREFIX}/include/gdm

	${INSTALL_DATA} ${WRKSRC}/output/libgdm/Gdm-1.0.typelib \
		${DESTDIR}${PREFIX}/lib/girepository-1.0
	${INSTALL_LIB} ${WRKSRC}/output/libgdm/libgdm.so \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/output/libgdm/libgdm.so.1 \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/output/libgdm/libgdm.so.1.0.0 \
		${DESTDIR}${PREFIX}/lib

	${INSTALL_DATA} ${WRKSRC}/output/meson-private/gdm.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

	${INSTALL_DATA} ${WRKSRC}/output/libgdm/Gdm-1.0.gir \
		${DESTDIR}${PREFIX}/share/gir-1.0
	${INSTALL_DATA} ${WRKSRC}/data/org.gnome.login-screen.gschema.xml \
		${DESTDIR}${PREFIX}/share/glib-2.0/schemas

.include "../../devel/meson/build.mk"
#.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
BUILDLINK_DEPMETHOD.openpam=	build
.include "../../security/openpam/buildlink3.mk"
BUILDLINK_DEPMETHOD.dconf=		build
.include "../../devel/dconf/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
BUILDLINK_DEPMETHOD.gtk3=		build
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
