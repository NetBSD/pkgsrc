# $NetBSD: Makefile,v 1.7 2009/04/30 21:00:18 sno Exp $

DISTNAME=	YAML-Syck-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=YAML/}
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AU/AUDREYT/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~audreyt/YAML-Syck/
COMMENT=	Fast, lightweight YAML loader and dumper
#LICENSE=	mit AND bsd

USE_LANGUAGES=	c
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/YAML/Syck/.packlist

BUILD_DEPENDS+= p5-Module-Install-[0-9]*:../../devel/p5-Module-Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
