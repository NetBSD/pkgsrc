# $NetBSD: Makefile,v 1.3 2011/08/14 16:06:07 obache Exp $

DISTNAME=	Squatting-On-PSGI-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BE/BEPPU/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Squatting-On-PSGI/
COMMENT=	Perl 5 module to run Squatting applications on PSGI
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Squatting/On/PSGI/.packlist

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Squatting-[0-9]*:../../www/p5-Squatting

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
