# $NetBSD: Makefile,v 1.4 2002/03/15 11:23:16 uebayasi Exp $

DISTNAME=	mlterm-2.3.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mlterm/}

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://mlterm.sourceforge.net/
COMMENT=	Multingual terminal emulator

# CODESET is only supported on NetBSD in 1.5T and later - see <langinfo.h>
ONLY_FOR_PLATFORM=	NetBSD-1.5[T-Z]-* NetBSD-1.5Z[A-Z]-*

USE_BUILDLINK_ONLY=	yes

GNU_CONFIGURE=	yes

USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE+=	${WRKSRC}/mkf/autoconf/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/autoconf/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/kiklib/autoconf/libtool

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | \
	while read f; do \
		${MV} $$f $${f}.orig; \
		${SED} -e 's|\(-[ILR]\)/usr/local|\1${LOCALBASE}|g' \
		    -e 's|\(-[ILR]\)/usr/X11R6|\1${X11BASE}|g' \
		    $${f}.orig > $$f; \
	done

.include "../../devel/glib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
