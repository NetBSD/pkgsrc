# $NetBSD: Makefile,v 1.10 2003/05/05 19:05:25 jmmv Exp $
#

DISTNAME=		gtk-engines-2.2.0
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+ version 2

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_X11=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
