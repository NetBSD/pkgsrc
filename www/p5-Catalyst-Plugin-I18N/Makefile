# $NetBSD: Makefile,v 1.24 2022/06/28 11:37:16 wiz Exp $

DISTNAME=	Catalyst-Plugin-I18N-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Catalyst::Plugin::I18N
COMMENT=	I18N for Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime-[0-9]*:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Locale-Maketext-Lexicon-[0-9]*:../../misc/p5-Locale-Maketext-Lexicon
#DEPENDS+=	{perl>=5.12.0,p5-Locale-Maketext-Simple>=0.19}:../../misc/p5-Locale-Maketext-Simple
DEPENDS+=	p5-MRO-Compat>=0.10:../../devel/p5-MRO-Compat

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/I18N/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
