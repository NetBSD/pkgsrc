# $NetBSD: Makefile,v 1.54.2.1 2003/12/11 19:48:11 agc Exp $

DISTNAME=	galeon-1.2.13
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=galeon/}

MAINTAINER=	taya@NetBSD.org
HOMEPAGE=	http://galeon.sourceforge.net/
COMMENT=	GNOME web browser based on gecko (mozilla rendering engine)

CONFLICTS=	galeon-current-[0-9]*

BUILD_DEPENDS+=	xml-i18n-tools>=0.8.1:../../textproc/xml-i18n-tools

EVAL_PREFIX+=	MOZILLA_PREFIX=mozilla
EVAL_PREFIX+=	ICONV_PREFIX=libiconv
EVAL_PREFIX+=	GCONF_PREFIX=GConf

USE_X11BASE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-mozilla-includes=${BUILDLINK_PREFIX.mozilla}/include/mozilla \
			--with-mozilla-libs=${BUILDLINK_PREFIX.mozilla}/lib/mozilla \
			--with-libiconv=${LOCALBASE} \
			--disable-applet \
			--disable-werror \
			--sysconfdir=${PREFIX}/etc
# XXX to build against mozilla 1.5
CONFIGURE_ARGS+= --with-mozilla-snapshot=1.5

.include	"../../converters/libiconv/buildlink2.mk"
.include	"../../devel/GConf/buildlink2.mk"
.include	"../../devel/gettext-lib/buildlink2.mk"
.include	"../../devel/libglade/buildlink2.mk"
.include	"../../devel/oaf/buildlink2.mk"
.include	"../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include	"../../textproc/libxml/buildlink2.mk"
.include	"../../textproc/scrollkeeper/omf.mk"
.include	"../../sysutils/gnome-vfs/buildlink2.mk"
.include	"../../www/mozilla/buildlink2.mk"
.include	"../../x11/gnome-libs/buildlink2.mk"

MOZ_LIBDIR=     ${MOZILLA_PREFIX}/lib/mozilla
LDFLAGS+=       -Wl,${RPATH_FLAG}${MOZ_LIBDIR}

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

pre-install:
	${GCONF_PREFIX}/bin/gconftool --shutdown

.if !empty(CC_VERSION:Mgcc-3*)
# Workaround for gcc3 build issue
post-buildlink:
	${CP} ${BUILDLINK_DIR}/bin/cc ${BUILDLINK_DIR}/bin/cc.orig
	${SED} 's:\(exec \$$cmd\):\1 -lstdc++ -lm:' ${BUILDLINK_DIR}/bin/cc.orig\
						> ${BUILDLINK_DIR}/bin/cc
.endif

post-install:
	${SED} -e "s,@PREFIX@,${PREFIX},g" -e "s,@MOZILLA_PREFIX@,${MOZILLA_PREFIX},g" ${FILESDIR}/galeon.in > ${PREFIX}/bin/galeon
	${CHOWN} ${BINOWN} ${PREFIX}/bin/galeon
	${CHGRP} ${BINGRP} ${PREFIX}/bin/galeon
	${CHMOD} ${BINMODE} ${PREFIX}/bin/galeon
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/galeon

.include "../../mk/bsd.pkg.mk"
