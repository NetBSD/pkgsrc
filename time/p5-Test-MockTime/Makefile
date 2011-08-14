# $NetBSD: Makefile,v 1.3 2011/08/14 15:28:48 obache Exp $

DISTNAME=	Test-MockTime-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Test::MockTime
COMMENT=	Replaces actual time with simulated time
LICENSE=	gnu-gpl-v2 # OR artistic

USE_LANGUAGES=	c # installs C module
PERL5_PACKLIST=	auto/Test/MockTime/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
