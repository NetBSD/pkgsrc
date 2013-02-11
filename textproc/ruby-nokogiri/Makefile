# $NetBSD: Makefile,v 1.14 2013/02/11 02:44:26 taca Exp $

DISTNAME=	nokogiri-1.5.6
CATEGORIES=	textproc

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://nokogiri.org/
COMMENT=	HTML, XML, SAX, and Reader parser with XPath and CSS selector support
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-nokogiri-[0-9]*

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
