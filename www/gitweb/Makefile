# $NetBSD: Makefile,v 1.38 2019/08/11 13:24:19 wiz Exp $

PKGREVISION= 1
.include "../../devel/git/Makefile.common"

PKGNAME=	${DISTNAME:S/git/gitweb/}
CATEGORIES=	www

COMMENT=	Web interface for GIT repositories

#DEPENDS+=	apache-[0-9]*:../../www/apache24
DEPENDS+=	git-base>=${GIT_VERSION}:../../devel/git-base
#DEPENDS+=	{perl>=5.15.8,p5-Time-HiRes>=1.9725}:../../time/p5-Time-HiRes
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

USE_TOOLS+=	perl:run

BUILD_DIRS=	gitweb
BUILD_TARGET=	gitweb.cgi static/gitweb.js
MAKE_FLAGS=	prefix=${PREFIX}
MAKE_FLAGS+=	GITWEB_FAVICON=/gitweb/git-favicon.png
MAKE_FLAGS+=	GITWEB_CONFIG=${GITWEB_CONFIG}
MAKE_FLAGS+=	GITWEB_CSS=/gitweb/gitweb.css
MAKE_FLAGS+=	GITWEB_HOMETEXT=${GITWEB_HTDOCS}/indextext.html
MAKE_FLAGS+=	GITWEB_LOGO=/gitweb/git-logo.png
MAKE_FLAGS+=	GITWEB_JS=/gitweb/gitweb.js
MAKE_FLAGS+=	PERL_PATH=${PERL5:Q}

GITWEB_CONFIG=	${PKG_SYSCONFDIR}/gitweb.conf
GITWEB_CGIBIN=	${PREFIX}/libexec/cgi-bin
# Apache wants files in ${PREFIX}/share/httpd/htdocs/gitweb
GITWEB_HTDOCS=	${PREFIX}/share/examples/gitweb/htdocs
GITWEB_EGDIR=	${PREFIX}/share/examples/gitweb

CONF_FILES=	${GITWEB_EGDIR}/gitweb.conf ${PKG_SYSCONFDIR}/gitweb.conf
MESSAGE_SUBST+=	CONFFILE=${PKG_SYSCONFDIR}/gitweb.conf

INSTALLATION_DIRS=	libexec/cgi-bin share/doc/gitweb \
			${GITWEB_EGDIR} ${GITWEB_HTDOCS}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gitweb/gitweb.cgi ${DESTDIR}${GITWEB_CGIBIN}
.for f in git-favicon.png git-logo.png gitweb.css gitweb.js
	${INSTALL_DATA} ${WRKSRC}/gitweb/static/${f} ${DESTDIR}${GITWEB_HTDOCS}
.endfor
	${INSTALL_DATA} ${WRKSRC}/gitweb/README \
		${DESTDIR}${PREFIX}/share/doc/gitweb
	${INSTALL_DATA} ${FILESDIR}/gitweb.conf ${DESTDIR}${GITWEB_EGDIR}

.include "../../mk/bsd.pkg.mk"
