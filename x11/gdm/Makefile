# $NetBSD: Makefile,v 1.46 2004/01/22 12:56:12 jmmv Exp $
#

DISTNAME=	gdm-2.4.4.7
PKGREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdm/2.4/} \
		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mjl@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Display Manager - a re-implementation of the xdm program

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

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

BUILD_DEFS+=	USE_PAM

.if defined(USE_PAM)
.include "../../security/PAM/buildlink2.mk"
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

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../graphics/librsvg2/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
