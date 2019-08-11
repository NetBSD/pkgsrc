# $NetBSD: Makefile,v 1.25 2019/08/11 13:24:18 wiz Exp $
#

DISTNAME=		drraw-2.2b2
PKGREVISION=		7
CATEGORIES=		databases graphics www
MASTER_SITES=		http://web.taranis.org/drraw/dist/

MAINTAINER=		kleink@NetBSD.org
HOMEPAGE=		http://web.taranis.org/drraw/
COMMENT=		Simple web based presentation front-end for RRDtool

NO_BUILD=		yes
USE_TOOLS+=		perl:run

REPLACE_PERL=		drraw.cgi

PKG_SYSCONFSUBDIR?=	drraw
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

DRRAW_CONF_FILES=	drraw.conf

DRRAW_ICONS=		bomb.gif folder.gif folder.open.gif generic.gif \
			link.gif text.gif unknown.gif

DRRAW_DOCS=		CHANGES INSTALL LICENSE README.EVENTS

CONF_FILES=		${EGDIR}/drraw.conf ${PKG_SYSCONFDIR}/drraw.conf

DEPENDS+=		rrdtool>=1.2.9:../../databases/rrdtool

INSTALLATION_DIRS=	libexec/cgi-bin ${EGDIR}/icons ${DOCDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/drraw.cgi ${DESTDIR}${PREFIX}/libexec/cgi-bin
.for f in ${DRRAW_CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${EGDIR}/${f}
.endfor
.for f in ${DRRAW_ICONS}
	${INSTALL_DATA} ${WRKSRC}/icons/${f} ${DESTDIR}${EGDIR}/icons/${f}
.endfor
.for f in ${DRRAW_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}/${f}
.endfor

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	drraw.cgi
SUBST_VARS.prefix=	PKG_SYSCONFDIR
SUBST_MESSAGE.prefix=	Fixing harcoded paths.

.include "../../mk/bsd.pkg.mk"
