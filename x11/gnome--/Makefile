# $NetBSD: Makefile,v 1.5 2002/02/14 13:50:44 drochner Exp $
#

DISTNAME=	gnomemm-1.1.19
PKGNAME=	gnome---1.1.19
CATEGORIES=	x11
MASTER_SITES=	http://prdownloads.sourceforge.net/gtkmm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ binding for the GNOME libraries

DEPENDS+=	gnome-libs-[0-9]*:../../x11/gnome-libs
DEPENDS+=	libsigc++>=1.0.1:../../devel/libsigc++
DEPENDS+=	gtk-->=1.2.5:../../x11/gtk--
BUILD_DEPENDS+=	perl-*:../../lang/perl5

GNU_CONFIGURE=	YES
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig/scripts
USE_X11BASE=	yes

EVAL_PREFIX+=	PERLBASE=perl

post-patch:
	(cd ${WRKSRC}/docgen && ${CP} pce2 pce2.tmp && \
	 ${SED} "s|XXXPERLBASEXXX|${PERLBASE}|" <pce2.tmp >pce2)

.include "../../mk/bsd.pkg.mk"
