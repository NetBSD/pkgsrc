# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:55 joerg Exp $

DISTNAME=	ffproxy-1.6
CATEGORIES=	www
MASTER_SITES=	http://faith.eu.org/ffproxy/

MAINTAINER=	niklas@noxa.de
HOMEPAGE=	http://faith.eu.org/programs.html\#ffproxy
COMMENT=	Filtering HTTP/HTTPS proxy server

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONF_FILES=	${PREFIX}/share/ffproxy/sample.config ${PKG_SYSCONFDIR}/ffproxy.conf
.include "../../mk/bsd.pkg.mk"
