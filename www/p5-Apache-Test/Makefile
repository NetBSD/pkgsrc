# $NetBSD: Makefile,v 1.12 2008/04/23 21:25:59 wiz Exp $
#

DISTNAME=		Apache-Test-1.30
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5apt
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		adam@migus.org
HOMEPAGE=		http://search.cpan.org/dist/Apache-Test/
COMMENT=		Wrapper for Test.pm to test an Apache server

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		ap2-perl-[0-9]*

USE_LANGUAGES=		# none
PERL5_PACKLIST=		auto/Apache/Test/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
