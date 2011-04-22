# $NetBSD: Makefile,v 1.5 2011/04/22 13:44:52 obache Exp $

DISTNAME=	nokogiri-1.4.4
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://nokogiri.org/
COMMENT=	HTML, XML, SAX, and Reader parser with XPath and CSS selector support
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-nokogiri-*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
