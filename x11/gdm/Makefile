# $NetBSD: Makefile,v 1.120.2.1 2006/12/21 02:13:31 salo Exp $
#

DISTNAME=	gdm-2.16.4
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdm/2.16/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Display Manager - a re-implementation of the xdm program

DEPENDS+=	zenity>=2.16.0:../../x11/zenity

BUILDLINK_API_DEPENDS.libart2+=	libart2>=2.3.11

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdm
PKG_SUPPORTED_OPTIONS=	inet6 pam
.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-dmconfdir=${PKG_SYSCONFDIR:Q}/dm
CONFIGURE_ARGS+=	--with-sysconfsubdir=
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
			${ROOT_USER} ${ROOT_GROUP} 0755
.endfor
RCD_SCRIPTS=		gdm

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		desktop
SUBST_MESSAGE.desktop=	Configuring GDM settings.
SUBST_STAGE.desktop=	pre-configure
SUBST_FILES.desktop=	config/default.desktop.in
SUBST_FILES.desktop+=	config/gnome.desktop.in
SUBST_FILES.desktop+=	config/gdm.conf.in
SUBST_SED.desktop=	-e 's/^_//g'
SUBST_SED.desktop+=	-e 's|^User=gdm$$|User=${GDMOWN}|g'
SUBST_SED.desktop+=	-e 's|^Group=gdm$$|Group=${GDMGRP}|g'
SUBST_SED.desktop+=	-e 's|^\#Logo=.*$$|Logo=@EXPANDED_PIXMAPDIR@/NetBSD.xpm|g'
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
SUBST_SED.desktop+=	-e 's|^\#RebootCommand=.*$$|RebootCommand=/sbin/shutdown -r now|g'
SUBST_SED.desktop+=	-e 's|^\#HaltCommand=.*$$|HaltCommand=/sbin/shutdown -p now|g'
.endif

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSunOS
GDMOWN=		daemon
GDMGRP=		other
.else
GDMOWN=		daemon
GDMGRP=		daemon
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	X_SERVER_ARGS="vt05"
.endif

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-authentication-scheme=pam
.  if ${PAM_TYPE} == "linux-pam"
PLIST_SUBST+=		PAM_MISC=""
.  else
PLIST_SUBST+=		PAM_MISC="@comment "
.  endif
.elif exists(/etc/shadow)
CONFIGURE_ARGS+=	--enable-authentication-scheme=shadow
PLIST_SUBST+=		PAM_MISC="@comment "
.else
CONFIGURE_ARGS+=	--enable-authentication-scheme=crypt
PLIST_SUBST+=		PAM_MISC="@comment "
.endif

.if exists(${X11BASE}/include/X11/extensions/dmxext.h)
PLIST_SUBST+=		DMX=""
.else
PLIST_SUBST+=		DMX="@comment "
.endif
PRINT_PLIST_AWK+=	/dmx/ { print "$${DMX}" $$0; next }

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${FILESDIR}/NetBSD.xpm ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/custom.desktop \
		${PREFIX}/share/gdm/BuiltInSessions

.include "../../mk/bsd.pkg.mk"
