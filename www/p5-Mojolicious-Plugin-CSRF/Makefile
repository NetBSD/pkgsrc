# $NetBSD: Makefile,v 1.3 2026/10/18 01:33:32 wen Exp $

DISTNAME=	Mojolicious-Plugin-CSRF-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GR/GRYPHON/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://mojolicio.us/
COMMENT=	Mojolicious plugin for Cross Site Request Forgery (CSRF)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mojolicious-[0-9]*:../../www/p5-Mojolicious

TEST_DEPENDS+=	p5-Test2-MojoX-[0-9]*:../../www/p5-Test2-MojoX

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Mojolicious/Plugin/CSRF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
