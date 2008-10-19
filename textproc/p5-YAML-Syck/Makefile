# $NetBSD: Makefile,v 1.6 2008/10/19 19:19:00 he Exp $

DISTNAME=	YAML-Syck-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AU/AUDREYT/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~audreyt/YAML-Syck/
COMMENT=	Fast, lightweight YAML loader and dumper

USE_LANGUAGES=	c
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/YAML/Syck/.packlist

BUILD_DEPENDS+= p5-Module-Install-[0-9]*:../../devel/p5-Module-Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
