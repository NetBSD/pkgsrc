#
# $NetBSD: Makefile,v 1.19 2004/05/28 01:47:26 lukem Exp $
#

DISTNAME=		cvsweb-3.0.1
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.freebsd.org/pub/FreeBSD/ports/local-distfiles/scop/

MAINTAINER=		lukem@NetBSD.org
HOMEPAGE=		http://www.freebsd.org/projects/cvsweb.html
COMMENT=		Web interface for browsing a CVS repository

DEPENDS+=		p5-File-Temp>=0.12:../../devel/p5-File-Temp
DEPENDS+=		p5-IPC-Run>=0.74:../../devel/p5-IPC-Run
DEPENDS+=		p5-MIME-Types>=1.12:../../mail/p5-MIME-Types
DEPENDS+=		p5-URI>=1.30:../../www/p5-URI

NO_BUILDLINK=		YES
USE_PERL5=		# defined
USE_PKGINSTALL=		YES

PERL5_REQD+=		5.6
REPLACE_PERL=		cvsweb.cgi

PKG_SYSCONFSUBDIR?=	httpd
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

CVSWEB_CONF_FILES=	cvsweb.conf \
			cvsweb.conf-freebsd \
			cvsweb.conf-netbsd \
			cvsweb.conf-openbsd \
			cvsweb.conf-ruby

CVSWEB_CSS=		cvsweb.css

CVSWEB_ICONS=		back.gif binary.gif dir.gif \
			miniback.gif minidir.gif minigraph.png minitext.gif \
			text.gif

CVSWEB_DOCS=		ChangeLog INSTALL NEWS README TODO

CONF_FILES=		${EGDIR}/cvsweb.conf ${PKG_SYSCONFDIR}/cvsweb.conf

.if !exists(/usr/bin/rlog)
DEPENDS+=		rcs-[0-9]*:../../devel/rcs
.endif

do-build:

do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/libexec/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${PREFIX}/libexec/cgi-bin
	${INSTALL_DATA_DIR} ${EGDIR}
.for f in ${CVSWEB_CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${EGDIR}/${f}
.endfor
	${INSTALL_DATA_DIR} ${EGDIR}/icons
.for f in ${CVSWEB_ICONS}
	${INSTALL_DATA} ${WRKSRC}/icons/${f} ${EGDIR}/icons/${f}
.endfor
	${INSTALL_DATA_DIR} ${EGDIR}/css
.for f in ${CVSWEB_CSS}
	${INSTALL_DATA} ${WRKSRC}/css/${f} ${EGDIR}/css/${f}
.endfor
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${CVSWEB_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
