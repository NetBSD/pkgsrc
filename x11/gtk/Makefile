# $NetBSD: Makefile,v 1.71 2002/07/18 02:19:33 rh Exp $

DISTNAME=		gtk+-1.2.10
PKGREVISION=	2
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
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_X11BASE=		yes
USE_GMAKE=		yes

GNU_CONFIGURE=		 yes
CONFIGURE_ARGS+=	--with-xinput=xfree \
					--sysconfdir=${X11PREFIX}/share
CONFIGURE_ENV+=		X_LDFLAGS="${X_LDFLAGS}"

INFO_FILES=		gdk.info gtk.info

MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

# The following ensures that `gtk-config --libs' includes the correct linker
# flags for linking the X11 libs.
#
X_LDFLAGS=		-Wl,-R${X11BASE}/lib -L${BUILDLINK_X11_DIR}/lib

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

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk.m4 \
	  ${LOCALBASE}/share/aclocal/gtk.m4

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
