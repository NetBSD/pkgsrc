# $NetBSD: Makefile,v 1.15 2026/05/12 18:29:24 wiz Exp $

DISTNAME=	cgit-1.3
PKGREVISION=	1
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

TOOL_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=		bash:run gmake perl:test
USE_FEATURES+=		memrchr
MAKE_FLAGS+=		GIT_VER=${GIT_VER}
MAKE_FLAGS+=		PERL_PATH=${PERL5}
MAKE_FLAGS+=		CGIT_SCRIPT_PATH=${CGIT_CGIBIN}
MAKE_FLAGS+=		CGIT_DATA_PATH=${CGIT_HTDOCS}
MAKE_FLAGS+=		filterdir=${CGIT_FILTERS}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		PYTHON_PATH=${PYTHONBIN}
BUILD_MAKE_FLAGS+=	CGIT_CONFIG=${PKG_SYSCONFDIR}/cgitrc

MAKE_ENV+=		CGIT_LIBS=${LIBNBCOMPAT_LIBNAME}
MAKE_ENV.SunOS+=	NEEDS_LIBICONV=YesPlease

BUILD_TARGET=	all doc-man
INSTALL_TARGET=	install install-man
TEST_TARGET=	test

CGIT_CONFIG=	${PKG_SYSCONFDIR}/cgitrc
CGIT_CGIBIN=	${PREFIX}/libexec/cgi-bin
CGIT_FILTERS=	${PREFIX}/libexec/cgit/filters
CGIT_HTDOCS=	${PREFIX}/share/httpd/htdocs/cgit
CGIT_EGDIR=	${PREFIX}/share/examples/cgit

CONF_FILES=		${CGIT_EGDIR}/cgitrc ${CGIT_CONFIG}
INSTALLATION_DIRS+=	share/examples/cgit

REPLACE_BASH+=		filters/html-converters/rst2html
REPLACE_PYTHON+=	filters/email-gravatar.py
REPLACE_PYTHON+=	filters/syntax-highlighting.py
REPLACE_PYTHON+=	filters/html-converters/md2html

post-extract:
	rm -r ${WRKSRC}/git && mv ${WRKDIR}/git-${GIT_VER} ${WRKSRC}/git

post-install:
	${INSTALL_DATA} ${WRKSRC}/cgitrc ${DESTDIR}${CGIT_EGDIR}

.include "../../lang/python/tool.mk"
.include "../../lang/python/application.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
