# $NetBSD: Makefile,v 1.3 2026/01/07 08:49:08 wiz Exp $

DISTNAME=	commonmarker-2.3.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/commonmarker/&23/}
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gjtorikian/commonmarker
COMMENT=	CommonMark parser and renderer written in C, wrapped in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rb_sys>=0.9<1:../../devel/ruby-rb_sys

USE_TOOLS+=	gmake

RUBYGEM_OPTIONS+=	--format-executable

.include "cargo-depends.mk"

# XXX: including "lang/ruby/gem.mk" after "lang/rust/cargo.mk" cause
# ignoring gem-extract target...
#
.include "../../lang/ruby/gem.mk"
.include "../../lang/rust/cargo.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
