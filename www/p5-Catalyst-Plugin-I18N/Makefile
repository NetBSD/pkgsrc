# $NetBSD: Makefile,v 1.1.1.1 2008/10/12 17:28:55 abs Exp $

DISTNAME=	Catalyst-Plugin-I18N-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::I18N
COMMENT=	I18N for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Locale-Maketext-Simple>=0:../../misc/p5-Locale-Maketext-Simple
DEPENDS+=	p5-I18N-LangTags>=0:../../misc/p5-I18N-LangTags
DEPENDS+=	p5-Locale-Maketext-Lexicon>=0:../../misc/p5-Locale-Maketext-Lexicon

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/I18N/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
