# $NetBSD: Makefile,v 1.1.1.1 2004/03/30 23:40:52 xtraeme Exp $
#

DISTNAME=	galeon-1.3.14a
PKGNAME=	${DISTNAME:S/galeon/galeon-devel/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=galeon/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://galeon.sourceforge.net/
COMMENT=	GNOME2 Web browser based on gecko

DEPENDS=		gnome2-dirs>=1.5:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${DISTNAME:S/14a/14/}

BUILDLINK_RPATHDIRS.mozilla-gtk2+=  lib/mozilla-gtk2

GCONF2_SCHEMAS=		galeon.schemas

CONFIGURE_ARGS+=	--with-mozilla-snapshot=1.6
CONFIGURE_ARGS+=	--enable-nautilus-view=yes

EGDIR=			${PREFIX}/share/examples/galeon2
CONF_FILES=		${EGDIR}/galeon.soundlist \
			${PKG_SYSCONFDIR}/galeon.soundlist

# ATTENTION: glib2<=2.2.x uses g_value_set_FOO_take_ownership, but these
# functions has been deprecated when using glib2>=2.4.x. So if you are
# using 2.4.x, comment out this block.
SUBST_CLASSES=		    glib2
SUBST_STAGE.glib2=	    post-patch
SUBST_FILES.glib2=	    utils/galeon-marshal.c
SUBST_SED.glib2=	    -e s,g_value_take_string,g_value_set_string_take_ownership,g
SUBST_MESSAGE.glib2=	    "Fixing g_value_take_string."

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/mozilla-gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
