# $NetBSD: Makefile,v 1.59 2001/06/16 19:50:58 jlam Exp $

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

# Fix gtk-config by removing buildlink directory references.
post-build:
	@cd ${WRKSRC};							\
	${MV} -f gtk-config gtk-config.fixme;				\
	${SED}	-e "/^glib/s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"	\
		-e "/^glib/s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"	\
		gtk-config.fixme > gtk-config;				\
	${RM} -f gtk-config.fixme;					\
	${CHMOD} +x gtk-config

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk.m4 \
	  ${LOCALBASE}/share/aclocal/gtk.m4

.include "../../mk/bsd.pkg.mk"
