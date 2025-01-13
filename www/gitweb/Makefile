# $NetBSD: Makefile,v 1.47 2025/01/13 14:24:44 adam Exp $

.include "../../devel/git/Makefile.common"

PKGNAME=	${DISTNAME:S/git/gitweb/}
CATEGORIES=	www

COMMENT=	Web interface for GIT repositories

DEPENDS+=	git-base>=${GIT_VERSION}:../../devel/git-base
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

USE_TOOLS+=	perl:run

BUILD_TARGET=	gitweb
INSTALL_TARGET=	install-gitweb
MAKE_ENV+=	INSTALL=${INSTALL:Q}
REPLACE_PERL+=	gitweb/gitweb.perl

GITWEB_EGDIR=	${PREFIX}/share/examples/gitweb
CONF_FILES=	${GITWEB_EGDIR}/gitweb.conf ${PKG_SYSCONFDIR}/gitweb.conf
MESSAGE_SUBST+=	CONFFILE=${PKG_SYSCONFDIR}/gitweb.conf

INSTALLATION_DIRS=	${GITWEB_EGDIR}

post-install:
	${INSTALL_DATA} ${FILESDIR}/gitweb.conf ${DESTDIR}${GITWEB_EGDIR}

.include "../../mk/bsd.pkg.mk"
