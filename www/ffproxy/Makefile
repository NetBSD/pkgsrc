# $NetBSD: Makefile,v 1.5 2012/10/28 06:30:15 asau Exp $

DISTNAME=	ffproxy-1.6
CATEGORIES=	www
MASTER_SITES=	http://faith.eu.org/ffproxy/
PKGREVISION=	1

MAINTAINER=	niklas@noxa.de
HOMEPAGE=	http://faith.eu.org/programs.html\#ffproxy
COMMENT=	Filtering HTTP/HTTPS proxy server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

CONF_FILES=	${PREFIX}/share/ffproxy/sample.config ${PKG_SYSCONFDIR}/ffproxy.conf
.include "../../mk/bsd.pkg.mk"
