# $NetBSD: Makefile,v 1.12 2001/09/21 16:37:41 taya Exp $

DISTNAME=	galeon-0.12.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=galeon/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://galeon.sourceforge.net/
COMMENT=	GNOME web browser based on gecko (mozilla rendering engine)

BUILD_DEPENDS+=	xml-i18n-tools>=0.8.1:../../textproc/xml-i18n-tools
DEPENDS+=	mozilla>=0.9.2:../mozilla
DEPENDS+=	gnome-libs>=1.2.1:../../x11/gnome-libs
DEPENDS+=	libglade>=0.13:../../devel/libglade
DEPENDS+=	gnome-vfs>=0.6:../../sysutils/gnome-vfs
DEPENDS+=	GConf>=1.0.4:../../devel/GConf
DEPENDS+=	oaf>=0.6.5:../../devel/oaf
DEPENDS+=	libxml>=1.8.13:../../textproc/libxml
DEPENDS+=	libiconv>=1.6.1:../../converters/libiconv
DEPENDS+=	gdk-pixbuf-gnome>=0.10.1:../../graphics/gdk-pixbuf-gnome

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-mozilla-includes=${PREFIX}/include/mozilla \
		 --with-mozilla-libs=${PREFIX}/lib/mozilla \
		--with-libiconv=${LOCALBASE} \
		--disable-applet \
		--sysconfdir=${PREFIX}/etc

USE_LIBINTL=	yes

MOZ_LIBDIR=     ${PREFIX}/lib/mozilla
LDFLAGS+=       -Wl,-R${MOZ_LIBDIR}
LDFLAGS+=	-export-dynamic

pre-install:
	${X11PREFIX}/bin/gconftool --shutdown

post-install:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/galeon.in > ${PREFIX}/bin/galeon
	${CHOWN} ${BINOWN} ${PREFIX}/bin/galeon
	${CHGRP} ${BINGRP} ${PREFIX}/bin/galeon
	${CHMOD} ${BINMODE} ${PREFIX}/bin/galeon
	${BSD_INSTALL_PROGRAM_DIR} ${PREFIX}/lib/galeon

.include "../../mk/bsd.pkg.mk"
