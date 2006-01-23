# $NetBSD: Makefile,v 1.113 2006/01/23 17:08:46 joerg Exp $

DISTNAME=		gnome-libs-1.4.2
PKGREVISION=		4
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-libs/1.4/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Libraries for the GNU Network Object Model Environment

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BROKEN_GETTEXT_DETECTION=	YES
BUILD_USES_MSGFMT=	YES

USE_DIRS+=		gnome1-1.5
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR:Q} \
			--enable-gtk-doc=no \
			--with-html-dir=${PREFIX}/share/doc/html \
			--with-kde-datadir=${X11PREFIX}/share/kde
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
CONFIGURE_ENV+=		${CONFIGURE_ENV.db-${BDB_TYPE}}

USE_PKGLOCALEDIR=	YES

LOCALSTATEDIR=		${VARBASE}/gnome
PLIST_SUBST+=		LOCALSTATEDIR=${LOCALSTATEDIR:Q}

SUBST_CLASSES+=		varbase
SUBST_MESSAGE.varbase=	"Fixing path to score files."
SUBST_STAGE.varbase=	post-patch
SUBST_FILES.varbase+=	gnome-data/Makefile.in
SUBST_FILES.varbase+=	libgnome/gnome-score.c
SUBST_SED.varbase=	-e 's,@VARBASE@,${VARBASE},g'

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../net/ORBit/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"

CONFIGURE_ENV.db-${BDB_TYPE}?=	ac_cv_func_dbopen=no
CONFIGURE_ENV.db-db1=		# empty

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

.include "../../mk/bsd.pkg.mk"
