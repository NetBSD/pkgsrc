# $NetBSD: Makefile,v 1.3 2007/02/26 14:56:30 joerg Exp $
#

DISTNAME=	xmlrpc-c-1.09.00
PKGREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlrpc-c/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmlrpc-c.sourceforge.net/
COMMENT=	Library for writing an XML-RPC server or client in C or C++

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

SUBST_CLASSES+=	pthread
SUBST_FILES.pthread=	xmlrpc-c-config.in xmlrpc-c-config.test.in
PTHREAD_LINKFLAGS=	${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}
SUBST_SED.pthread=	-e s/-lpthread/${PTHREAD_LINKFLAGS:Q}/
SUBST_STAGE.pthread=	post-patch

.include "../../www/libwww/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
