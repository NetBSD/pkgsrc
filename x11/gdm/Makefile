# $NetBSD: Makefile,v 1.62 2004/04/25 18:47:55 snj Exp $
#

DISTNAME=	gdm-2.6.0.0
PKGREVISION=	2
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

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		X11BASE=${X11BASE}
MAKE_ENV+=		CHMOD=${CHMOD} CHOWN=${CHOWN}

OWN_DIRS=		${PKG_SYSCONFDIR}/dm/Sessions
OWN_DIRS+=		${PKG_SYSCONFDIR}/gdm/Init
OWN_DIRS+=		${PKG_SYSCONFDIR}/gdm/PostSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/gdm/PreSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/gdm/modules
OWN_DIRS+=		/var/gdm
OWN_DIRS+=		/var/log/gdm

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

SUBST_CLASSES+=		desktop
SUBST_MESSAGE.desktop=	"Configuring GDM settings."
SUBST_STAGE.desktop=	pre-configure
SUBST_FILES.desktop=	config/default.desktop.in
SUBST_FILES.desktop+=	config/gnome.desktop.in
SUBST_FILES.desktop+=	config/gdm.conf.in
SUBST_SED.desktop=	-e 's/^_//g'
SUBST_SED.desktop+=	-e 's|@GDMOWN@|${GDMOWN}|g'
SUBST_SED.desktop+=	-e 's|@GDMGRP@|${GDMGRP}|g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSunOS
GDMOWN=		daemon
GDMGRP=		other
.else
GDMOWN=		daemon
GDMGRP=		daemon
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	X_SERVER_ARGS="vt05"
.endif

BUILD_DEFS+=	USE_PAM

.if defined(USE_PAM)
.include "../../security/PAM/buildlink3.mk"
CONFIGURE_ENV+=		USE_PAM=yes
PLIST_SUBST+=		PAM_MISC=""
.else
CONFIGURE_ENV+=		USE_PAM=no
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
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
