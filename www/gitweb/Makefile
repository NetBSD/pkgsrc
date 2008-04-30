# $NetBSD: Makefile,v 1.4 2008/04/30 13:38:16 jmmv Exp $
#

DISTNAME=	git-1.5.0.3
PKGNAME=	${DISTNAME:S/git/gitweb/}
CATEGORIES=	www
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://git.or.cz/
COMMENT=	Web interface for GIT repositories

DEPENDS+=	apache{,2,22}-[0-9]*:../../www/apache22
DEPENDS+=	scm${DISTNAME:S/-/>=/}:../../devel/scmgit

EXTRACT_USING=	gtar
USE_TOOLS+=	gmake perl:run

BUILD_TARGET=	gitweb/gitweb.cgi
MAKE_FLAGS=	prefix=${PREFIX}
MAKE_FLAGS+=	GITWEB_FAVICON=/gitweb/git-favicon.png
MAKE_FLAGS+=	GITWEB_CONFIG=${GITWEB_CONFIG}
MAKE_FLAGS+=	GITWEB_CSS=/gitweb/gitweb.css
MAKE_FLAGS+=	GITWEB_HOMETEXT=${GITWEB_HTDOCS}/indextext.html
MAKE_FLAGS+=	GITWEB_LOGO=/gitweb/git-logo.png
MAKE_FLAGS+=	PERL_PATH=${PERL5:Q}

GITWEB_CONFIG=	${PKG_SYSCONFDIR}/gitweb.conf
GITWEB_CGIBIN=	${PREFIX}/libexec/cgi-bin
GITWEB_HTDOCS=	${PREFIX}/share/httpd/htdocs/gitweb
GITWEB_EGDIR=	${PREFIX}/share/examples/gitweb

CONF_FILES=	${GITWEB_EGDIR}/gitweb.conf ${PKG_SYSCONFDIR}/gitweb.conf
MESSAGE_SUBST+=	CONFFILE=${PKG_SYSCONFDIR}/gitweb.conf

INSTALLATION_DIRS=	libexec/cgi-bin share/httpd/htdocs

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gitweb/gitweb.cgi ${GITWEB_CGIBIN}
	${INSTALL_DATA_DIR} ${GITWEB_HTDOCS}
.for f in git-favicon.png git-logo.png gitweb.css
	${INSTALL_DATA} ${WRKSRC}/gitweb/${f} ${GITWEB_HTDOCS}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gitweb
	${INSTALL_DATA} ${WRKSRC}/gitweb/README \
		${PREFIX}/share/doc/gitweb
	${INSTALL_DATA_DIR} ${GITWEB_EGDIR}
	${INSTALL_DATA} ${FILESDIR}/gitweb.conf ${GITWEB_EGDIR}

.include "../../mk/bsd.pkg.mk"
