# $NetBSD: Makefile,v 1.98 2006/01/24 07:32:51 wiz Exp $
#

DISTNAME=	gdm-2.8.0.7
PKGREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdm/2.8/}
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.README Daemon.png

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Display Manager - a re-implementation of the xdm program

BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.libart2+=	libart2>=2.3.11

SITES_Daemon.README=	${MASTER_SITE_LOCAL}
SITES_Daemon.png=	${MASTER_SITE_LOCAL}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_MSGFMT_PLURALS=	YES
USE_TOOLS+=		gmake pkg-config

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdm
PKG_SUPPORTED_OPTIONS=	inet6 pam
.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q}
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}
MAKE_ENV+=		CHMOD=${CHMOD:Q} CHOWN=${CHOWN:Q}

OWN_DIRS=		${PKG_SYSCONFDIR}/dm/Sessions
OWN_DIRS+=		${PKG_SYSCONFDIR}/gdm/Init
OWN_DIRS+=		${PKG_SYSCONFDIR}/gdm/PostSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/gdm/PreSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/gdm/modules
OWN_DIRS+=		${VARBASE}/gdm
OWN_DIRS+=		${VARBASE}/log/gdm

EGDIR=			${PREFIX}/share/examples
CONF_FILES=		${EGDIR}/dm/Sessions/default.desktop \
			${PKG_SYSCONFDIR}/dm/Sessions/default.desktop
.for f in gdm.conf locale.alias \
	modules/AccessDwellMouseEvents modules/AccessKeyMouseEvents \
	modules/factory-AccessDwellMouseEvents \
	modules/factory-AccessKeyMouseEvents
CONF_FILES+=		${EGDIR}/gdm/${f} \
			${PKG_SYSCONFDIR}/gdm/${f}
.endfor
.for f in Init/Default PostSession/Default PreSession/Default \
	XKeepsCrashing Xsession
CONF_FILES_PERMS+=	${EGDIR}/gdm/${f} \
			${PKG_SYSCONFDIR}/gdm/${f} \
			${ROOT_USER} ${ROOT_GROUP} 0755
.endfor
RCD_SCRIPTS=		gdm

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		desktop
SUBST_MESSAGE.desktop=	"Configuring GDM settings."
SUBST_STAGE.desktop=	pre-configure
SUBST_FILES.desktop=	config/default.desktop.in
SUBST_FILES.desktop+=	config/gnome.desktop.in
SUBST_FILES.desktop+=	config/gdm.conf.in
SUBST_SED.desktop=	-e 's/^_//g'
SUBST_SED.desktop+=	-e 's|^User=gdm$$|User=${GDMOWN}|g'
SUBST_SED.desktop+=	-e 's|^Group=gdm$$|Group=${GDMGRP}|g'
SUBST_SED.desktop+=	-e 's|^\#Logo=.*$$|Logo=@EXPANDED_PIXMAPDIR@/Daemon.png|g'
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gdm
	${INSTALL_DATA} ${DISTDIR}/Daemon.README ${PREFIX}/share/doc/gdm
	${INSTALL_DATA} ${DISTDIR}/Daemon.png ${PREFIX}/share/pixmaps

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
