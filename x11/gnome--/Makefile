# $NetBSD: Makefile,v 1.7 2002/03/24 21:23:57 rh Exp $
#

DISTNAME=	gnomemm-1.1.19
PKGNAME=	${DISTNAME:S/mm/--/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://prdownloads.sourceforge.net/gtkmm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ binding for the GNOME libraries

BUILD_DEPENDS+=	perl-*:../../lang/perl5

GNU_CONFIGURE=	YES
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes
USE_BUILDLINK_ONLY=	YES
REPLACE_BUILDLINK=	gnomemmConf.sh
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig/scripts

EVAL_PREFIX+=	PERLBASE=perl

post-patch:
	(cd ${WRKSRC}/docgen && ${CP} pce2 pce2.tmp && \
	 ${SED} "s|XXXPERLBASEXXX|${PERLBASE}|" <pce2.tmp >pce2)

.include "../../devel/libsigc++/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../x11/gtk--/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
