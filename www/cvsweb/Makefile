#
# $NetBSD: Makefile,v 1.9 2001/12/17 22:11:46 jlam Exp $
#

DISTNAME=		cvsweb-1.112
CATEGORIES=		net
MASTER_SITES=		http://stud.fh-heilbronn.de/~zeller/download/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://stud.fh-heilbronn.de/~zeller/cgi/cvsweb.cgi/
COMMENT=		Web interface for browsing a CVS repository

USE_BUILDLINK_ONLY=	YES
WRKSRC=			${WRKDIR}/cvsweb

PKG_SYSCONFSUBDIR?=	httpd
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=	${EGDIR}/cvsweb.conf.default ${PKG_SYSCONFDIR}/cvsweb.conf

do-build:
	${MV} ${WRKSRC}/cvsweb.cgi ${WRKSRC}/cvsweb.cgi.bak
	${SED}	-e 's,/usr/bin/perl,${PERL5},'				\
		-e 's,/usr/local/web/apache/conf/,${PKG_SYSCONFDIR}/,'	\
		${WRKSRC}/cvsweb.cgi.bak > ${WRKSRC}/cvsweb.cgi

do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/libexec/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${PREFIX}/libexec/cgi-bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cvsweb
	${INSTALL_DATA} ${WRKSRC}/cvsweb.conf \
		${PREFIX}/share/examples/cvsweb/cvsweb.conf.default

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
