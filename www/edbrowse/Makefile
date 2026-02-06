# $NetBSD: Makefile,v 1.3 2026/02/06 10:06:06 wiz Exp $

DISTNAME=	edbrowse-3.8.15
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=CMB/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://edbrowse.org/
COMMENT=	Command Line Editor & Browser
LICENSE=	gnu-gpl-v2 AND mit

USE_TOOLS+=	gmake perl:build
USE_LANGUAGES=	c c++

CPPFLAGS+=	-DQ_NG=0 	# use standard quickjs

NO_CONFIGURE=	yes

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-extract
SUBST_MESSAGE.man=	Fixing paths in man page
SUBST_FILES.man=	doc/*.1
SUBST_SED.man=		-e '/usersguide\.html/ s,/usr,${PREFIX},g'

MAKE_FILE=		makefile

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS=		require

BUILDLINK_TRANSFORM+=	rm:-lpthread rm:-Wall \
			opt:-ldl:${BUILDLINK_LDADD.dl:Q} \
			opt:-lopenssl:${BUILDLINK_LDADD.openssl:Q}

MAKE_FLAGS+=		QUICKJS_INCLUDE=${PREFIX}/include/quickjs \
			QUICKJS_LIB=${PREFIX}/lib \
			QUICKJS_LIB_NAME=quickjs

EGDIR=			share/examples/${PKGBASE}
DOCDIR=			share/doc/${PKGBASE}

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man-edbrowse-freebsd.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}.1
	${INSTALL_PROGRAM} ${WRKSRC}/src/edbrowse	\
		${DESTDIR}${PREFIX}/bin

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/sample.ebrc	\
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/usersguide.html	\
		${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/quickjs/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
