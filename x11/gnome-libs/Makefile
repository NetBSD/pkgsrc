# $NetBSD: Makefile,v 1.62 2001/06/16 20:05:10 jlam Exp $

DISTNAME=		gnome-libs-1.2.13
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-libs/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Libaries for the GNU Network Object Model Environment

BUILD_USES_MSGFMT=	yes

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

USE_CONFIG_WRAPPER=	YES

.include "../../audio/esound/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../net/ORBit/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"

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

# Fix gnomeConf.sh, gnome-config by removing buildlink directory references.
post-build:
	@cd ${WRKSRC};							\
	for file in gnomeConf.sh gnome-config; do			\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"	\
			-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"	\
			$${file}.fixme > $${file};			\
		${RM} -f $${file}.fixme;				\
		${CHMOD} +x $${file};					\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/CORBA/servers
	${TOUCH} ${PREFIX}/etc/CORBA/servers/.directory
	${INSTALL_DATA_DIR} ${LOCALSTATEDIR}
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/libart.m4 \
		${LOCALBASE}/share/aclocal/libart.m4

.include "../../mk/bsd.pkg.mk"
