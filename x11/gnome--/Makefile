# $NetBSD: Makefile,v 1.11 2002/09/11 22:17:10 wiz Exp $
#

DISTNAME=	gnomemm-1.1.19
PKGNAME=	${DISTNAME:S/mm/--/}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmm/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ binding for the GNOME libraries

GNU_CONFIGURE=	YES
USE_PERL5=	build
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
