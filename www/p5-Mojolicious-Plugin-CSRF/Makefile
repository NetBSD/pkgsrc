# $NetBSD: Makefile,v 1.2 2026/07/16 19:06:11 wiz Exp $

DISTNAME=	Mojolicious-Plugin-CSRF-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mojolicious/}

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
