# $NetBSD: Makefile,v 1.10 2022/06/28 11:37:47 wiz Exp $

DISTNAME=	WWW-Mechanize-FormFiller-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
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
