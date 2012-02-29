# $NetBSD: Makefile,v 1.10 2012/02/29 21:19:02 apb Exp $
#

.include "../../devel/scmgit/Makefile.version"

DISTNAME=	git-${GIT_VERSION}
PKGNAME=	${DISTNAME:S/git/gitweb/}
CATEGORIES=	www
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://git.or.cz/
COMMENT=	Web interface for GIT repositories

PKG_DESTDIR_SUPPORT=	user-destdir

#DEPENDS+=	apache{,2,22}-[0-9]*:../../www/apache22
DEPENDS+=	scmgit-base>=${GIT_VERSION}:../../devel/scmgit-base

#EXTRACT_USING=	gtar
USE_TOOLS+=	gmake perl:run

BUILD_DIRS=	gitweb
BUILD_TARGET=	gitweb.cgi
MAKE_FLAGS=	prefix=${PREFIX}
MAKE_FLAGS+=	GITWEB_FAVICON=/gitweb/git-favicon.png
MAKE_FLAGS+=	GITWEB_CONFIG=${GITWEB_CONFIG}
MAKE_FLAGS+=	GITWEB_CSS=/gitweb/gitweb.css
MAKE_FLAGS+=	GITWEB_HOMETEXT=${GITWEB_HTDOCS}/indextext.html
MAKE_FLAGS+=	GITWEB_LOGO=/gitweb/git-logo.png
MAKE_FLAGS+=	PERL_PATH=${PERL5:Q}

GITWEB_CONFIG=	${PKG_SYSCONFDIR}/gitweb.conf
GITWEB_CGIBIN=	${PREFIX}/libexec/cgi-bin
# Apache wants files in ${PREFIX}/share/httpd/htdocs/gitweb
GITWEB_HTDOCS=	${PREFIX}/share/examples/gitweb/htdocs
GITWEB_EGDIR=	${PREFIX}/share/examples/gitweb

CONF_FILES=	${GITWEB_EGDIR}/gitweb.conf ${PKG_SYSCONFDIR}/gitweb.conf
MESSAGE_SUBST+=	CONFFILE=${PKG_SYSCONFDIR}/gitweb.conf

INSTALLATION_DIRS=	libexec/cgi-bin \
			share/doc/gitweb \
			${GITWEB_EGDIR} ${GITWEB_HTDOCS}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gitweb/gitweb.cgi ${DESTDIR}${GITWEB_CGIBIN}
.for f in git-favicon.png git-logo.png gitweb.css
	${INSTALL_DATA} ${WRKSRC}/gitweb/static/${f} ${DESTDIR}${GITWEB_HTDOCS}
.endfor
	${INSTALL_DATA} ${WRKSRC}/gitweb/README \
		${DESTDIR}${PREFIX}/share/doc/gitweb
	${INSTALL_DATA} ${FILESDIR}/gitweb.conf ${DESTDIR}${GITWEB_EGDIR}

.include "../../mk/bsd.pkg.mk"
