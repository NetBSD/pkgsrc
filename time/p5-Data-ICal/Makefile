# $NetBSD: Makefile,v 1.15 2013/12/09 14:17:54 obache Exp $

DISTNAME=		Data-ICal-0.21
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Data-ICal
COMMENT=		Generates iCalendar (RFC 2445) calendar files
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Class-Accessor>=0.30:../../devel/p5-Class-Accessor
DEPENDS+=		p5-Class-ReturnValue>=0.53:../../devel/p5-Class-ReturnValue
DEPENDS+=		{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Text-vFile-asData>=0.05:../../textproc/p5-Text-vFile-asData

BUILD_DEPENDS+=		{perl>=5.6.2,p5-Test-Simple-[0-9]*}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=		p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
BUILD_DEPENDS+=		p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+=		p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Data/ICal/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
