# $NetBSD: Makefile,v 1.3 2004/04/02 16:00:50 xtraeme Exp $
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
BUILDLINK_DEPENDS.glib2+=	    glib2>=2.4.0

GCONF2_SCHEMAS=		galeon.schemas

CONFIGURE_ARGS+=	--with-mozilla-snapshot=1.6
CONFIGURE_ARGS+=	--enable-nautilus-view=yes

EGDIR=			${PREFIX}/share/examples/galeon2
CONF_FILES=		${EGDIR}/galeon.soundlist \
			${PKG_SYSCONFDIR}/galeon.soundlist

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/mozilla-gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
