# $NetBSD: Makefile,v 1.21 2004/02/25 17:15:42 minskim Exp $

DISTNAME=	mlterm-2.8.0
PKGNAME=	${DISTNAME}pl1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mlterm/}

PATCHFILES=	${PKGNAME}.tar.gz
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://mlterm.sourceforge.net/
COMMENT=	Multilingual terminal emulator

# CODESET is only supported on NetBSD in 1.5T and later - see <langinfo.h>
ONLY_FOR_PLATFORM=	NetBSD-1.5[T-Z]-* NetBSD-1.5Z[A-Z]-* NetBSD-1.[6-9]*

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-imagelib=imlib
.if exists(${X11BASE}/lib/libXft.a)
CONFIGURE_ARGS+=	--enable-anti-alias
.endif
CONFIGURE_ARGS+=	--without-libiconv-prefix

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in -print | \
	while read f; do \
		${MV} $$f $${f}.orig; \
		${SED} \
		    -e 's|\(-[IL]\)/usr/local|\1${BUILDLINK_DIR}|g' \
		    -e 's|\(-[IL]\)/usr/X11R6|\1${BUILDLINK_X11_DIR}|g' \
		    -e 's|\(-[R]\)/usr/local[^[:space:]][^[:space:]]*||g' \
		    $${f}.orig > $$f; \
	done

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
