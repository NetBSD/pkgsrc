# $NetBSD: Makefile,v 1.62 2001/06/19 06:52:10 jlam Exp $

DISTNAME=		gtk+-1.2.10
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v1.2/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.2/ \
			http://www.ameth.org/gimp/pub/gtk/v1.2/ \
			${MASTER_SITE_GNOME:=stable/sources/gtk/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gtk.org/
COMMENT=		Gimp toolkit. Libraries for building X11 user interfaces

BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK_ONLY=	yes
#USE_LIBINTL=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_CONFIG_WRAPPER=	yes

GNU_CONFIGURE=		 yes
CONFIGURE_ARGS+=	--with-xinput=xfree
CONFIGURE_ENV+=		X_LDFLAGS="${X_LDFLAGS}"

INFO_FILES=		gdk.info gtk.info

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"

MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

# The following ensures that `gtk-config --libs' includes the correct linker
# flags for linking the X11 libs.
#
X_LDFLAGS=		-Wl,-R${X11BASE}/lib -L${X11BASE}/lib

GTK_VERSION=		${DISTNAME:S/gtk+-//}
GTK_MAJOR_VERSION=	${GTK_VERSION:C/\..*//}
GTK_MINOR_VERSION=	${GTK_VERSION:C/[^.]*\.//:C/\..*//}
GTK_MICRO_VERSION=	${GTK_VERSION:C/.*\.//}

# We patch the version info in the configure scripts for reasons related to
# shared library numbering, but we don't want it to leak into the various
# installed files.  Explicitly replace the version number with the correct
# one derived from the package name.
#
pre-configure:
	@cd ${WRKSRC};							\
	files="gtk-config.in docs/gtk-config.1.in gdk.pc.in gtk+.pc.in gtk/gtkfeatures.h.in"; \
	for file in $${files}; do					\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|@GTK_MAJOR_VERSION@|${GTK_MAJOR_VERSION}|g" \
			-e "s|@GTK_MINOR_VERSION@|${GTK_MINOR_VERSION}|g" \
			-e "s|@GTK_MICRO_VERSION@|${GTK_MICRO_VERSION}|g" \
			-e "s|@VERSION@|${GTK_VERSION}|g"		\
			$${file}.fixme > $${file};			\
		${RM} $${file}.fixme;					\
	done

# Fix config scripts by removing buildlink directory references.
post-build:
	@cd ${WRKSRC};							\
	config_scripts="gtk-config";					\
	for file in $${config_scripts}; do				\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"	\
			-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"	\
			$${file}.fixme > $${file};			\
		${RM} -f $${file}.fixme;				\
		${CHMOD} +x $${file};					\
	done

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk.m4 \
	  ${LOCALBASE}/share/aclocal/gtk.m4

.include "../../mk/bsd.pkg.mk"
