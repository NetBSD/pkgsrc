#
# $NetBSD: Makefile,v 1.11 2002/06/27 03:22:22 lukem Exp $
#

DISTNAME=		cvsweb-2.0.3
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.freebsd.org/pub/FreeBSD/ports/local-distfiles/knu/

MAINTAINER=		lukem@netbsd.org
HOMEPAGE=		http://www.freebsd.org/cgi/cvsweb.cgi/projects/cvsweb/
COMMENT=		Web interface for browsing a CVS repository

USE_BUILDLINK_ONLY=	YES

PKG_SYSCONFSUBDIR?=	httpd
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

CVSWEB_CONF_FILES=	cvsweb.conf \
			cvsweb.conf-freebsd \
			cvsweb.conf-netbsd \
			cvsweb.conf-openbsd \
			cvsweb.conf-ruby

CVSWEB_ICONS=		back.gif dir.gif \
			miniback.gif minidir.gif minitext.gif text.gif

CVSWEB_DOCS=		ChangeLog INSTALL README README.FreeBSD \
			TODO TODO.FreeBSD

CONF_FILES=		${EGDIR}/cvsweb.conf ${PKG_SYSCONFDIR}/cvsweb.conf

.if !exists(/usr/bin/rlog)
DEPENDS+=	rcs-[0-9]*:../../devel/rcs
.endif

do-build:
	${MV} ${WRKSRC}/cvsweb.cgi ${WRKSRC}/cvsweb.cgi.bak
	${SED}	-e 's,/usr/bin/perl,${PERL5},'				\
		-e 's,/usr/local/etc/cvsweb/,${PKG_SYSCONFDIR}/,'	\
		${WRKSRC}/cvsweb.cgi.bak > ${WRKSRC}/cvsweb.cgi

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
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${CVSWEB_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}/${f}
.endfor

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
