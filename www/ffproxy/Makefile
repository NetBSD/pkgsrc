# $NetBSD: Makefile,v 1.6 2025/06/15 16:55:15 taca Exp $

DISTNAME=	ffproxy-1.6
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://faith.eu.org/ffproxy/

MAINTAINER=	niklas@noxa.de
HOMEPAGE=	http://faith.eu.org/programs.html\#ffproxy
COMMENT=	Filtering HTTP/HTTPS proxy server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

EGDIR=		share/examples/ffproxy
FFPDIR=		share/ffproxy

CONFIGS=	access.dyndns access.host access.ip filter.header.add \
		filter.header.drop filter.header.entry filter.header.match \
		filter.host.match filter.rheader.drop filter.rheader.entry \
		filter.rheader.match filter.url.match

CONF_FILES=	${PREFIX}/${EGDIR}/ffproxy.conf ${PKG_SYSCONFDIR}/ffproxy.conf
.for f in ${CONFIGS}
CONF_FILES+=	${PREFIX}/${EGDIR}/db/${f} ${PREFIX}/${FFPDIR}/db/${f}
.endfor
OWN_DIRS+=	${FFPDIR}/db

RCD_SCRIPTS=			ffproxy

PLIST_SUBST+=		EGDIR=${EGDIR} FFPDIR=${FFPDIR}
PRINT_PLIST_AWK+=	/^${EGDIR:S|/|\\/|g}/ \
			{ gsub(/${EGDIR:S|/|\\/|g}/, "$${EGDIR}") }
PRINT_PLIST_AWK+=	/^${FFPDIR:S|/|\\/|g}/ \
			{ gsub(/${FFPDIR:S|/|\\/|g}/, "$${FFPDIR}") }

INSTALLATION_DIRS+=	${EGDIR}/db

.include "../../mk/bsd.pkg.mk"
