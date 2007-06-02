# $NetBSD: Makefile,v 1.1.1.1 2007/06/02 19:07:32 agc Exp $
#

DISTNAME=	metisse-0.4.0-rc4
PKGNAME=	metisse-0.4.0rc4
CATEGORIES=	wm x11
MASTER_SITES=	http://insitu.lri.fr/metisse/download/0.4.0-rc4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://insitu.lri.fr/metisse/
COMMENT=	Window manager with novel features

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt perl
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_GNU_READLINE=	yes	# uses read_history_range append_history
				# history_truncate_file

DEPENDS+=	rxvt>=2.7.10nb5:../../x11/rxvt

.include "../../audio/rplay/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../local/nucleo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
