# $NetBSD: Makefile,v 1.2 2002/01/03 14:47:17 wiz Exp $
#

DISTNAME=		gdkxft-1.0
CATEGORIES=		x11
MASTER_SITES=		http://philrsss.anu.edu.au/~josh/gdkxft/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://philrsss.anu.edu.au/~josh/gdkxft/
COMMENT=		transparently add anti-aliased font support to gtk+ applications

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/lib/libXft.a)
IGNORE=			"${PKGNAME} requires XFree86-4.0 or higher"
.endif

GNU_CONFIGURE=		YES
USE_PERL5=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_BUILDLINK_ONLY=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gdkxft
.for doc in AUTHORS COPYING ChangeLog INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/gdkxft
.endfor

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
