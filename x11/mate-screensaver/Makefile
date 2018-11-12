# $NetBSD: Makefile,v 1.14 2018/11/12 03:53:11 ryoon Exp $

.include "../../meta-pkgs/mate/Makefile.common"

PKGREVISION=	2
DISTNAME=	mate-screensaver-${VERSION}
CATEGORIES=	x11

COMMENT=	Screen saver and locker for the MATE desktop

PKGCONFIG_OVERRIDE+=	data/mate-screensaver.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-console-kit=yes
CONFIGURE_ARGS+=	--with-systemd=no

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS+=	PAM_PREFIX=${PREFIX}/share/examples/pam.d

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/mate-screensaver/xdg/autostart/mate-screensaver.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/mate-screensaver.desktop
CONF_FILES+=	${PREFIX}/share/examples/mate-screensaver/xdg/menus/mate-screensavers.menu \
		${PKG_SYSCONFDIR}/xdg/menus/mate-screensavers.menu

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		pam

.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--disable-pam
SPECIAL_PERMS+=		libexec/mate-screensaver-dialog ${SETUID_ROOT_PERMS}
.else
DEPENDS+=		pam-pwauth_suid-[0-9]*:../../security/pam-pwauth_suid
INSTALLATION_DIRS+=	${PREFIX}/share/examples/pam.d

post-extract:
	${CP} ${FILESDIR}/mate-screensaver.pam ${WRKDIR}

SUBST_CLASSES+=		pam-conf
SUBST_STAGE.pam-conf=	post-configure
SUBST_FILES.pam-conf=	${WRKDIR}/mate-screensaver.pam
SUBST_VARS.pam-conf=	PREFIX

PLIST.pam=		yes

post-install: pamd
.PHONY: pamd
pamd:
	${TEST} -f ${DESTDIR}${PREFIX}/share/examples/pam.d/mate-screensaver || \
		${INSTALL_DATA} ${WRKDIR}/mate-screensaver.pam ${DESTDIR}${PREFIX}/share/examples/pam.d/mate-screensaver

MAKE_DIRS+=	/etc/pam.d
CONF_FILES+=	${PREFIX}/share/examples/pam.d/mate-screensaver \
		/etc/pam.d/mate-screensaver

DEPENDS+=	consolekit-[0-9]*:../../sysutils/consolekit
.endif

post-install:
	# avoid conflicts with gnome-screensaver
	${RM} -f ${DESTDIR}${PREFIX}/share/applications/screensavers/gnomelogo-floaters.desktop
	${RM} -f ${DESTDIR}${PREFIX}/share/pixmaps/gnome-logo-white.svg
	cd ${DESTDIR}${PREFIX}/share/applications/screensavers && \
	for f in *; do			\
		${MV} $$f mate-$$f; 	\
	done

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/mate-menus/buildlink3.mk"
.include "../../x11/libmatekbd/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
