# $NetBSD: Makefile,v 1.54 2001/04/26 17:42:54 rh Exp $

DISTNAME=		gtk+-1.2.10
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v1.2/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.2/ \
			http://www.ameth.org/gimp/pub/gtk/v1.2/ \
			ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/v1.2/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gtk.org/
COMMENT=		Gimp toolkit. Libraries for building X11 user interfaces

DEPENDS+=		glib>=1.2.10:../../devel/glib
BUILD_DEPENDS+=		perl-5.*:../../lang/perl5
BUILD_USES_MSGFMT=	yes

USE_LIBINTL=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_X11BASE=		yes
USE_GMAKE=		yes

GNU_CONFIGURE=		 yes
CONFIGURE_ARGS+=	--with-xinput=xfree
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" X_LDFLAGS="${X_LDFLAGS}"

INFO_FILES=		gdk.info gtk.info

CPPFLAGS=		-I${LOCALBASE}/include			   # libintl.h
LDFLAGS=		-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib  # -lintl
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

# The following ensures that `gtk-config --libs' includes the correct linker
# flags for linking the X11 libs.
#
X_LDFLAGS=		-Wl,-R${X11BASE}/lib -L${X11BASE}/lib

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk.m4 \
	  ${LOCALBASE}/share/aclocal/gtk.m4

.include "../../mk/bsd.pkg.mk"
