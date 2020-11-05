# $NetBSD: Makefile,v 1.199 2020/11/05 09:09:23 ryoon Exp $
#

DISTNAME=	gdm-2.20.11
PKGREVISION=	34
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdm/2.20/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Gnome Display Manager - a re-implementation of the xdm program

DEPENDS+=	zenity>=2.16.0:../../x11/zenity

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
BUILD_DEFS+=		VARBASE

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-dmconfdir=${PKG_SYSCONFDIR:Q}/dm
CONFIGURE_ARGS+=	--with-sysconfsubdir=
CONFIGURE_ARGS+=	--with-prefetch=yes
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q}
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	GDM_CUSTOM_CONF=${EGDIR:Q}/custom.conf
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR:Q}
MAKE_ENV+=		CHMOD=${CHMOD:Q} CHOWN=${CHOWN:Q}

OWN_DIRS=		${PKG_SYSCONFDIR}/Init
OWN_DIRS+=		${PKG_SYSCONFDIR}/PostLogin
OWN_DIRS+=		${PKG_SYSCONFDIR}/PostSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/PreSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/dm
OWN_DIRS+=		${PKG_SYSCONFDIR}/modules
OWN_DIRS+=		${VARBASE}/gdm
OWN_DIRS+=		${VARBASE}/log/gdm

PKG_SYSCONFSUBDIR=	gdm
EGDIR=			${PREFIX}/share/examples/gdm
CONF_FILES=
.for f in custom.conf locale.alias \
	modules/AccessDwellMouseEvents modules/AccessKeyMouseEvents \
	modules/factory-AccessDwellMouseEvents \
	modules/factory-AccessKeyMouseEvents
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.for f in Init/Default PostLogin/Default.sample PostSession/Default \
	PreSession/Default XKeepsCrashing Xsession
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755
.endfor
RCD_SCRIPTS=		gdm

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		desktop
SUBST_MESSAGE.desktop=	Configuring GDM settings.
SUBST_STAGE.desktop=	pre-configure
SUBST_FILES.desktop+=	config/gdm.conf.in
SUBST_SED.desktop=	-e 's/^_//g'
SUBST_SED.desktop+=	-e 's|^User=gdm$$|User=${GDMOWN}|g'
SUBST_SED.desktop+=	-e 's|^Group=gdm$$|Group=${GDMGRP}|g'
SUBST_SED.desktop+=	-e 's|^\#GtkTheme=.*$$|GtkTheme=Clearlooks|g'
SUBST_SED.desktop+=	-e 's|^\#FirstVT=.*$$|FirstVT=5|g'
SUBST_SED.desktop+=	-e 's|^\#VTAllocation=.*$$|VTAllocation=true|g'
.if ${OPSYS} == "NetBSD"
SUBST_SED.desktop+=	-e 's|^\#Logo=.*$$|Logo=${PREFIX}/share/pixmaps/NetBSD.xpm|g'
.endif
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
SUBST_SED.desktop+=	-e 's|^\#RebootCommand=.*$$|RebootCommand=/sbin/shutdown -r now|g'
SUBST_SED.desktop+=	-e 's|^\#HaltCommand=.*$$|HaltCommand=/sbin/shutdown -p now|g'
.endif
SUBST_SED.desktop+=	-e 's|^PreFetchProgram=.*$$|PreFetchProgram=${PREFIX}/libexec/gdmprefetch @${PKG_SYSCONFDIR}/gdmprefetchlist|g'

SUBST_CLASSES+=		gdmsetup
SUBST_MESSAGE.gdmsetup=	Patching gdmsetup theme installer to use ${REAL_ROOT_USER}:${REAL_ROOT_GROUP}
SUBST_STAGE.gdmsetup=	pre-configure
SUBST_FILES.gdmsetup=	gui/gdmsetup.c
SUBST_SED.gdmsetup=	-e 's/root:root/${REAL_ROOT_USER}:${REAL_ROOT_GROUP}/g'

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSunOS
GDMOWN=		daemon
GDMGRP=		other
.else
GDMOWN=		daemon
GDMGRP=		daemon
.endif

# The following forces the X server to start on the 5th virtual terminal.
# This is suboptimal but matches the defaults for the xdm configuration,
# which should work for most installations.  See the definition of
# DEFAULTVT in xsrc/xfree/xc/programs/xdm/config/Imakefile.
#
# If we do not do this, we hit a very annoying and obscure problem: during
# system startup, gdm starts before init spawns gettys.  If the X server
# is started before init spawns the gettys (which easily happens on slow
# machines), it grabs the first virtual terminal (instead of the first
# "free" one).  Later on, when the first getty is started, it grabs the
# same terminal X used (the first one).  As a result, only one of them
# will receive key presses.  And on slow machines, X will have lost access
# to the keyboard.
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD") && \
    (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
CONFIGURE_ARGS+=	X_SERVER_ARGS="vt05"
.endif

PLIST_VARS+=		dmx
.if exists(${X11BASE}/include/X11/extensions/dmxext.h)
PLIST.dmx=		yes
.endif
PRINT_PLIST_AWK+=	/dmx/ { print "$${DMX}" $$0; next }

PLIST_VARS+=		gdmopen
.if exists(/usr/include/linux/vt.h) || ${OPSYS} == "SunOS"
PLIST.gdmopen=		yes
.endif
PRINT_PLIST_AWK+=	/gdmopen/ { print "$${GDMOPEN}" $$0; next }

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libart+=	libart>=2.3.11
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${FILESDIR}/NetBSD.xpm ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/custom.desktop \
		${DESTDIR}${PREFIX}/share/gdm/BuiltInSessions

.include "../../mk/bsd.pkg.mk"
