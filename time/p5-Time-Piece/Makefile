# $NetBSD: Makefile,v 1.38 2019/06/30 20:17:18 nia Exp $

DISTNAME=	Time-Piece-1.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Time-Piece
COMMENT=	Time::Piece - Object Oriented time objects
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Time/Piece/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
