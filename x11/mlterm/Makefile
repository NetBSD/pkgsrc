# $NetBSD: Makefile,v 1.18 2004/01/24 15:30:33 grant Exp $

DISTNAME=	mlterm-2.7.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mlterm/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://mlterm.sourceforge.net/
COMMENT=	Multilingual terminal emulator

# CODESET is only supported on NetBSD in 1.5T and later - see <langinfo.h>
ONLY_FOR_PLATFORM=	NetBSD-1.5[T-Z]-* NetBSD-1.5Z[A-Z]-* NetBSD-1.[6-9]*

USE_BUILDLINK2=		yes
USE_X11=		yes

USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
LIBTOOL_OVERRIDE+=	${WRKSRC}/mkf/autoconf/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/autoconf/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/kiklib/autoconf/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-imagelib=imlib
.if exists(${X11BASE}/lib/libXft.a)
CONFIGURE_ARGS+=	--enable-anti-alias
.endif
CONFIGURE_ARGS+=	--without-libiconv-prefix

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | \
	while read f; do \
		${MV} $$f $${f}.orig; \
		${SED} \
		    -e 's|\(-[IL]\)/usr/local|\1${BUILDLINK_DIR}|g' \
		    -e 's|\(-[IL]\)/usr/X11R6|\1${BUILDLINK_X11_DIR}|g' \
		    -e 's|\(-[R]\)/usr/local[^[:space:]][^[:space:]]*||g' \
		    $${f}.orig > $$f; \
	done

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
