# $NetBSD: Makefile,v 1.12 2011/01/13 13:36:35 wiz Exp $
#

DISTNAME=	libunique-1.1.6
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libunique/1.1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/LibUnique
COMMENT=	Library for writing single instance applications
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake

PKGCONFIG_OVERRIDE+=	unique.pc.in

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=	gtkdoc-rebase

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
