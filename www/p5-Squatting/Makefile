# $NetBSD: Makefile,v 1.3 2011/08/14 16:06:07 obache Exp $

DISTNAME=	Squatting-0.70
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BE/BEPPU/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Squatting/
COMMENT=	Camping-inspired Web microframework for Perl 5
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Squatting/.packlist

DEPENDS+=	p5-Class-C3-Componentised-[0-9]*:../../devel/p5-Class-C3-Componentised
DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=	p5-Continuity>=0.991:../../www/p5-Continuity
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-IO-All-[0-9]*:../../devel/p5-IO-All
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=	p5-Shell-Perl-[0-9]*:../../devel/p5-Shell-Perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
