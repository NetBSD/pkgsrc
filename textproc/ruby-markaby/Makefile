# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:22:02 jlam Exp $

DISTNAME=	markaby-0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.whytheluckystiff.net/markaby/
COMMENT=	HTML Markup as Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
