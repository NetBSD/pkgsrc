# $NetBSD: Makefile,v 1.18 2016/09/08 15:19:19 joerg Exp $

DISTNAME=	diff-lcs-1.2.5
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diff-lcs.rubyforge.org/
COMMENT=	Diff library for Ruby
LICENSE=	gnu-gpl-v2 OR artistic OR ruby-license

RUBYGEM_OPTIONS+=	--format-executable

RUBY_VERSIONS_ACCEPTED= 18 21 22 23

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
