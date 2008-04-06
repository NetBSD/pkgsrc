# $NetBSD: Makefile,v 1.12 2008/04/06 07:49:55 taca Exp $

DISTNAME=	xmlparser-0.6.81
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.yoshidam.net/Ruby.html#xmlparser
COMMENT=	Ruby bindings to the Expat XML parsing library

DEPENDS+=	${RUBY_PKGPREFIX}-mkrf>=0.2.1:../../devel/ruby-mkrf

.include "../../misc/rubygems/rubygem.mk"

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
