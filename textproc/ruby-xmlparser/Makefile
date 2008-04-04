# $NetBSD: Makefile,v 1.11 2008/04/04 15:22:24 jlam Exp $

DISTNAME=	xmlparser-0.6.81
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www.yoshidam.net/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.yoshidam.net/Ruby.html#xmlparser
COMMENT=	Ruby bindings to the Expat XML parsing library

DEPENDS+=	${RUBY_PKGPREFIX}-mkrf>=0.2.1:../../devel/ruby-mkrf

.include "../../misc/rubygems/rubygem.mk"

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
