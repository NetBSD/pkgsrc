# $NetBSD: Makefile,v 1.2 2010/09/10 08:29:06 taca Exp $

DISTNAME=	nokogiri-1.4.3.1
CATEGORIES=	textproc

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://nokogiri.org
COMMENT=	HTML, XML, SAX, and Reader parser with XPath and CSS selector support
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-nokogiri-*

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
