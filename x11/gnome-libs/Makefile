# $NetBSD: Makefile,v 1.74 2002/01/01 15:14:19 bjoern Exp $

DISTNAME=		gnome-libs-1.4.1.2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-libs/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Libraries for the GNU Network Object Model Environment

BUILD_USES_MSGFMT=	YES

USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE} \
			--with-kde-datadir=${X11PREFIX}/share/kde
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} \
			X11BASE=${X11BASE} \
			PKGLOCALEDIR=${PKGLOCALEDIR}

USE_BUILDLINK_ONLY=	YES

LOCALSTATEDIR=		/var/gnome
PLIST_SUBST+=		LOCALBASE=${LOCALBASE} \
			LOCALEDIR=${LOCALEDIR} \
			LOCALSTATEDIR=${LOCALSTATEDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.include "../../databases/db/buildlink.mk"

CPPFLAGS+=		-I${BUILDLINK_DIR}/include/db2

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
	${INSTALL_DATA_DIR} ${PREFIX}/etc/CORBA/servers
	${TOUCH} ${PREFIX}/etc/CORBA/servers/.directory
	${INSTALL_DATA_DIR} ${LOCALSTATEDIR}
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/libart.m4 \
		${LOCALBASE}/share/aclocal/libart.m4

.include "../../audio/esound/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../net/ORBit/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
