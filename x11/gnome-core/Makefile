# $NetBSD: Makefile,v 1.63 2001/04/24 18:07:14 rh Exp $

DISTNAME=		gnome-core-1.4.0.2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-core/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Base component of GNU Network Object Management Environment

DEPENDS+=		gdk-pixbuf-gnome>=0.9.0nb1:../../graphics/gdk-pixbuf-gnome
DEPENDS+=		libghttp>=1.0.9:../../www/libghttp
DEPENDS+=		libxml-*:../../textproc/libxml
DEPENDS+=		xscreensaver-gnome>=3.25nb1:../xscreensaver-gnome
DEPENDS+=		libglade>=0.14:../../devel/libglade
DEPENDS+=		gtkhtml>=0.8.3:../../www/gtkhtml
BUILD_USES_MSGFMT=	YES

USE_LIBINTL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LOCALSTATEDIR=		/var/gnome

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}
CPPFLAGS+=		-I${LOCALBASE}/include	# libintl.h
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

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
.for prg in gnome-terminal gpl lgpl fdl
.for lng in C da de es it no
	[ ! -d ${PREFIX}/share/gnome/help/${prg}/${lng}/figures ] || \
	${RMDIR} ${PREFIX}/share/gnome/help/${prg}/${lng}/figures
.endfor
.endfor

.include "../../mk/bsd.pkg.mk"
