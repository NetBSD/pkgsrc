# $NetBSD: Makefile,v 1.2.2.1 2006/01/12 23:45:16 salo Exp $
#

DISTNAME=		rxvt-unicode-6.3
CATEGORIES=		x11
MASTER_SITES=		http://dist.schmorp.de/rxvt-unicode/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://software.schmorp.de/pkg/rxvt-unicode
COMMENT=		rxvt clone supporting Xft fonts and Unicode

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c++
USE_TOOLS+=		gmake perl pkg-config

CONFIGURE_ARGS+=	--enable-transparency	\
			--enable-menubar	\
			--enable-xpm-background	\
			--enable-xgetdefault	\
			--with-term=rxvt	\
			--enable-24bit

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
