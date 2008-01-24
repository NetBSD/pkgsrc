# $NetBSD: Makefile,v 1.24 2008/01/24 07:17:33 xtraeme Exp $
#

DISTNAME=	Xalan-C_1_10_0-src
PKGNAME=	xalan-c-1.10
#PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://archive.apache.org/dist/xml/xalan-c/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xalan-c/
COMMENT=	XSLT processor of the Apache Project

WRKSRC=		${WRKDIR}/xml-xalan/c
USE_TOOLS+=	gmake
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
CONFIGURE_ARGS+=	-C --prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	-p ${XALAN_PLATFORM}
CONFIGURE_ARGS+=	-t icu
CONFIGURE_ARGS+=	-r pthread
# 1.7.0 needs the following argument.
#CONFIGURE_ARGS+=	-m inmem

CONFIGURE_ENV+=	${XALAN_ENV}
MAKE_ENV+=	${XALAN_ENV}

pre-configure:
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}

.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
