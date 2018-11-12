# $NetBSD: Makefile,v 1.81 2018/11/12 03:53:00 ryoon Exp $

DISTNAME=	gnotime-2.4.0
PKGREVISION=	9
CATEGORIES=	time gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gttr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gttr.sourceforge.net/
COMMENT=	Time tracker for GNOME2
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS=		gnotime.schemas
MAKE_ENV+=		GCONF_SCHEMAS_DIR=${GCONF_SCHEMAS_DIR:Q}

EGDIR=			share/gconf
CONF_FILES+=		${EGDIR}/schemas/${GCONF_SCHEMAS}  etc/gconf/schemas/${GCONF_SCHEMAS}

post-install:
	cd ${DESTDIR}${PREFIX}; \
	${MKDIR}                                etc/gconf/schemas ;\
	${MKDIR}                                 ${EGDIR}/schemas ;\
	${MV} etc/gconf/schemas/${GCONF_SCHEMAS} ${EGDIR}/schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/qof/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../www/gtkhtml314/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
