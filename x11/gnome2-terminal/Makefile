# $NetBSD: Makefile,v 1.15 2003/12/28 23:37:07 jmmv Exp $
#

DISTNAME=		gnome-terminal-2.0.2
PKGNAME=		${DISTNAME:S/-/2-/}
PKGREVISION=		4
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-terminal/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Xterm like terminal program for GNOME 2

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

CONFLICTS=		gnome-core-[0-9]*

USE_PERL5=		build
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCONF2_SCHEMAS= 	gnome-terminal.schemas

.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/libzvt/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
