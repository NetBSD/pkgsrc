# $NetBSD: Makefile,v 1.15 2026/07/16 19:06:21 wiz Exp $

DISTNAME=	WWW-Mechanize-FormFiller-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WWW-Mechanize-FormFiller
COMMENT=	Framework to automate HTML forms
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Random>=0.05:../../devel/p5-Data-Random
DEPENDS+=	p5-HTML-Form-[0-9]*:../../www/p5-HTML-Form

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/WWW/Mechanize/FormFiller/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
