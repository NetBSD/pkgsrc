# $NetBSD: Makefile,v 1.14 2021/02/14 15:06:43 taca Exp $

DISTNAME=	ferret-0.11.8.7
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/jkraemer/ferret/
COMMENT=	Text search engine library written for Ruby
LICENSE=	mit

USE_GCC_RUNTIME=	yes
RUBYGEM_OPTIONS+=	--format-executable

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || !empty(CC_VERSION:Mgcc-[6-9]*)
BUILDLINK_TRANSFORM.SunOS+=	opt:-D_XOPEN_SOURCE=500:-D_XOPEN_SOURCE=600
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
