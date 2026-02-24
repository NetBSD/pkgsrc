# $NetBSD: Makefile,v 1.14 2026/02/24 21:06:53 wiz Exp $

DISTNAME=	cgit-1.3
CATEGORIES=	www
MASTER_SITES=	https://git.zx2c4.com/cgit/snapshot/
EXTRACT_SUFX=	.tar.xz
# cgit builds its own libgit using a known-good version; check
# release notes or Makefile (GIT_VER) when updating the package
GIT_VER=	2.53.0
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} git-${GIT_VER}${EXTRACT_SUFX}
#SITES.git-${GIT_VER}${EXTRACT_SUFX}=	https://www.kernel.org/pub/software/scm/git/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.zx2c4.com/cgit/
COMMENT=	Fast web interface for git
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake perl:test
USE_FEATURES+=		memrchr
MAKE_FLAGS+=		GIT_VER=${GIT_VER}
MAKE_FLAGS+=		PERL_PATH=${PERL5}
BUILD_MAKE_FLAGS+=	CGIT_CONFIG=${PKG_SYSCONFDIR}/cgitrc

MAKE_ENV+=		CGIT_LIBS=${LIBNBCOMPAT_LIBNAME}
MAKE_ENV.SunOS+=	NEEDS_LIBICONV=YesPlease

TEST_TARGET=	test

CGIT_CONFIG=	${PKG_SYSCONFDIR}/cgitrc
CGIT_CGIBIN=	${PREFIX}/libexec/cgi-bin
CGIT_FILTERS=	${PREFIX}/libexec/cgit/filters
CGIT_HTDOCS=	${PREFIX}/share/httpd/htdocs/cgit
CGIT_EGDIR=	${PREFIX}/share/examples

CONF_FILES=		${CGIT_EGDIR}/cgitrc ${CGIT_CONFIG}
INSTALLATION_DIRS=	libexec/cgi-bin \
			libexec/cgit/filters \
			share/httpd/htdocs/cgit \
			share/examples
post-extract:
	rm -r ${WRKSRC}/git && mv ${WRKDIR}/git-${GIT_VER} ${WRKSRC}/git

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cgit ${DESTDIR}${CGIT_CGIBIN}/cgit.cgi
	${INSTALL_DATA} ${WRKSRC}/cgit.png ${DESTDIR}${CGIT_HTDOCS}
	${INSTALL_DATA} ${WRKSRC}/cgit.js ${DESTDIR}${CGIT_HTDOCS}
	${INSTALL_DATA} ${WRKSRC}/cgit.css ${DESTDIR}${CGIT_HTDOCS}
	${INSTALL_DATA} ${WRKSRC}/cgitrc ${DESTDIR}${CGIT_EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/filters/commit-links.sh \
		${DESTDIR}${CGIT_FILTERS}
	${INSTALL_SCRIPT} ${WRKSRC}/filters/syntax-highlighting.sh \
		${DESTDIR}${CGIT_FILTERS}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
