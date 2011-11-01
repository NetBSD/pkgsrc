# $NetBSD: Makefile,v 1.31 2011/11/01 06:02:43 sbd Exp $
#

DISTNAME=	ratpoison-1.4.5
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://savannah.nongnu.org/download/ratpoison/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/ratpoison/
COMMENT=	Simple window manager with no fat library dependencies

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES
INFO_FILES=		yes

USE_TOOLS+=	perl:run pkg-config autoconf
REPLACE_PERL+=	contrib/rpws contrib/genrpbindings contrib/clickframe.pl
REPLACE_SH=	contrib/allwindows.sh

BUILDLINK_DEPMETHOD.libXt?=	build

pre-configure:
	cd ${WRKSRC}; autoconf

.include "../../devel/readline/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
