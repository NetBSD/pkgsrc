# $NetBSD: Makefile,v 1.74 2002/03/24 20:03:34 rh Exp $

DISTNAME=		gnome-core-1.4.0.6
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-core/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Base component of GNU Network Object Management Environment

DEPENDS+=		xscreensaver-gnome>=3.25nb1:../xscreensaver-gnome
BUILD_USES_MSGFMT=	YES

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LOCALSTATEDIR=		${X11PREFIX}/var/gnome

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}

USE_PERL5=		YES
PERL_SCRIPTS=		help-browser/gnome-convert help-browser/gnome-download

post-patch:
	cd ${WRKSRC}; \
	for FILE in ${PERL_SCRIPTS}; do \
		${CP} $$FILE $${FILE}.orig; \
		${SED} -e 's#/usr/bin/perl#${PERL5}#g' \
			<$${FILE}.orig >$$FILE; \
	done

post-install:
.for prg in gnome-feedback gnome-terminal gpl lgpl fdl
.for lng in C da de es it no
	[ ! -d ${PREFIX}/share/gnome/help/${prg}/${lng}/figures ] || \
	${RMDIR} ${PREFIX}/share/gnome/help/${prg}/${lng}/figures
.endfor
.endfor

.include "../../archivers/bzip2/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../www/gtkhtml/buildlink.mk"
.include "../../www/libghttp/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
