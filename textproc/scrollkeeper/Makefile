# $NetBSD: Makefile,v 1.5 2002/04/03 20:38:35 rh Exp $
#

DISTNAME=		scrollkeeper-0.2
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scrollkeeper/}	\
			${MASTER_SITE_GNOME:=stable/sources/scrollkeeper/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://scrollkeeper.sourceforge.net/
COMMENT=		Open Document Cataloging Project

BUILD_USES_MSGFMT=	yes
DEPENDS+=		libxml>=1.8.9:../../textproc/libxml

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBINTL=		yes
USE_X11BASE=		yes

CONFIGURE_ARGS+=	--localstatedir=${X11PREFIX}/var
CONFIGURE_ARGS+=	--sharedstatedir=${X11PREFIX}/var

.include "../../mk/bsd.pkg.mk"
