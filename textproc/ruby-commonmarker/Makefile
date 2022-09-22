# $NetBSD: Makefile,v 1.2 2022/09/22 13:46:06 taca Exp $

DISTNAME=	commonmarker-0.23.6
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gjtorikian/commonmarker
COMMENT=	CommonMark parser and renderer written in C, wrapped in Ruby
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

.include "../../textproc/cmark/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
