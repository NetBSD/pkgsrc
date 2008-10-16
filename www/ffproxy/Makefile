# $NetBSD: Makefile,v 1.3 2008/10/16 20:28:06 bouyer Exp $

DISTNAME=	ffproxy-1.6
CATEGORIES=	www
MASTER_SITES=	http://faith.eu.org/ffproxy/
PKGREVISION=	1

MAINTAINER=	niklas@noxa.de
HOMEPAGE=	http://faith.eu.org/programs.html\#ffproxy
COMMENT=	Filtering HTTP/HTTPS proxy server

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONF_FILES=	${PREFIX}/share/ffproxy/sample.config ${PKG_SYSCONFDIR}/ffproxy.conf
.include "../../mk/bsd.pkg.mk"
