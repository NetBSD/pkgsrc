# $NetBSD: Makefile,v 1.53 2000/11/07 04:39:13 rh Exp $

DISTNAME=		gnome-core-1.2.3
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-core/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gdk-pixbuf>=0.7.0:../../graphics/gdk-pixbuf
DEPENDS+=		libghttp>=1.0.4:../../www/libghttp
DEPENDS+=		libxml-*:../../textproc/libxml
DEPENDS+=		xscreensaver-gnome>=3.25nb1:../xscreensaver-gnome

USE_X11BASE=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LOCALSTATEDIR=		/var/gnome

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}
CPPFLAGS+=		-I${LOCALBASE}/include	# libintl.h
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

USE_PERL5=		# defined
PERL_SCRIPTS=		help-browser/gnome-convert help-browser/gnome-download

post-patch:
	cd ${WRKSRC}; \
	for FILE in ${PERL_SCRIPTS}; do \
		${CP} $$FILE $${FILE}.orig; \
		${SED} -e 's#/usr/bin/perl#${PERL5}#g' \
			<$${FILE}.orig >$$FILE; \
	done

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gnome-terminal/C/figures
	${RMDIR} ${PREFIX}/share/gnome/help/gnome-terminal/da/figures
	${RMDIR} ${PREFIX}/share/gnome/help/gnome-terminal/es/figures
	${RMDIR} ${PREFIX}/share/gnome/help/gnome-terminal/it/figures
	${RMDIR} ${PREFIX}/share/gnome/help/gnome-terminal/no/figures
	${RMDIR} ${PREFIX}/share/gnome/help/session/C/figures

.include "../../mk/bsd.pkg.mk"
