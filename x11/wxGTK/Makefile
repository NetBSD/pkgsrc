# $NetBSD: Makefile,v 1.1.1.2 2000/08/31 22:23:59 dmcmahill Exp $
#

DISTNAME=	wxGTK-2.2.1
CATEGORIES=	x11 devel
MASTER_SITES=	ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/source/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.freiburg.linux.de/~wxxt/

DEPENDS+=	gtk+>=1.2.7:../../x11/gtk

WRKSRC=		${WRKDIR}/wxGTK
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES

CONFIGURE_ARGS+=	--disable-threads

.include "../../mk/bsd.pkg.mk"
