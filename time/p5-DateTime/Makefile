# $NetBSD: Makefile,v 1.18 2009/11/11 09:12:56 seb Exp $

DISTNAME=	DateTime-0.51
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Perl module for date/time sets and ranges
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-DateTime-Locale>=0.41:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=0.59:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Params-Validate>=0.76:../../devel/p5-Params-Validate

USE_LANGUAGES=	c # installs C module
PERL5_PACKLIST=	auto/DateTime/.packlist
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
