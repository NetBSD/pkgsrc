# $NetBSD: Makefile,v 1.1.1.1 2001/05/19 10:08:59 drochner Exp $
#

DISTNAME=	gnomemm-1.1.19
PKGNAME=	gnome---1.1.19
CATEGORIES=	x11
MASTER_SITES=	http://prdownloads.sourceforge.net/gtkmm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ binding for the GNOME libraries

DEPENDS+=	gnome-libs-*:../../x11/gnome-libs

GNU_CONFIGURE=	YES
USE_GMAKE=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig/scripts
USE_X11BASE=	yes

EVAL_PREFIX+=	PERLBASE=perl

post-patch:
	(cd ${WRKSRC}/docgen && ${CP} pce2 pce2.tmp && \
	 ${SED} "s|XXXPERLBASEXXX|${PERLBASE}|" <pce2.tmp >pce2)

.include "../../mk/bsd.pkg.mk"
