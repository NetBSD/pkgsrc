# $NetBSD: Makefile,v 1.52 2022/06/28 11:37:03 wiz Exp $
#

DISTNAME=		cvsweb-3.0.6
PKGREVISION=		13
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.freebsd.org/pub/FreeBSD/ports/local-distfiles/scop/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.freebsd.org/projects/cvsweb.html
COMMENT=		Web interface for browsing a CVS repository

#DEPENDS+=		{perl>=5.6.1,p5-File-Temp>=0.12}:../../devel/p5-File-Temp
DEPENDS+=		p5-IPC-Run>=0.74:../../devel/p5-IPC-Run
DEPENDS+=		p5-MIME-Types>=1.12:../../mail/p5-MIME-Types
DEPENDS+=		p5-URI>=1.30:../../www/p5-URI

.if !exists(/usr/bin/rlog)
DEPENDS+=		rcs-[0-9]*:../../devel/rcs
.endif

NO_BUILD=		YES
USE_TOOLS+=		perl:run

REPLACE_PERL=		cvsweb.cgi

PKG_SYSCONFSUBDIR?=	cvsweb
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

INSTALLATION_DIRS=	libexec/cgi-bin ${EGDIR}/icons ${EGDIR}/css ${DOCDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${DESTDIR}${PREFIX}/libexec/cgi-bin
.for f in ${CVSWEB_CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${EGDIR}/${f}
.endfor
.for f in ${CVSWEB_ICONS}
	${INSTALL_DATA} ${WRKSRC}/icons/${f} ${DESTDIR}${EGDIR}/icons/${f}
.endfor
.for f in ${CVSWEB_CSS}
	${INSTALL_DATA} ${WRKSRC}/css/${f} ${DESTDIR}${EGDIR}/css/${f}
.endfor
.for f in ${CVSWEB_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}/${f}
.endfor

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	cvsweb.conf cvsweb.cgi INSTALL
SUBST_SED.prefix=	-e "s,/usr/local/etc/apache,${PKG_SYSCONFBASE}/httpd,g"
SUBST_SED.prefix+=	-e "s,/usr/local/etc/cvsweb,${PKG_SYSCONFDIR},g"
SUBST_SED.prefix+=	-e "s,/usr/local/bin,${LOCALBASE}/bin,g"
SUBST_MESSAGE.prefix=	Fixing hardcoded paths.

.include "../../mk/bsd.pkg.mk"
