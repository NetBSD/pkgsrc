# $NetBSD: Makefile,v 1.2 2007/04/25 09:39:13 hiramatsu Exp $

DISTNAME=	YAML-Syck-0.85
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AU/AUDREYT/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~audreyt/YAML-Syck-0.72/
COMMENT=	Fast, lightweight YAML loader and dumper 

USE_LANGUAGES=	c
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/YAML/Syck/.packlist

BUILD_DEPENDS+= p5-Module-Install-[0-9]*:../../devel/p5-Module-Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
