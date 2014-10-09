# $NetBSD: Makefile,v 1.26 2014/10/09 13:45:02 wiz Exp $

DISTNAME=	Time-Piece-1.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Piece/
COMMENT=	Time::Piece - Object Oriented time objects
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Time/Piece/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
