# $NetBSD: Makefile,v 1.4 2004/04/13 09:38:39 xtraeme Exp $
#

.include "../htmldoc/Makefile.common"

PKGNAME=	htmldoc-x11-${HTMLDOC_VERSION}
PKGREVISION=	2
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript (GUI available)

CONFLICTS=		htmldoc-[0-9]*

USE_X11=		# defined
CONFIGURE_ARGS+=	--with-gui --with-x

.include "../../x11/fltk/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
