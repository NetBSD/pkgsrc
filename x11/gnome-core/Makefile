# $NetBSD: Makefile,v 1.57 2001/02/13 11:47:07 tron Exp $

DISTNAME=		gnome-core-1.2.4
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-core/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gdk-pixbuf-gnome>=0.9.0nb1:../../graphics/gdk-pixbuf-gnome
DEPENDS+=		libghttp>=1.0.4:../../www/libghttp
DEPENDS+=		libxml-*:../../textproc/libxml
DEPENDS+=		xscreensaver-gnome>=3.25nb1:../xscreensaver-gnome
BUILD_DEPENDS+=		msgfmt:../../devel/gettext

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
PLIST_SUBST+=		LOCALEDIR=${LOCALEDIR}

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
