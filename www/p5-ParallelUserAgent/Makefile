# $NetBSD: Makefile,v 1.7 2014/05/29 23:38:12 wiz Exp $
#

DISTNAME=	ParallelUserAgent-2.57
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}
MASTER_SITES=  	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MARCLANG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ParallelUserAgent/
COMMENT=	CPAN Bundle for the LWP Parallel User Agent extension

DEPENDS+=     p5-libwww>=5.64:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/Parallel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
