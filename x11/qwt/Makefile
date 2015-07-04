# $NetBSD: Makefile,v 1.38 2015/07/04 16:18:42 joerg Exp $

DISTNAME=	qwt-5.0.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qwt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/qwt/
COMMENT=	Qt widget library for technical purposes

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

CONFLICTS=	qwtlib-[0-9]*

AUTO_MKDIRS=		yes

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR:Q}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} qmake

.include "../../x11/qt3/application.mk"
.include "../../mk/bsd.pkg.mk"
