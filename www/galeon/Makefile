# $NetBSD: Makefile,v 1.40 2002/12/10 01:30:02 hubertf Exp $

DISTNAME=	galeon-1.2.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=galeon/}

MAINTAINER=	taya@netbsd.org
HOMEPAGE=	http://galeon.sourceforge.net/
COMMENT=	GNOME web browser based on gecko (mozilla rendering engine)

CONFLICTS=	galeon-current-[0-9]*

BUILD_DEPENDS+=	xml-i18n-tools>=0.8.1:../../textproc/xml-i18n-tools

USE_X11BASE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-mozilla-includes=${PREFIX}/include/mozilla \
			--with-mozilla-libs=${PREFIX}/lib/mozilla \
			--with-libiconv=${LOCALBASE} \
			--disable-applet \
			--disable-werror \
			--sysconfdir=${PREFIX}/etc
# XXX to build against mozilla 1.1
CONFIGURE_ARGS+= --with-mozilla-snapshot=1.2

.include	"../../converters/libiconv/buildlink2.mk"
.include	"../../devel/GConf/buildlink2.mk"
.include	"../../devel/gettext-lib/buildlink2.mk"
.include	"../../devel/libglade/buildlink2.mk"
.include	"../../devel/oaf/buildlink2.mk"
.include	"../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include	"../../textproc/libxml/buildlink2.mk"
.include	"../../textproc/scrollkeeper/buildlink2.mk"
.include	"../../sysutils/gnome-vfs/buildlink2.mk"
.include	"../../www/mozilla/buildlink2.mk"
.include	"../../x11/gnome-libs/buildlink2.mk"

MOZ_LIBDIR=     ${PREFIX}/lib/mozilla
LDFLAGS+=       -Wl,-R${MOZ_LIBDIR}

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

pre-install:
	${X11PREFIX}/bin/gconftool --shutdown

post-install:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/galeon.in > ${PREFIX}/bin/galeon
	${CHOWN} ${BINOWN} ${PREFIX}/bin/galeon
	${CHGRP} ${BINGRP} ${PREFIX}/bin/galeon
	${CHMOD} ${BINMODE} ${PREFIX}/bin/galeon
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/galeon

.include "../../mk/bsd.pkg.mk"
