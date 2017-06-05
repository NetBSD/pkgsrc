# $NetBSD: Makefile,v 1.32 2017/06/05 14:25:06 ryoon Exp $

DISTNAME=	Time-Piece-1.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Piece/
COMMENT=	Time::Piece - Object Oriented time objects
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Time/Piece/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
