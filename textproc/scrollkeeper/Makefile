# $NetBSD: Makefile,v 1.8 2002/10/19 10:54:58 rh Exp $
#

DISTNAME=		scrollkeeper-0.2
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scrollkeeper/}	\
			${MASTER_SITE_GNOME:=sources/scrollkeeper/0.2/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://scrollkeeper.sourceforge.net/
COMMENT=		Open Document Cataloging Project

BUILD_USES_MSGFMT=	yes
USE_GMAKE=		yes
USE_X11BASE=		yes
USE_BUILDLINK2=		yes

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${X11PREFIX}/var
CONFIGURE_ARGS+=	--sharedstatedir=${X11PREFIX}/var

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
