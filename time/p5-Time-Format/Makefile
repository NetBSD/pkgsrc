# $NetBSD: Makefile,v 1.3 2008/09/10 19:11:56 he Exp $
#

DISTNAME=	Time-Format-1.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Format/
COMMENT=	Easy-to-use date/time formatting

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-Simple>=0.40:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Time/Format/.packlist
USE_LANGUAGES=	# none

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
