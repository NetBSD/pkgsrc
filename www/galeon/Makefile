# $NetBSD: Makefile,v 1.32 2002/06/12 03:00:44 wiz Exp $

DISTNAME=	galeon-1.2.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=galeon/}

MAINTAINER=	taya@netbsd.org
HOMEPAGE=	http://galeon.sourceforge.net/
COMMENT=	GNOME web browser based on gecko (mozilla rendering engine)

CONFLICTS=	galeon-current-[0-9]*

BUILD_DEPENDS+=	xml-i18n-tools>=0.8.1:../../textproc/xml-i18n-tools
DEPENDS+=	scrollkeeper>=0.2:../../textproc/scrollkeeper
DEPENDS+=	mozilla>=1.0:../../www/mozilla

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-mozilla-includes=${PREFIX}/include/mozilla \
		 --with-mozilla-libs=${PREFIX}/lib/mozilla \
		--with-libiconv=${LOCALBASE} \
		--disable-applet \
		--disable-werror \
		--sysconfdir=${PREFIX}/etc

.include	"../../x11/gnome-libs/buildlink.mk"
.include	"../../devel/libglade/buildlink.mk"
.include	"../../sysutils/gnome-vfs/buildlink.mk"
.include	"../../devel/GConf/buildlink.mk"
.include	"../../devel/oaf/buildlink.mk"
.include	"../../textproc/libxml/buildlink.mk"
.include	"../../converters/libiconv/buildlink.mk"
.include	"../../graphics/gdk-pixbuf-gnome/buildlink.mk"
.include	"../../devel/gettext-lib/buildlink.mk"

MOZ_LIBDIR=     ${PREFIX}/lib/mozilla
LDFLAGS+=       -Wl,-R${MOZ_LIBDIR}
.if(${OBJECT_FMT} == ELF)
LDFLAGS+=	-export-dynamic
.else
LIBS+=		-lstdc++
.endif

pre-install:
	${X11PREFIX}/bin/gconftool --shutdown

post-install:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/galeon.in > ${PREFIX}/bin/galeon
	${CHOWN} ${BINOWN} ${PREFIX}/bin/galeon
	${CHGRP} ${BINGRP} ${PREFIX}/bin/galeon
	${CHMOD} ${BINMODE} ${PREFIX}/bin/galeon
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/galeon

.include "../../mk/bsd.pkg.mk"
