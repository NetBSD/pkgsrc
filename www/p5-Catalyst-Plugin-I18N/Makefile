# $NetBSD: Makefile,v 1.6 2010/09/04 11:59:45 sno Exp $

DISTNAME=	Catalyst-Plugin-I18N-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::I18N
COMMENT=	I18N for Catalyst
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	{perl>=5.10.0,p5-I18N-LangTags>=0.35}:../../misc/p5-I18N-LangTags
DEPENDS+=	p5-Locale-Maketext-Lexicon>=0:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=	{perl>=5.10.0,p5-Locale-Maketext-Simple-[0-9]*}:../../misc/p5-Locale-Maketext-Simple
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/I18N/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
