# $NetBSD: Makefile,v 1.39 2002/07/16 13:11:13 agc Exp $

DISTNAME=		control-center-1.4.0.4
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/control-center/}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME control-center development library

BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.gnome-libs=	gnome-libs>=1.4.1.2nb1

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

LOCALSTATEDIR=		${X11PREFIX}/var/gnome

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}

# Remove -I$(includedir) from the INCLUDES passed to the compiler as this
# defeats buildlink.  Also replace "imlib-config" with "$(IMLIB_CONFIG)"
# so we use the config wrapper script.
#
post-patch:
	cd ${WRKSRC};							\
	files="control-center/Makefile.in capplets/*/Makefile.in";	\
	for file in $${files}; do					\
                ${SED}	-e "s|[ 	]*-I\$$(includedir)||"		\
			-e "s|imlib-config|\$$(IMLIB_CONFIG)|g"		\
                        $${file} > $${file}.fixed;			\
                ${MV} -f $${file}.fixed $${file};			\
        done
	@${ECHO} >>${WRKSRC}/control-center/cappletConf.sh.in ""

.include "../../devel/popt/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../sysutils/gnome-vfs/buildlink.mk"
.include "../../textproc/scrollkeeper/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
