# $NetBSD: Makefile,v 1.16 2004/10/03 00:18:21 tv Exp $
#

DISTNAME=	Xalan-C_1_6-src
PKGNAME=	xalan-c-1.6
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://archive.apache.org/dist/xml/xalan-c/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xalan-c/
COMMENT=	XSLT processor of the Apache Project

WRKSRC=		${WRKDIR}/xml-xalan/c/src/xalanc
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"
.if ${LOWER_OPSYS} == "SunOS"
XALAN_PLATFORM=	solaris
.elif ${LOWER_OPSYS} == "Darwin"
XALAN_PLATFORM=	macosx
.else
XALAN_PLATFORM=	${LOWER_OPSYS}
.endif
XALAN_ENV=	XALANCROOT="${WRKDIR}/xml-xalan/c" ICUROOT="${LOCALBASE}"

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./runConfigure
CONFIGURE_ARGS+=	-C --prefix=${PREFIX}
CONFIGURE_ARGS+=	-p ${XALAN_PLATFORM}
CONFIGURE_ARGS+=	-t icu
CONFIGURE_ARGS+=	-r pthread
# 1.7.0 needs the following argument.
#CONFIGURE_ARGS+=	-m inmem

CONFIGURE_ENV+=	${XALAN_ENV}
MAKE_ENV+=	${XALAN_ENV}

.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
