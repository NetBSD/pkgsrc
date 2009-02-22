# $NetBSD: Makefile,v 1.3 2009/02/22 17:27:46 he Exp $

DISTNAME=	Catalyst-Plugin-Session-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session/
COMMENT=	Generic Catalyst Session plugin

DEPENDS+=	p5-Catalyst-Runtime>=5.7010:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Digest>=0:../../security/p5-Digest
DEPENDS+=	p5-File-Temp>=0:../../devel/p5-File-Temp
DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Object-Signature>=0:../../devel/p5-Object-Signature
DEPENDS+=	p5-PathTools>=0:../../devel/p5-PathTools
DEPENDS+=	p5-Tie-RefHash>=1.34:../../devel/p5-Tie-RefHash
BUILD_DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-MockObject>=1.01:../../devel/p5-Test-MockObject
BUILD_DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst>=0:../../www/p5-Test-WWW-Mechanize-Catalyst

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/Session/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
