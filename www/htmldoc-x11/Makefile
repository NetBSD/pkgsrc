# $NetBSD: Makefile,v 1.1.1.1 2002/05/06 21:44:43 seb Exp $
#

PKGNAME=		htmldoc-x11-${HTMLDOC_VERSION}

COMMENT=                Converts HTML to indexed HTML, PDF and/or PostScript (GUI available)

DISTINFO_FILE=	${.CURDIR}/../htmldoc/distinfo
PLIST_SRC=	${.CURDIR}/../htmldoc/PLIST

# defined in Makefile.common but x11.buildlink.mk must pick it up
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-gui --with-x

CONFLICTS=		htmldoc-[0-9]*

.include "../../x11/fltk/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../htmldoc/Makefile.common"
