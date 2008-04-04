# $NetBSD: Makefile,v 1.3 2008/04/04 15:22:09 jlam Exp $

DISTNAME=	maruku-0.5.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://maruku.rubyforge.org/
COMMENT=	Markdown-superset interpreter

DEPENDS+=	${RUBY_PKGPREFIX}-syntax>=1.0.0:../../textproc/ruby-syntax

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
