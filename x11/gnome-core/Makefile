# $NetBSD: Makefile,v 1.80 2002/09/21 23:11:19 jlam Exp $
#

DISTNAME=		gnome-core-1.4.2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-core/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Base component of GNU Network Object Management Environment

DEPENDS+=		xscreensaver-gnome>=3.25nb1:../xscreensaver-gnome
BUILD_DEPENDS+=		gtk-doc>=0.9:../../textproc/gtk-doc
BUILD_USES_MSGFMT=	YES

.include "../../mk/bsd.prefs.mk"
.if (${LOCALBASE} == ${X11PREFIX})
BUILDLINK_DEPENDS.gnome-pixmaps=gnome{,2}-pixmaps>=1.4.2
.endif

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

LOCALSTATEDIR=		${X11PREFIX}/var/gnome

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}

REPLACE_PERL=		help-browser/gnome-convert help-browser/gnome-download

post-install:
.for prg in gnome-feedback gnome-terminal gpl lgpl fdl
.  for lng in C da de es it no
	[ ! -d ${PREFIX}/share/gnome/help/${prg}/${lng}/figures ] || \
	${RMDIR} ${PREFIX}/share/gnome/help/${prg}/${lng}/figures
.  endfor
.endfor

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../graphics/gnome-pixmaps/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../www/gtkhtml/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
