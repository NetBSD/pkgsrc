# $NetBSD: Makefile,v 1.7 2012/10/03 21:58:22 wiz Exp $

DISTNAME=      	Time-Duration-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~avif/Time-Duration-1.04/Duration.pm
COMMENT=	Perl5 module for rounded or exact English expression of durations

BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Time/Duration/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
