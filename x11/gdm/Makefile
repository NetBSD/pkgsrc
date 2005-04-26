# $NetBSD: Makefile,v 1.77 2005/04/26 20:20:32 drochner Exp $
#

DISTNAME=	gdm-2.6.0.9
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdm/2.6/}
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.README Daemon.png

MAINTAINER=	mjl@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Display Manager - a re-implementation of the xdm program

BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.libart2+=	libart2>=2.3.11

SITES_Daemon.README=	${MASTER_SITE_LOCAL}
SITES_Daemon.png=	${MASTER_SITE_LOCAL}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

USE_DIRS+=		gnome2-1.5
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdm
PKG_SUPPORTED_OPTIONS=	inet6 PAM
.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_ENV+=		X11BASE=${X11BASE}
MAKE_ENV+=		CHMOD=${CHMOD} CHOWN=${CHOWN}

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
CONF_FILES+=		${EGDIR}/gdm/$f \
			${PKG_SYSCONFDIR}/gdm/$f
.endfor
SUPPORT_FILES_MODE=	0755
.for f in Init/Default PostSession/Default PreSession/Default \
	XKeepsCrashing Xsession
SUPPORT_FILES+=		${EGDIR}/gdm/$f \
			${PKG_SYSCONFDIR}/gdm/$f
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

.if !empty(PKG_OPTIONS:MPAM)
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gdm
	${INSTALL_DATA} ${DISTDIR}/Daemon.README ${PREFIX}/share/doc/gdm
	${INSTALL_DATA} ${DISTDIR}/Daemon.png ${PREFIX}/share/pixmaps

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
