# $NetBSD: Makefile,v 1.9 2007/04/14 19:32:58 kleink Exp $
#

DISTNAME=		drraw-2.2a3
CATEGORIES=		databases graphics www
MASTER_SITES=		http://web.taranis.org/drraw/dist/
EXTRACT_SUFX=		.tgz

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

DRRAW_DOCS=		CHANGES INSTALL README.EVENTS WISHLIST

CONF_FILES=		${EGDIR}/drraw.conf ${PKG_SYSCONFDIR}/drraw.conf

DEPENDS+=		rrdtool>=1.2.9:../../databases/rrdtool

do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/libexec/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/drraw.cgi ${PREFIX}/libexec/cgi-bin
	${INSTALL_DATA_DIR} ${EGDIR}
.for f in ${DRRAW_CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${EGDIR}/${f}
.endfor
	${INSTALL_DATA_DIR} ${EGDIR}/icons
.for f in ${DRRAW_ICONS}
	${INSTALL_DATA} ${WRKSRC}/icons/${f} ${EGDIR}/icons/${f}
.endfor
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${DRRAW_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}/${f}
.endfor

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	drraw.cgi
SUBST_SED.prefix=	-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g"
SUBST_MESSAGE.prefix=	Fixing harcoded paths.

.include "../../mk/bsd.pkg.mk"
