# $NetBSD: Makefile,v 1.92 2003/10/29 15:35:51 wiz Exp $

DISTNAME=		gnome-libs-1.4.2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-libs/1.4/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Libraries for the GNU Network Object Model Environment

DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs
BUILD_USES_MSGFMT=	YES

USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libart_lgpl/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--enable-gtk-doc=no \
			--with-html-dir=${PREFIX}/share/doc/html \
			--with-glib-prefix=${LOCALBASE} \
			--with-kde-datadir=${X11PREFIX}/share/kde
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} \
			X11BASE=${X11BASE} \
			PKGLOCALEDIR=${PKGLOCALEDIR}

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_DB185=		YES

LOCALSTATEDIR=		/var/gnome
PLIST_SUBST+=		LOCALBASE=${LOCALBASE} \
			LOCALEDIR=${LOCALEDIR} \
			LOCALSTATEDIR=${LOCALSTATEDIR}

post-extract:
.for file in gnome-app-helper-convenience-macros.htm			\
	     gnome-app-helper-keybindings-config.htm
	cd ${WRKSRC}/devel-docs/gnome-dev-info/gnome-dev-info &&	\
	( [ -f ${file}l ] || ${MV} ${file} ${file}l )
.endfor

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

.include "../../audio/esound/buildlink2.mk"
.include "../../databases/db/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../net/ORBit/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
