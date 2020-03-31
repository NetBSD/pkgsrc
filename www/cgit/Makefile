# $NetBSD: Makefile,v 1.11 2020/03/31 13:59:32 roy Exp $

DISTNAME=	cgit-1.2.3
CATEGORIES=	www
MASTER_SITES=	https://git.zx2c4.com/cgit/snapshot/
EXTRACT_SUFX=	.tar.xz
# cgit builds its own libgit using a known-good version
# check release notes or README when updating the package
GIT_VER=	2.25.1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} git-${GIT_VER}${EXTRACT_SUFX}
SITES.git-${GIT_VER}${EXTRACT_SUFX}=	http://hjemli.net/git/git/snapshot/

HOMEPAGE=	https://git.zx2c4.com/cgit/
COMMENT=	Fast web interface for git
MAINTAINER=	pkgsrc-users@NetBSD.org
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake
MAKE_FLAGS+=		GIT_VER=${GIT_VER}
BUILD_MAKE_FLAGS+=	CGIT_CONFIG=${PKG_SYSCONFDIR}/cgitrc

MAKE_ENV.SunOS+=	NEEDS_LIBICONV=YesPlease

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
	${INSTALL_DATA} ${WRKSRC}/cgit.png ${DESTDIR}${CGIT_HTDOCS}/cgit.png
	${INSTALL_DATA} ${WRKSRC}/cgit.css ${DESTDIR}${CGIT_HTDOCS}/cgit.css
	${INSTALL_DATA} ${WRKSRC}/cgitrc ${DESTDIR}${CGIT_EGDIR}/cgitrc
	${INSTALL_SCRIPT} ${WRKSRC}/filters/commit-links.sh \
		${DESTDIR}${CGIT_FILTERS}/commit-links.sh
	${INSTALL_SCRIPT} ${WRKSRC}/filters/syntax-highlighting.sh \
		${DESTDIR}${CGIT_FILTERS}/syntax-highlighting.sh

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
