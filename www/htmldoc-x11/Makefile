# $NetBSD: Makefile,v 1.3 2004/03/26 02:27:57 wiz Exp $
#

.include "../htmldoc/Makefile.common"

PKGNAME=	htmldoc-x11-${HTMLDOC_VERSION}
PKGREVISION=	1
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript (GUI available)

CONFLICTS=		htmldoc-[0-9]*

USE_X11=		# defined
CONFIGURE_ARGS+=	--with-gui --with-x

.include "../../x11/fltk/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
