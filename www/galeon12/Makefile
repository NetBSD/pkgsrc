# $NetBSD: Makefile,v 1.5 2004/10/03 00:18:25 tv Exp $

DISTNAME=	galeon-1.2.14
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=galeon/}

MAINTAINER=	taya@NetBSD.org
HOMEPAGE=	http://galeon.sourceforge.net/
COMMENT=	GNOME web browser based on gecko (mozilla rendering engine)

CONFLICTS=	galeon-current-[0-9]*

EVAL_PREFIX+=	MOZILLA_PREFIX=mozilla
EVAL_PREFIX+=	ICONV_PREFIX=libiconv
EVAL_PREFIX+=	GCONF_PREFIX=GConf

USE_X11BASE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-mozilla-includes=${BUILDLINK_PREFIX.mozilla}/include/mozilla \
			--with-mozilla-libs=${BUILDLINK_PREFIX.mozilla}/lib/mozilla \
			--with-libiconv=${LOCALBASE} \
			--disable-applet \
			--disable-werror \
			--sysconfdir=${PREFIX}/etc \
			MOZILLA_CONFIG=${MOZ_LIBDIR}/mozilla-config
CONFIGURE_ARGS+= --with-mozilla-snapshot=1.7

.include	"../../converters/libiconv/buildlink3.mk"
.include	"../../devel/GConf/buildlink3.mk"
.include	"../../devel/gettext-lib/buildlink3.mk"
.include	"../../devel/libglade/buildlink3.mk"
.include	"../../devel/oaf/buildlink3.mk"
.include	"../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include	"../../textproc/intltool/buildlink3.mk"
.include	"../../textproc/libxml/buildlink3.mk"
.include	"../../textproc/scrollkeeper/omf.mk"
.include	"../../sysutils/gnome-vfs/buildlink3.mk"
.include	"../../www/mozilla/buildlink3.mk"
.include	"../../x11/gnome-libs/buildlink3.mk"

MOZ_LIBDIR=     ${MOZILLA_PREFIX}/lib/mozilla
LDFLAGS+=       ${COMPILER_RPATH_FLAG}${MOZ_LIBDIR}

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

pre-install:
	${GCONF_PREFIX}/bin/gconftool --shutdown

post-install:
	${SED} -e "s,@PREFIX@,${PREFIX},g" -e "s,@MOZILLA_PREFIX@,${MOZILLA_PREFIX},g" ${FILESDIR}/galeon.in > ${PREFIX}/bin/galeon
	${CHOWN} ${BINOWN} ${PREFIX}/bin/galeon
	${CHGRP} ${BINGRP} ${PREFIX}/bin/galeon
	${CHMOD} ${BINMODE} ${PREFIX}/bin/galeon
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/galeon

.include "../../mk/bsd.pkg.mk"
