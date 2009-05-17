# $NetBSD: Makefile,v 1.6 2009/05/17 19:26:00 sno Exp $

DISTNAME=	Catalyst-Plugin-Session-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session/
COMMENT=	Generic Catalyst Session plugin
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Catalyst-Runtime>=5.71001:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Digest>=0:../../security/p5-Digest
DEPENDS+=	p5-File-Temp>=0:../../devel/p5-File-Temp
DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Moose>=0.76:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Emulate-Class-Accessor-Fast>=0.00801:../../devel/p5-MooseX-Emulate-Class-Accessor-Fast
DEPENDS+=	p5-Object-Signature>=0:../../devel/p5-Object-Signature
DEPENDS+=	p5-PathTools>=0:../../devel/p5-PathTools
DEPENDS+=	p5-Tie-RefHash>=1.34:../../devel/p5-Tie-RefHash
DEPENDS+=	p5-namespace-clean>=0.10:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-MockObject>=1.01:../../devel/p5-Test-MockObject
# p5-Test-WWW-Mechanize-Catalyst has BUILD_DEPENDS on p5-Catalyst-Plugin-Session
# BUILD_DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst>=0:../../www/p5-Test-WWW-Mechanize-Catalyst

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/Session/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
