# $NetBSD: Makefile,v 1.57 2001/02/17 17:06:24 wiz Exp $

DISTNAME=		gnome-libs-1.2.8
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-libs/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Libaries for the GNU Network Object Model Environment

DEPENDS+=		ORBit-*:../../net/ORBit
DEPENDS+=		esound>=0.2.18:../../audio/esound
DEPENDS+=		gtk+>=1.2.7:../gtk
DEPENDS+=		imlib-*:../../graphics/imlib
BUILD_DEPENDS+=		msgfmt:../../devel/gettext

USE_LIBINTL=		YES
USE_X11BASE=		YES
USE_XPM=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE} \
			--with-kde-datadir=${X11PREFIX}/share/kde
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" \
			LOCALBASE=${LOCALBASE} \
			X11BASE=${X11BASE}

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=       	-L${LOCALBASE}/lib

LOCALSTATEDIR=		/var/gnome
PLIST_SUBST+=		LOCALBASE=${LOCALBASE} \
			LOCALEDIR=${LOCALEDIR} \
			LOCALSTATEDIR=${LOCALSTATEDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=		db-*:../../databases/db
CPPFLAGS+=		-I${LOCALBASE}/include/db2

pre-configure:
	${MV} ${WRKSRC}/configure ${WRKSRC}/configure-pre-db-sub && \
		${SED} -e 's|-ldb|-ldb2|g' \
			< ${WRKSRC}/configure-pre-db-sub \
			> ${WRKSRC}/configure && \
		${CHMOD} 0755 ${WRKSRC}/configure
.endif

post-patch:
	${MV} ${WRKSRC}/gnome-config.in ${WRKSRC}/gnome-config.in-pre-lpath && \
		${SED} -e "s|@LOCALBASE@|${LOCALBASE}|g" \
			< ${WRKSRC}/gnome-config.in-pre-lpath \
			> ${WRKSRC}/gnome-config.in

pre-build:
	cd ${WRKSRC}/support && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} gnomesupport.h

post-install:
	${MKDIR} ${PREFIX}/etc/CORBA/servers
	${TOUCH} ${PREFIX}/etc/CORBA/servers/.directory
	${MKDIR} ${LOCALSTATEDIR}
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/libart.m4 \
		${LOCALBASE}/share/aclocal/libart.m4

.include "../../mk/bsd.pkg.mk"
