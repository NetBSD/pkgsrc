# $NetBSD: Makefile,v 1.6 2004/10/03 00:18:26 tv Exp $
#

.include "../htmldoc/Makefile.common"

PKGNAME=	htmldoc-x11-${HTMLDOC_VERSION}
PKGREVISION=	3
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript (GUI available)

CONFLICTS=		htmldoc-[0-9]*

USE_X11=		# defined
CONFIGURE_ARGS+=	--with-gui --with-x

.include "../../x11/fltk/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
