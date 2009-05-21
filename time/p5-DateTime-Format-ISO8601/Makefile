# $NetBSD: Makefile,v 1.5 2009/05/21 14:17:27 sno Exp $

DISTNAME=	DateTime-Format-ISO8601-0.06
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jhoblitt/DateTime-Format-ISO8601/
COMMENT=	Parses ISO8601 formats
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DateTime>=0.18:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.77:../../time/p5-DateTime-Format-Builder

# Recommended dependencies:
BUILD_DEPENDS+=	p5-File-Find-Rule>=0.24:../../devel/p5-File-Find-Rule
BUILD_DEPENDS+=	p5-Test-Distribution>=1.22:../../devel/p5-Test-Distribution
BUILD_DEPENDS+=	p5-Test-Pod>=0.95:../../devel/p5-Test-Pod

PERL5_MODULE_TYPE=   Module::Build

PERL5_PACKLIST=		auto/DateTime/Format/ISO8601/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
